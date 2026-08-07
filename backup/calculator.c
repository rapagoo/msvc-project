#include <stdio.h>

int main(void)
{
    int a, b;
    char op;
    printf("Enter formula: ");
    scanf("%d %c %d", &a, &op, &b);


    switch(op)
    {
        case '+':
            printf("%d %c %d = %d\n", a, op, b, a + b);
            break;
        case '-':
            printf("%d %c %d = %d\n", a, op, b, a - b);
            break;
        case '*':
            printf("%d %c %d = %d\n", a, op, b, a * b);
            break;
        case '/':
            if (b == 0)
                printf("Error: Can't divide by 0\n");
            else
                printf("%d %c %d = %f\n", a, op, b, (float)a / (float)b);
            break;
        default:
            break;
    }

    if (op == '*')
        printf("%d %c %d = %d\n", a, op, b, a * b);
    else if (op == '+')
        printf("%d %c %d = %d\n", a, op, b, a + b);
    else if (op == '-')
        printf("%d %c %d = %d\n", a, op, b, a - b);
    else
    {
        if (b == 0)
            printf("Error: Can't divide by 0\n");
        else
            printf("%d %c %d = %d\n", a, op, b, a / b);
    }
}