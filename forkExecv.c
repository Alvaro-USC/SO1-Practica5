#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        int *p = malloc(100 * sizeof(int));
        printf("Hijo malloc: %p\n", (void*)p);
        char *args[] = {"./otro_programa", NULL};
        execv(args[0], args);
        perror("execv"); // Solo si falla
        exit(1);
    } else {
        printf("Padre PID: %d\n", getpid());
        getchar();
    }
    return 0;
}


//  COMPAÑERO PRÁCTICA 5: YAGO
