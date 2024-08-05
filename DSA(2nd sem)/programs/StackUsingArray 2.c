#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack* ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct stack* ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
int peek(struct stack *sp, int i){
    int arrayInd = sp->top -i+1;
    if(arrayInd<0){
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else{
        return sp->arr[arrayInd];
    }
}   
void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow. Cannot push %d to the stack\n",val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack* ptr){
     if(isEmpty(ptr)){
        printf("Stack underflow. Cannot pop to the stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int main(){
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 80;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size*sizeof(int));
    printf("Before pushing, Full: %d\n", isFull(sp));
    printf("Before pushing, Empty: %d\n", isEmpty(sp));
    push(sp,2);
    push(sp,58);
    push(sp,6);
    push(sp,7);
    push(sp,56);
    push(sp,24);
    push(sp,4);
    push(sp,62);
    push(sp,21);
    push(sp,92);
    push(sp,32);
    printf("After pushing, Full: %d\n", isFull(sp));
    printf("After pushing, Empty: %d\n", isEmpty(sp));
    printf("Popped %d from the stack\n", pop(sp));
    for(int j = 0; j<sp->top+1; j++){
        printf("The value at position %d is %d\n", j, peek(sp, j));
    }
    return 0;
}