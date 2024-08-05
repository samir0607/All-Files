#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Structure to represent the queue
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the queue
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Function to enqueue an element into the queue
void enqueue(Queue* q, int val) {
    Node* newNode = createNode(val);
    if (isEmpty(q)) {
        q->front = newNode;
    } else {
        q->rear->next = newNode;
    }
    q->rear = newNode;
}

// Function to dequeue an element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return val;
}

// Function to reverse a linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to reverse the first k elements of the queue
void reverseFirstK(Queue* q, int k) {
    if (isEmpty(q) || k <= 0) {
        printf("Invalid operation!\n");
        return;
    }

    Node* current = q->front;
    Node* prev = NULL;
    Node* next = NULL;
    int count = 0;

    // Traverse to the kth node
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // Update pointers
    q->front->next = current;
    q->front = prev;

    // Update rear pointer if needed
    if (current == NULL) {
        q->rear = q->front;
    }
}

// Function to display the queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("Queue before reversing first 3 elements: ");
    displayQueue(&q);

    // Reverse the first 3 elements
    reverseFirstK(&q, 3);

    printf("Queue after reversing first 3 elements: ");
    displayQueue(&q);

    return 0;
}
