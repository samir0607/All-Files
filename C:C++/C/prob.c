#include<stdio.h>
int main(){
    int x[]={1,2,3,4,5,6,7};
    int i,j;
    i=4;
    j=3;
    x[i]=i++;
    x[--j]=--i+4;
    for(int k=0;k<7;k++){
        printf("%d ",x[k]);
    }
    return 0;
}
//output is 11