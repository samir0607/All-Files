#include <stdio.h>
struct employee{
    char name[20];
    int age;
    float salary;
}emp;
int main()
{
   FILE *fptr;
   fptr = fopen ("emp.txt", "w"); /*open for writing*/

   if (fptr == NULL)
   {
      printf("File does not exists\n");
      return 1;
   }

  printf("Enter the name\n");
  fgets(emp.name, sizeof(emp.name), stdin);


  printf("Enter the age\n");
  scanf("%d", &emp.age);

 printf("Enter the salary\n");
 scanf("%f", &emp.salary);
 fprintf(fptr, "Name: %s\t Age: %d\t Salary: %.2f\n", emp.name, emp.age, emp.salary);

   fclose(fptr);
    return 0;
}
