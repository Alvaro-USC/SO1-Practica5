#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>  // para getpid()

int global_var = 2;  // Variable global

void* hilo_func(void* arg) {
    int param = *(int*)arg;
    int local_hilo = global_var * param;
    int *p = malloc(50 * sizeof(int));

    printf("Hilo %lu: PID=%d, global=%p, param=%p, local=%p, malloc=%p\n",
           pthread_self(), getpid(), (void*)&global_var, arg, (void*)&local_hilo, (void*)p);

    getchar();  // Para mantener el hilo activo y poder inspeccionar el mapa
    free(p);
    return NULL;
}

int main() {
    pid_t pid = getpid();
    int local_main = 5;
    pthread_t hilo1, hilo2;

    pthread_create(&hilo1, NULL, hilo_func, &local_main);
    pthread_create(&hilo2, NULL, hilo_func, &local_main);

    int *p = malloc(100 * sizeof(int));
    printf("Main: PID=%d, global=%p, local=%p, malloc=%p\n",
           pid, (void*)&global_var, (void*)&local_main, (void*)p);

    getchar();  // Para mantener el proceso activo
    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);
    free(p);

    return 0;
}
