#include<stdio.h>
struct student{
        char name[20];
        int stid;
        float grade;
    }st[2];
int main()
{
    int i;
    for(i=0;i<2;i++)
    {
        printf("Enter Name, student ID and grade points: ");
        scanf("%s %d %f",&st[i].name,&st[i].stid,&st[i].grade);
    }
    printf("Name \t\t Student ID \t\t GPA\n");
    for(i=0;i<2;i++){
        printf("%s \t\t %d \t\t %f\n",st[i].name,st[i].stid,st[i].grade);
    }
    return 0;
}