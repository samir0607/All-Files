#include<stdio.h>
int main(){
    int a[10],key,flag=1,i;
    for(i=0;i<10;i++){
        printf("Enter a number: ");
        scanf("%d",&a[i]);
    }
    printf("Enter key: ");
    scanf("%d",&key);
    for(i=0;i<10;i++){
        if(a[i]==key){
            flag=1;
            break;
        }
        else
        flag=0;
    }
    if(flag==1)
    printf("Element found");
    else
    printf("Element not found");
    return 0;

}