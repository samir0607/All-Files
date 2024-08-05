#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * next;
};
void traversal(struct Node * ptr){
    printf("Elements are: \n");
    while(ptr!=NULL){
        printf("%d\n", ptr->data);
        ptr=ptr->next;
    }
}
struct Node * insertAtFirst(struct Node*head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct Node * insertAtIndex(struct Node*head, int data, int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p= head;
    int i = 0;

    while(i!=index-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node * insertAtEnd(struct Node * head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct Node * insertAfterNode(struct Node * head, struct Node * prevNode, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
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
    head = insertAtFirst(head, 56);
    head = insertAtIndex(head, 42, 1);
    head = insertAtEnd(head, 99);
    head = insertAfterNode(head, second, 80);
    traversal(head);
    return 0;
}