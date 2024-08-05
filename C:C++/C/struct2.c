#include<stdio.h>
struct employee{
        int code;
        char name[20];
        char dept[20];
        double salary;
    }em[5];
int main()
{
    int i;
    for(i=0;i<5;i++)
    {
        printf("Enter Name, employee code, department and salary: ");
        scanf("%s %d %s %lf",&em[i].name,&em[i].code,&em[i].dept,&em[i].salary);
    }
    printf("Name \t\t Employee Code \t\t Department \t\t Salary\n");
    for(i=0;i<5;i++){
        printf("%s \t\t %d \t\t\t %s\t\t\t %lf\n",em[i].name,em[i].code,em[i].dept,em[i].salary);
    }
    return 0;
}
