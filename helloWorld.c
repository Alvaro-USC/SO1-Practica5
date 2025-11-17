#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int n = 100;
	int* p1 = (int*)malloc(sizeof(int));
	*p1 = 1;
	if (!p1) return 1;
	printf("Hello World: %d %p %d\n", n, p1, *p1);

	return 0;
}