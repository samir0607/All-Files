#include<stdio.h>
int main(){
    char filename[100];
    printf("Enter the file name: ");
    scanf("%s", &filename);
    FILE *fptr = fopen(filename, "r");
    if(fptr == NULL){
        printf("File does not exist");
        return -1;
    }
    fseek(fptr, 0, SEEK_END);
    long filesize = ftell(fptr);
    if(filesize == -1){
        printf("Unable to determine the file size");
    }
    else{
        printf("File size is %ld bytes", filesize);
    }
    fclose(fptr);
    return 0;
}

