#include <stdio.h>
#include <math.h>
#include <unistd.h>

int main() {
    double x = sin(3.14/4);
    printf("sin(π/4) = %f\n", x);
    printf("PID=%d\n", getpid());
    getchar();
    return 0;
}
