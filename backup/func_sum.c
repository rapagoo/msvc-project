#include <stdio.h>

int sum(int n){
    int result=0;
    for (size_t i = 1; i <= n; i++)
    {
       result = result + i;
    }
    return result;
    
}
int input;

int main(int argc, char const *argv[])
{
    int input=0;
    printf("입력 : ");
    scanf("%d", &input);
    int result=sum(input);
    printf("%d",result);
    return 0;
}
