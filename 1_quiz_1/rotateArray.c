#include <stdio.h>
//Question 2 on the Quiz one
// Function to rotate the array to the right by k steps. The K steps are defined in main
void rotateArray(int arr[], int size, int k) {
    int temp[size];  // Create a temporary array to hold the rotated values inside the array

    // Loop through each element in the original array
    for (int i = 0; i < size; i++) {
        // Calculate the new position using modulo to wrap around
        int newPos = (i + k) % size;
        temp[newPos] = arr[i];
    }

    // Copy the rotated values in temp back to the original array
    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to test some Examples
int main() {
    // First Test
    int nums1[] = {1, 2, 3, 4, 5, 6, 7};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int k1 = 3;
    printf("Before rotation: ");
    printArray(nums1, size1);
    rotateArray(nums1, size1, k1);
    printf("After rotating right by %d steps: ", k1);
    printArray(nums1, size1);

    // Second Test
    int nums2[] = {10, 20, 30, 40};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int k2 = 1;
    printf("\nBefore rotation: ");
    printArray(nums2, size2);
    rotateArray(nums2, size2, k2);
    printf("After rotating right by %d step: ", k2);
    printArray(nums2, size2);

    return 0;
}
