#include<stdio.h>
struct student
{
    int roll;
    float marks;
};
int main()
{
    struct student s;
    s.roll=101;
    s.marks=88.5;
    printf("roll number=%d\n",s.roll);
    printf("marks=%.2f\n",s.marks);
    return 0;
}