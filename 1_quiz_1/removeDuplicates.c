#include <stdio.h>
//This Was Question 1 for the first Quiz
// Function to remove the duplicates from the  sorted array(I have Predefined them. no user input)
int removeDuplicates(int nums[], int size) {
    if (size == 0)
        return 0;  // If the array is empty then just return 0

    int track = 1;  

    // Loop through the array starting from index 1 since the first element has nothing to be compared to it is at index 0
    for (int read_index = 1; read_index < size; read_index++) {
        // If the current value is not the same as   the one before it, it is not duplicate
        if (nums[read_index] != nums[read_index - 1]) {
            nums[track] = nums[read_index];  // Save the unique value in the index
            track++;  // Move the tracker forward
        }
    }

    return track;  // Return the count of unique elements we have found
}

// A function to print an array up to a size defined in the function invokation
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to run several example cases
int main() {
    // Test Case 1: Some duplicates
    int nums1[] = {1, 1, 2, 2, 3, 4, 4};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int newLength1 = removeDuplicates(nums1, size1);
    printf("Test Case 1 - Original: {1, 1, 2, 2, 3, 4, 4}\n");
    printf("After removing duplicates: ");
    printArray(nums1, newLength1);
    printf("New length: %d\n\n", newLength1);

   

    // All elements are the same testing
    int nums3[] = {7, 7, 7, 7, 7};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    int newLength3 = removeDuplicates(nums3, size3);
    printf("Test Case 3 - Original: {7, 7, 7, 7, 7}\n");
    printf("After removing duplicates: ");
    printArray(nums3, newLength3);
    printf("New length: %d\n\n", newLength3);

    // An Empty array Testing
    int nums4[] = {};
    int size4 = sizeof(nums4) / sizeof(nums4[0]);
    int newLength4 = removeDuplicates(nums4, size4);
    printf("Test Case 4 - Original: {}\n");
    printf("After removing duplicates: ");
    printArray(nums4, newLength4);
    printf("New length: %d\n\n", newLength4);

    return 0;
}
