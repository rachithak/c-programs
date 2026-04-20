#include<stdio.h>
int main()
{
    float a,b,choice;
    char op;
    printf("enter two numbers a and b:");
    scanf("%f %f", &a, &b);
    printf("enter your choice(+,-.*,/):\n");
    scanf(" %c", &op);
    switch(op)
    {
    case '+':
    printf("addition of number is:%f",a+b);
    break;
    case '-':
    printf("subraction of number is:%f",a-b);
    break;
    case '*':
    printf("multipication of number is:%f",a*b);
    break;
    case '/':
    printf("division of number is:%f",a/b);
    break;
    default:
    printf("invalid choice");
    }
    return 0;
}