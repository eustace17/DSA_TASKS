#include <stdio.h>

// Function to find the number that appears only once
int findSingleNumber(int nums[], int size) {
    int result = 0;

    // Loop through the array
    for (int i = 0; i < size; i++) {
        result = result ^ nums[i];  // XOR each number because any number XOR'd with itself becomes Zero
    }

    return result;  // This will be the unique number
}

// Main function to test with examples
int main() {
    // Test Case 1
    int nums1[] = {2, 3, 2, 4, 4};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Test Case 1: {2, 3, 2, 4, 4}\n");
    printf("Single number is: %d\n\n", findSingleNumber(nums1, size1));

    // Test Case 2
    int nums2[] = {10, 20, 10, 30, 30};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Test Case 2: {10, 20, 10, 30, 30}\n");
    printf("Single number is: %d\n\n", findSingleNumber(nums2, size2));

    // Test Case 3
    int nums3[] = {99};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Test Case 3: {99}\n");
    printf("Single number is: %d\n", findSingleNumber(nums3, size3));

    return 0;
}
