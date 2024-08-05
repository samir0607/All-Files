#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Structure to represent the stack
typedef struct {
    int stack[MAX_SIZE];
    int min[MAX_SIZE]; // Stack to keep track of minimum elements
    int top;
} MinStack;

// Function to initialize the stack
MinStack* create() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->top = -1;
    return obj;
}

// Function to push element onto the stack
void push(MinStack* obj, int x) {
    obj->top++;
    obj->stack[obj->top] = x;
    obj->min[obj->top] = (obj->top == 0 || x <= obj->min[obj->top - 1]) ? x : obj->min[obj->top - 1];
}

// Function to pop element from the stack
void pop(MinStack* obj) {
    if (obj->top >= 0) {
        obj->top--;
    }
}

// Function to get the top element of the stack
int top(MinStack* obj) {
    if (obj->top >= 0) {
        return obj->stack[obj->top];
    }
    return -1;
}

// Function to get the minimum element of the stack
int getMin(MinStack* obj) {
    if (obj->top >= 0) {
        return obj->min[obj->top];
    }
    return -1;
}

// Function to free the memory allocated for the stack
void freeStack(MinStack* obj) {
    free(obj);
}

int main() {
    MinStack* obj = create();

    push(obj, -2);
    push(obj, 0);
    push(obj, -3);
    printf("Minimum element in the stack: %d\n", getMin(obj)); // Output: -3

    pop(obj);
    printf("Top element of the stack: %d\n", top(obj)); // Output: 0
    printf("Minimum element in the stack: %d\n", getMin(obj)); // Output: -2

    freeStack(obj);

    return 0;
}
