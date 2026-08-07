#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(int argc, char const *argv[])
{
    int a=1, b=2;
    swap(&a, &b);
    printf("a: %d, b: %d", a, b);
    return 0;
}
