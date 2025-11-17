#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int main() {
    pid_t pid = fork();
    if (pid == 0) {
        int *p = malloc(100 * sizeof(int));
        printf("Hijo malloc: %p\n", (void*)p);
        char *args[] = {"./helloWorld", NULL};
        printf("Presiona Enter para cambiar la imagen con execv...\n");
        getchar();
        execv(args[0], args);
        perror("execv"); // Solo si falla
        exit(1);
    } else {
        printf("Padre PID: %d\n", getpid());
        wait(NULL);
        getchar();
    }
    return 0;
}
