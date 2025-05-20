#include <stdio.h>

// Function to calculate sum of elements in the array
int summation(int arr[], int size) {
    int sum = 0;

    // Go through each element and add each to the sum variable
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum;
}

// Function to find the maximum number in the array
int maximum(int arr[], int size) {
    //I Assume first number is the max like in case study 1
    int max = arr[0];

    // Go through  and update max if there is a bigger number
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

// Main function
int main() {
    int n;

    // Ask user for the number of elements
    printf("Enter the number of integers (n): ");
    scanf("%d", &n);

    // Declare the array with size n
    int numbers[n];

    // Let the user enter the integers
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    // Call the two functions and store their results
    int total = summation(numbers, n);
    int largest = maximum(numbers, n);

    // Show the outputs
    printf("\nSum of numbers: %d\n", total);
    printf("Maximum number: %d\n", largest);

    return 0;
}
