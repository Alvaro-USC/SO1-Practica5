#include <stdio.h>
#include <unistd.h>

void f1(int x) {
    int local = 100;
    printf("f1: parámetro x=%p, local=%p\n", (void*)&x, (void*)&local);
}

void f2(int x) {
    int local = 200;
    printf("f2: parámetro x=%p, local=%p\n", (void*)&x, (void*)&local);
}

int main() {
    int val = 5;
    f1(val);
    f2(val);
    printf("main: %p\n", (void*)main);
    printf("f1: %p\n", (void*)f1);
    printf("f2: %p\n", (void*)f2);
    printf("PID: %d\n", getpid());
    getchar();
    return 0;
}
