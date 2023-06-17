#include <stdio.h>

// Function to find the maximum and minimum numbers in an array
void findMaxMin(int arr[], int low, int high, int *max, int *min)
{
    int mid, max1, max2, min1, min2;

    // If the array has only one element
    if (low == high) {
        *max = arr[low];
        *min = arr[low];
    }
    // If the array has two elements
    else if (high == low + 1) {
        if (arr[low] > arr[high]) {
            *max = arr[low];
            *min = arr[high];
        } else {
            *max = arr[high];
            *min = arr[low];
        }
    }
    // If the array has more than two elements
    else {
        mid = (low + high) / 2;
        findMaxMin(arr, low, mid, &max1, &min1);
        findMaxMin(arr, mid + 1, high, &max2, &min2);

        if (max1 > max2)
            *max = max1;
        else
            *max = max2;

        if (min1 < min2)
            *min = min1;
        else
            *min = min2;
    }
}
int main() {
    int n, i;
    int *arr, min, max;
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    arr = (int*) malloc(n * sizeof(int));
    
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    findMaxMin(arr, 0, n - 1, &max, &min);

    printf("Maximum number: %d\n", max);
    printf("Minimum number: %d\n", min);

    free(arr);
    
    return 0;
}
