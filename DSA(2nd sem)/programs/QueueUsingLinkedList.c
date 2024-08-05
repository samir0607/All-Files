#include<stdio.h>
#include<stdlib.h>

struct node* f = NULL;
struct node* r = NULL;
struct node{
    int data;
    struct node * next;
};
void traversal(struct node *ptr){
    printf("Printing the elements of this linked list\n");
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}
void enqueue(int val){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    if(n==NULL){
        printf("Queue is Full");
    }
    else{
        n->data = val;
        n->next = NULL;
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next = n;
            r=n;
        }
    }
}
int dequeue(){
    int val = -1;
    struct node* ptr = f;
    if(f==NULL){
        printf("Queue is empty");
    }else{
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}
int main(){
    traversal(f);
    enqueue(34);
    enqueue(3);
    enqueue(4);
    traversal(f);
    printf("%d is dequeued", dequeue());
    return 0;
}