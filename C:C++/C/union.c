#include<stdio.h>
#include<string.h>

union student{
    char name[10];
    int roll;
    float marks;
    char ph[10];
    char dept[5];
}std;

int main(){
    std.roll=21;
    printf("Roll no: %d\n",std.roll);
    std.marks=22.5;
    printf("Marks: %.1f\n",std.marks);
    strcpy(std.dept,"CSE");
    printf("Department: %s",std.dept);
    std.marks=23.5;
    printf("Marks: %.1f\n",std.marks);
    printf("Size of name member: %d\n",sizeof(std.name));
    printf("Size of roll member: %d\n",sizeof(std.roll));
    printf("Size of marks member: %d\n",sizeof(std.marks));
    printf("Size of phone member: %d\n",sizeof(std.ph));
    printf("Size of department member: %d\n",sizeof(std.dept));
    printf("Size of union: %u",sizeof(std));
    return  0;
}
