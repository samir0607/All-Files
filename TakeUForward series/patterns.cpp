#include<stdio.h>
void pattern1(int count){
  for (int i = 0; i < count; i++)
  {
    for (int j = 0; j < count; j++)
    {
      printf("* ");
    }
    printf("\n");
  }
}
void pattern2(int count){
  for (int i = 0; i < count; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      printf("* ");
    }
    printf("\n");
  }
}
void pattern3(int count){
  for (int i = 0; i < count; i++)
  {
    for (int j = 1; j <= i+1; j++)
    {
      printf("%d",j);
    }
    printf("\n");
  }
}
void pattern4(int count){
  for (int i = 0; i < count; i++)
  {
    for (int j = 0; j < i+1; j++)
    {
      printf("%d",i+1);
    }
    printf("\n");
  }
}
void pattern5(int count){
  for (int i = 0; i < count; i++)
  {
    for (int j = 0; j < count-i; j++)
    {
      printf("*");
    }
    printf("\n");
  }
}
void pattern6(int count){
  for (int i = 0; i < count; i++)
  {
    for (int j = 0; j < count-i; j++)
    {
      printf("%d",j+1);
    }
    printf("\n");
  }
}
void pattern7(int count){
  for (int i = 1; i <= count; i++)
  {
    for (int j = 0; j < count-i; j++)
    {
      printf(" ");
    }
    for (int j = 0; j < 2*i-1; j++)
    {
      printf("*");
    }
    printf("\n");
  }
}
void pattern8(int count){
  for (int i = count; i >= 1; i--)
  {
    for (int j = 0; j < count-i; j++)
    {
      printf(" ");
    }
    for (int j = 0; j < 2*i-1; j++)
    {
      printf("*");
    }
    
    printf("\n");
  }
}
void pattern9(int count){
  for (int i = 1; i <= count; i++)
  {
    for (int j = 0; j < count-i; j++)
    {
      printf(" ");
    }
    for (int j = 0; j < 2*i-1; j++)
    {
      printf("*");
    }
    printf("\n");
  }
  for (int i = count; i >= 1; i--)
  {
    for (int j = 0; j < count-i; j++)
    {
      printf(" ");
    }
    for (int j = 0; j < 2*i-1; j++)
    {
      printf("*");
    }
    printf("\n");
  }
}
void pattern10(int count){
  for (int i = 0; i <= count; i++)
  {
    for (int j = 0; j < i; j++)
    {
      printf("* ");
    }
    printf("\n");
  }
  for (int i = 0; i <= count; i++)
  {
    for (int j = 0; j < count-i-1; j++)
    {
      printf("*");
    }
    printf("\n");
  }
}
void pattern11(int count){
  for (int i = 0; i <= count; i++)
  {
    int s = 1;
    (i%2==0)? s=0 : s=1;
    for (int j = 0; j < i; j++)
    {
      printf("%d",s);
      (s==0)? s=1 : s = 0;
    }
    printf("\n");
  }
}
void pattern12(int count){
  int num = 1;
  for (int i = 1; i <= count; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      printf("%d ",num);
      num++;
    }
    printf("\n");
  }
}

int main(){
  int n = 5;
  pattern12(n);
  return 0;
}