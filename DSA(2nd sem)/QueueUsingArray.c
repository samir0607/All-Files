 #include<stdio.h>
 #include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("Queue overflow");
    }
    else{
        q->r = q->r+1;
        q->arr[q->r] = val;
    }
}
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue underflow");
        return -1;
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}
int main(){
    struct queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size*sizeof(int));
    enqueue(&q, 12);
    enqueue(&q, 13);
    enqueue(&q, 17);
    printf("Dequeue element %d", dequeue(&q));
    if(isEmpty(&q)){
        printf("Queue is empty");
    }
    if(isFull(&q)){
        printf("Queue is full");
    }
    return 0;
}