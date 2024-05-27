#include <stdio.h>

// Function prototypes
int calculate_sum(int numbers[], int size);

int main()
{
    int size;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int numbers[size];

    // Get the elements of the array from the user
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &numbers[i]);
    }

    // Calculate the sum of the numbers in the array
    int sum = calculate_sum(numbers, size);

    // Print the sum
    printf("Sum of the numbers: %d\n", sum);

    return 0;
}

// Function to calculate the sum of numbers in an array
int calculate_sum(int numbers[], int size)
{
    int sum = 0;

    // Iterate through the array and add each element to the sum
    for (int i = 0; i < size; i++)
    {
        sum += numbers[i];
    }

    return sum;
}
