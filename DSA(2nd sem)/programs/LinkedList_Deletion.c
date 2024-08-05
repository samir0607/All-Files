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
struct Node * deleteFirst(struct Node * head){
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head; 
}
struct Node * deleteIndex(struct Node * head, int index){
    struct Node * p = head;
    struct Node * ptr = head->next;
    int i = 0;
    while(i!=index-1){
        p = p->next;
        ptr = ptr->next;
        i++;
    }
    p->next = ptr->next;
    free(ptr);
    return head; 
}
struct Node * deleteLast(struct Node * head){
    struct Node * p = head;
    struct Node *ptr = head->next;
    while(ptr->next!=NULL){
        p = p->next;
        ptr = ptr->next;
    }
    p->next = NULL;
    free(ptr);
    return head; 
}
struct Node * deleteValue(struct Node * head, int value){
    struct Node * p = head;
    struct Node * ptr = head->next;
    while(ptr->data != value && ptr->next != NULL){
        p = p->next;
        ptr = ptr->next;
    }
    if(ptr->data==value){
        p->next = ptr->next;
        free(ptr);
    }
    return head; 
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