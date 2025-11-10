#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p1, *p2;

    printf("Antes de malloc: PID=%d\n", getpid());
    getchar();  // Pausa para observar mapa

    p1 = (int*)malloc(100 * sizeof(int));
    if (!p1) return 1;
    printf("Después de malloc 100 ints: p1=%p\n", (void*)p1);
    getchar();

    p2 = (int*)malloc(1000 * sizeof(int));
    if (!p2) return 1;
    printf("Después de malloc 1000 ints: p2=%p\n", (void*)p2);
    getchar();

    free(p1);
    free(p2);
    printf("Después de free\n");
    getchar();

    return 0;
}
