#include<stdio.h>
int main(){
    int i,j,n,a;
    printf("Enter number of lines: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<i;j++)
        {
          a=a+1;
          printf("%d ",a);
        }
        printf("\n");
    }
    return 0;
}