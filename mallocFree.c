#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <alloca.h>

int main() {
    int *p1, *p2;

    printf("PID: %d\n", getpid());
    printf("Prueba de Malloc (para poca memoria)\n");
    p1 = (int*)malloc(100 * sizeof(int));
    if (!p1) {
        perror("malloc p1 falló");
        return 1;
    }
    printf("Reservados 100 ints (pequeño) en: %p\n", (void*)p1);
    getchar();

    printf("Prueba de Malloc (grande)\n");
    p2 = (int*)malloc(100000 * sizeof(int)); // ~400KB
    if (!p2) {
        perror("malloc p2 falló");
        return 1;
    }
    printf("Reservados 100,000 ints (grande) en: %p\n", (void*)p2);
    getchar();

    printf("Prueba de Free\n");
    free(p1);
    free(p2);
    printf("Se hizo free(p1) y free(p2).\n");
    getchar();

    printf("\nalloca vs malloc\n");
    int *p_malloc = (int*)malloc(500 * sizeof(int));
    int *p_alloca = (int*)alloca(500 * sizeof(int));
    int local_var_stack;

    if (!p_malloc) {
        perror("malloc p_malloc falló");
        return 1;
    }

    printf("Dirección de malloc (Heap): \t%p\n", (void*)p_malloc);
    printf("Dirección de alloca (Stack): \t%p\n", (void*)p_alloca);
    printf("Dirección de local_var (Stack):\t%p\n", (void*)&local_var_stack);
    getchar();
    
    free(p_malloc);


    printf("\nrealloc\n");
    char *p_realloc = (char*)malloc(100);
    if (!p_realloc) return 1;
    printf("Dirección original de p_realloc (100 bytes):\t%p\n", (void*)p_realloc);

    // Creamos un bloqueador para que p_realloc no crezca contiguamente en la memoria 
    char *p_blocker = (char*)malloc(100);
    printf("Dirección del 'bloqueador' (100 bytes): \t%p\n", (void*)p_blocker);


    char *p_realloc_new = (char*)realloc(p_realloc, 50000);
    if (!p_realloc_new) {
        perror("realloc falló");
        return 1;
    }
    printf("Dirección tras realloc (50000 bytes):  \t%p\n", (void*)p_realloc_new);
    getchar();

    free(p_realloc_new);
    free(p_blocker);

    printf("\nsizeof(puntero)\n");
    double *p_double = (double*)malloc(1000 * sizeof(double));
    if (!p_double) return 1;
    
    printf("Reservados 1000 doubles (8000 bytes) en: %p\n", (void*)p_double);
    printf("Resultado de sizeof(p_double): %lu\n", sizeof(p_double));
    getchar();
    free(p_double);


    printf("free(ptr++)\n");
    int *p_bad_free = (int*)malloc(10 * sizeof(int));
    if (!p_bad_free) return 1;

    printf("Puntero original devuelto por malloc: %p\n", (void*)p_bad_free);
    
    p_bad_free++; // Incrementamos el puntero
    
    printf("Puntero incrementado (incorrecto):    %p\n", (void*)p_bad_free);
    printf("Intentando llamar a free() con el puntero incorrecto...\n");
    printf("Pulsa ENTER para ejecutar free(p_bad_free++)...\n");
    getchar();

    free(p_bad_free); // Comportamiento indefinido

    printf("la memoria está corrupta.\n");
    getchar();

    return 0;
}