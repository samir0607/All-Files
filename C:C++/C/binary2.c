#include <stdio.h>
int binaryfirst(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}
int binarylast(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}
int main(){
    int arr[]={1,2,2,3,3,3,4,5,6,8,8,8,8,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 3;
    int result = binarySearch(arr, 0, n - 1, target);
    if(result!=-1) 
    printf("3 starts from %d",result);
    
}
