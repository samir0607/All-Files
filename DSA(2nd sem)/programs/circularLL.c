#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
};
void traversal(struct Node * head){
    struct Node * ptr = head;
    do{
        printf("%d\n", ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}
 struct Node* insertAtFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head->next;
    while(p->next!=head){
        p = p->next;
    }
    //At this p point points to the last node of the cicular linked list
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
 }
int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;
    //Allocate memory for nodes in the linked list in heap
    head =(struct Node*)malloc(sizeof(struct Node));
    second =(struct Node*)malloc(sizeof(struct Node));
    third =(struct Node*)malloc(sizeof(struct Node));
    fourth =(struct Node*)malloc(sizeof(struct Node));

    //Link first and second
    head->data = 7;
    head->next = second;
    //Link second and third
    second->data = 17;
    second->next = third;
    //Link thhird and fouth
    third->data = 70;
    third->next = fourth;
    //Link last with head
    fourth->data = 79;
    fourth->next = head;

    printf("Circular Linked list before insertion:\n");
    traversal(head);
    head = insertAtFirst(head, 21);
    printf("Circular Linked list After insertion:\n");
    traversal(head);
    return 0;
}