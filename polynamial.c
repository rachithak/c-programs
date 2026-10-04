#include<stdio.h>
struct term
{
    int coef;
    int exp;
};
int main()
{
    struct term p[3]=
    {
        {5,4},
        {3,2},
        {2,0}
    };
    int i;
    for(i=0;i<3;i++)
    {
        printf("%dx^%d",p[i].coef,p[i].exp);
    }
    return 0;
}