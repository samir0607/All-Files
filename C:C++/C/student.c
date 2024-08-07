#include<stdio.h>
#include<string.h>

struct student{
  int roll;
  float marks;
  char name[20];
  char grade;
}std;

void inputStudentDetail(struct student std[], int n){
  for(int i=0; i<n; i++){
    printf("Enter Roll, Name, Marks: ");
    scanf("%d %s %f", &std[i].roll,&std[i].name,&std[i].marks);
  }
}

void displayStudentDetail(struct student std[], int n){
  printf("Roll\t Name\t Marks\t Grade\n ");
  for(int i=0; i<n; i++){
    printf("%d\t %s\t %.2f\t %c\n", std[i].roll,std[i].name,std[i].marks);
  }
}

int calculateGrade(int marks){
  if(marks>=90) return 'A';
  else if(marks>=80) return 'B';
  else if(marks>=70) return 'C';
  else if(marks>=60) return 'D';
  else return 'F';
}

int main(){
  int n = 10;
  struct student std[n];
  inputStudentDetail(std, n);
  for (int i = 0; i < n; i++) {
    std[i].grade = calculateGrade(std[i].marks);
  }
  displayStudentDetail(std, n);
  return 0;
}