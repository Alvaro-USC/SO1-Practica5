#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int global_var = 2;  // Variable global

void* hilo_func(void* arg) {
    int param = *(int*)arg;
    int local_hilo = global_var * param;
    int *p = malloc(50 * sizeof(int));
    printf("Hilo %lu: global=%p, param=%p, local=%p, malloc=%p\n",
           pthread_self(), (void*)&global_var, arg, (void*)&local_hilo, (void*)p);
    getchar();
    free(p);
    return NULL;
}

int main() {
    int local_main = 5;
    pthread_t hilo1, hilo2;

    pthread_create(&hilo1, NULL, hilo_func, &local_main);
    pthread_create(&hilo2, NULL, hilo_func, &local_main);

    int *p = malloc(100 * sizeof(int));
    printf("Main: global=%p, local=%p, malloc=%p\n",
           (void*)&global_var, (void*)&local_main, (void*)p);
    getchar();

    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);
    free(p);

    return 0;
}
