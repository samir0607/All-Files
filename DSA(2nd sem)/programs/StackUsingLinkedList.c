#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* top = NULL;
void traversal(struct node* ptr){
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}
int isEmpty(struct node* top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct node* top){
    struct node* p = (struct node*)malloc(sizeof(struct node));
    if(p==NULL){
        return 1;
    }
    else
    return 0;
}
struct node* push(struct node* top, int x){
    if(isFull(top)){
        printf("Stack overflow");
    }
    else{
        struct node* n = (struct node*)malloc(sizeof(struct node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}
struct node* pop(struct node* tp){
    if(isEmpty(tp)){
        printf("Stack underflow");
    }
    else{
        struct node* n = tp;
        top = tp->next;
        int x = n->data;
        free(n);
        return x;
    }
}
int peek(int pos){
    struct node* ptr = top;
    for(int i  = 0; i < pos-1 && ptr!=NULL; i++){
        ptr = ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;
    }
    else
    return -1;
}
int main(){
    top = push(top, 78);
    top = push(top, 54);
    top = push(top, 8);
    top = push(top, 7);
    traversal(top);
    int element = pop(top);
    printf("Popped element is %d\n",element);
    traversal(top);
    printf("Valuse at 3 is %d",peek(3));
    return 0;
}