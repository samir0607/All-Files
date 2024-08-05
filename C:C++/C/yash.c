#include <stdio.h>

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 50};
    int n = sizeof(arr);
    int key;
    int found = 1;

    int lowest = arr[0];
    int highest = arr[n-1];

    printf("Enter the element to search: ");
    scanf("%d", &key);

    while(lowest <= highest)
    {
        int mid = lowest + (highest-lowest) / 2;

        if (arr[mid] == key)
        {
            found == 0;
            break;
        }
        else if(arr[mid] > key)
        {
            highest = mid - 1;
        }
        else if(arr[mid] < key)
        {
            lowest = mid + 1;
        }
    }

    if (found == 1)
    {
        printf("Not found");
    }
    else
    {
        printf("Found");
    }

    return 0;
}