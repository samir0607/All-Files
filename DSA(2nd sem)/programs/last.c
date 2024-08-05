#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
    int height;
};

// Function to create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

// Function to count the number of leaf nodes in an AVL tree
int countLeafNodes(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    
    // If the node is a leaf node, return 1
    if (root->left == NULL && root->right == NULL)
        return 1;
    
    // Recursively count leaf nodes in the left and right subtrees
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    // Construct an AVL tree
    struct TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(12);
    root->right->right = createNode(20);
    
    // Count the number of leaf nodes
    int leafCount = countLeafNodes(root);
    printf("Number of leaf nodes in the AVL tree: %d\n", leafCount);
    
    return 0;
}
