#include <stdio.h>
int x = 0;

int main(int a, int b)
{
    int c = 100;
    char d = 'a';
    char e[] = "abcde";
    float f = 1.0;
    double g = 1.0;
    printf("Hello World!\n");

    printf("result: %d", y(2));

    return 0;
}

int y(int x)
{
    return x * 2;
}