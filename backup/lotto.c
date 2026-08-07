#include <stdio.h>

void input_nums(int *lotto);
void print_nums(int *lotto);

int main(int argc, char const *argv[])
{
    int lotto_nums[6];
    input_nums(lotto_nums);
    print_nums(lotto_nums);
    return 0;
}

void input_nums(int *lotto)
{
    int num;
    int a;
    for (int i = 0; i < 6; i++)
    {
        printf("input numbers: ");
        scanf("%d", &num);
        a = 0;
        for (int j = 0; j < i; j++)
        {
            if (num == lotto[j])
            {
                a = 1;
                break;
            }
        }
        if (!a)
        {
            lotto[i] = num;
        }
        else
        {
            printf("Same number already exists. \n");
            i--;
        }
    }
}

void print_nums(int *lotto)
{
    printf("Numbers: ");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", lotto[i]);
    }
}
