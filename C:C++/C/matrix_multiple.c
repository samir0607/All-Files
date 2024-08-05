#include<stdio.h>
int main(){
    int a[3][3],b[3][3],c[3][3];
        printf("Matrix A\n");
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                printf("Enter element a%d%d: ",i+1,j+1);
                scanf("%d",&a[i][j]);
        }
        }
        printf("Matrix B\n");
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                printf("Enter element b%d%d: ",i+1,j+1);
                scanf("%d",&b[i][j]);
        }
        }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            c[i][j]=0;
            for(int k=0;k<3;k++){
            c[i][j]+=a[i][j]*b[j][i];
            }
        }
    }
    printf("The required matrix is\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",c[i][j]);
        }
    }
    return 0;
}