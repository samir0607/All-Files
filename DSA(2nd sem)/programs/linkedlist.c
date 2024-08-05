#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
};
void traversal(struct Node * ptr){
    while(ptr!=NULL){
        printf("%d\t", ptr->data);
        ptr=ptr->next;
    }
}

int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    //Allocate memory for nodes in the linked list in heap
    head =(struct Node*)malloc(sizeof(struct Node));
    second =(struct Node*)malloc(sizeof(struct Node));
    third =(struct Node*)malloc(sizeof(struct Node));

    //Link first and second
    head->data = 7;
    head->next = second;
    //Link second and third
    second->data = 17;
    second->next = third;
    //Terminate at third
    third->data = 70;
    third->next = NULL;

    traversal(head);
    return 0;
}