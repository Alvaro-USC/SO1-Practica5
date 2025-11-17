#include <stdio.h>
#include <unistd.h>

int global_var = 10;          // Variable global
int global_array[5] = {1,2,3,4,5}; // Array global

int main() {
    int local_var = 20;               // Variable local
    int local_array[10][10][10];      // Array 3D local

    printf("Direcciones de variables y main:\n");
    printf("global_var: %p\n", (void*)&global_var);
    printf("global_array: %p\n", (void*)global_array);
    printf("local_var: %p\n", (void*)&local_var);
    printf("local_array: %p\n", (void*)local_array);
    printf("main: %p\n", (void*)main);

    // Comprobar orden de almacenamiento del array 3D
    for (int i = 0; i < 1; i++)
        for (int j = 0; j < 1; j++)
            for (int k = 0; k < 3; k++)
                printf("local_array[%d][%d][%d] en %p\n", i, j, k, (void*)&local_array[i][j][k]);

    printf("PID del proceso: %d\n", getpid());
    printf("Pulse Enter para continuar...\n");
    getchar();  // Para mantener el proceso y poder ver /proc/PID/maps
    return 0;
}
