#include <stdio.h>
#include <stdbool.h>  // This header file allows me to use Boolean values

// Function to check if the array has duplicates
bool containsDuplicate(int arr[], int size) {
    // Go through each element in the array one by one
    for (int i = 0; i < size; i++) {
        // Compare it with the elements that come after it
        for (int j = i + 1; j < size; j++) {
            // If we find a match, then it's a duplicate
            if (arr[i] == arr[j]) {
                return true;  // Return true because a duplicate has been found
            }
        }
    }

    
    return false;//False if No Duplicate was found
}

// Function to print true or false (Found or Not Found)
void printResult(bool result) {
    if (result)
        printf("Result: true (duplicates found)\n");
    else
        printf("Result: false (No Dupes Found)\n");
}

// Main function to test
int main() {
    // Example test which has duplicates
    int nums1[] = {1, 2, 3, 1};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Test Case 1: {1, 2, 3, 1}\n");
    printResult(containsDuplicate(nums1, size1));

    // Example test which has no duplicates
    int nums2[] = {5, 10, 15, 20};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("\nTest Case 2: {5, 10, 15, 20}\n");
    printResult(containsDuplicate(nums2, size2));

    
    return 0;
}
