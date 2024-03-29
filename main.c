#include <stdio.h>
#include <math.h>

// Function prototypes
void evenAndOddExchange(int array[10]);
int countNumberOfDigits(int input);
int combineIndex(int array[10]);

int main() {

    int i = 0;
    // Task 1: Exchange even and odd indexed elements under certain conditions
    printf("Please enter 10 integers for the array:\n");

    int array[10];

    for (i = 0; i < 10; ++i)
    {
        scanf("%d", &array[i]);
    }

    evenAndOddExchange(array);

    printf("Array after swapping even and odd indexed elements when divisible:\n");

    for (i = 0; i < 10; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");


    // Task 2: Combine pairs of elements and calculate maximum difference
    printf("Please enter 10 integers, each with two digits:\n");
    for (i = 0; i < 10; ++i)
    {
        scanf("%d", &array[i]);
        while(countNumberOfDigits(array[i]) != 2)
        {
            printf("Error! Please enter an integer with two digits only:\n");
            scanf("%d", &array[i]);
        }
    }
    printf("Your array after combining pairs of elements:\n");
    printf("The biggest different between two numbers in your new array is: %d", combineIndex(array));

    return 0;
}

// Function to swap even and odd indexed elements under certain conditions
void evenAndOddExchange(int array[10])
{
    for (int i = 0; i < 4; ++i)
    {
        if (array[2 * i] % array[(2 * i) + 1] == 0)
        {
            int temp = array[2 * i];
            array[2 * i] = array[(2 * i) + 1];
            array[(2 * i) + 1] = temp;
        }
    }
}

// Function to count the number of digits in an integer
int countNumberOfDigits(int input) {
    if (input < 0) {
        input = -input;
    } else if (input == 0) {
        input = input + 2; // Add 2 to handle case when input is zero
    }
    int digitsNumber = log10(input) + 1;

    return digitsNumber;
}

// Function to combine pairs of elements into a new array and calculate maximum difference
int combineIndex(int array[10]) {
    int newArray[5];
    for (int i = 0; i < 5; ++i) {
        if(array[2 * i] < 0 && array[(2 * i) + 1] > 0)
        {
            array[2 * i] = array[2* i] * (-1);
            newArray[i] = array[(2 * i) + 1] * 100 + array[2 * i];
            newArray[i] = newArray[i] * (-1);
        }
        else if(array[2 * i] > 0 && array[(2 * i) + 1] < 0)
        {
            array[(2 * i) + 1] = array[(2 * i) + 1] * (-1);
            newArray[i] = array[(2 * i) + 1] * 100 + array[2 * i];
            newArray[i] = newArray[i] * (-1);
        }
        else
        {
            newArray[i] = array[(2 * i) + 1] * 100 + array[2 * i];
        }
    }

    for (int i = 0; i < 5; ++i) {
        printf("%d ", newArray[i]);
    }
    printf("\n");

    // Calculate the maximum difference between consecutive pairs
    int diff = 0;
    int difMax = 0;
    for (int i = 0; i < 4; ++i)
    {

        if (newArray[i] < 0)
        {
            newArray[i] = -newArray[i];
        }
        if(newArray[i + 1] < 0)
        {
            newArray[i + 1] = -newArray[i + 1];
        }
        diff = newArray[i + 1] - newArray[i];
        if(diff < 0)
            diff = -diff;
        if(diff > difMax)
            difMax = diff;

    }
    return difMax;
}
