#include <stdio.h>
 
int main() {
    // Example arrays
    int nums1[] = {1, 2, 3, 4, 5};
    int m = sizeof(nums1) / sizeof(nums1[0]);
 
    int nums2[] = {2, 3, 5, 6};
    int n = sizeof(nums2) / sizeof(nums2[0]);
 
    // Initialize an array to store the union
    int unionArray[m + n];
 
    // Variables to keep track of unique elements in the union array
    int i = 0, j = 0, k = 0;
 
    // Loop through both arrays until one of them is exhausted
    while (i < m && j < n) {
        // If the element from nums1 is smaller, add it to the union array
        if (nums1[i] < nums2[j]) {
            unionArray[k++] = nums1[i++];
        }
        // If the element from nums2 is smaller, add it to the union array
        else if (nums1[i] > nums2[j]) {
            unionArray[k++] = nums2[j++];
        }
        // If both elements are equal, add either one to the union array
        else {
            unionArray[k++] = nums1[i++];
            j++;
        }
    }
 
    // Add the remaining elements from nums1, if any
    while (i < m) {
        unionArray[k++] = nums1[i++];
    }
 
    // Add the remaining elements from nums2, if any
    while (j < n) {
        unionArray[k++] = nums2[j++];
    }
 
    // Print the union array
    printf("Union of the arrays: ");
    for (int l = 0; l < k; l++) {
        printf("%d ", unionArray[l]);
    }
 
    return 0;
}