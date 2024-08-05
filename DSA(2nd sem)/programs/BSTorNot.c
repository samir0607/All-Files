#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Define the structure for a tree node
struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Structure for stack node
struct StackNode {
    struct TreeNode* node;
    struct StackNode* next;
};

// Function to create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to push a node onto the stack
void push(struct StackNode** top, struct TreeNode* node) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->node = node;
    stackNode->next = *top;
    *top = stackNode;
}

// Function to pop a node from the stack
struct TreeNode* pop(struct StackNode** top) {
    if (*top == NULL)
        return NULL;
    struct StackNode* temp = *top;
    struct TreeNode* popped = temp->node;
    *top = temp->next;
    free(temp);
    return popped;
}

// Function to check if the tree is a Binary Search Tree (BST)
bool isBST(struct TreeNode* root) {
    struct StackNode* stack = NULL;
    struct TreeNode* prev = NULL; // Previous node during in-order traversal
    
    while (root != NULL || stack != NULL) {
        // Reach the leftmost node of the current subtree
        while (root != NULL) {
            push(&stack, root);
            root = root->left;
        }
        
        // Pop the top node from the stack
        root = pop(&stack);
        
        // Check if the current node is less than or equal to the previous node
        if (prev != NULL && root->value <= prev->value)
            return false;
        
        // Update prev to the current node
        prev = root;
        
        // Move to the right subtree
        root = root->right;
    }
    
    return true;
}

int main() {
    // Construct a sample tree
    struct TreeNode* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(8);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->right->left = createNode(7);
    root->right->right = createNode(9);
    
    if (isBST(root))
        printf("The given tree is a Binary Search Tree.\n");
    else
        printf("The given tree is not a Binary Search Tree.\n");
    
    return 0;
}
