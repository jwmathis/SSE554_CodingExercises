// Module24_Exercise2.cpp 
// Feb 16, 2025
// A program to implement quicksort to sort an unsorted array

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


void shuffle(int items[], int length) {
    for (int i = 0; i < length; i++) {
        int index = rand() % (length - i) + i;
        int temp = items[index];
        items[index] = items[i];
        items[i] = temp;
    }
}

void print_items(int items[], int length) {

    for (int i = 0; i < length; i++) {
        std::cout << items[i] << " ";
    }
    std::cout << std::endl;
}

int partition(int arr[], int low, int high) {
    // Pick the middle item to be the pivot value ad move it out of the way
    int middle = low + (high - low) / 2;
    int pivot = arr[middle];
    arr[middle] = arr[high];
    arr[high] = pivot;
    cout << "Initial pivot element : " << pivot << endl;

    // Keep track of the boundary index
    int boundary = low;

    // Look at all other items
    for (int index = low; index < high; index++) {
		// If the item is less than the pivot, then the boundary has to move
		if (arr[index] < pivot) {

            // Swap with the current boundary value and increase boundary by 1
			int temp = arr[index];
			arr[index] = arr[boundary];
			arr[boundary] = temp;
			boundary++;
		}
	}

    // Move pivot to between the two groups of numbers as idicated by the boundary index
    int temp = arr[high];
    arr[high] = arr[boundary];
    arr[boundary] = temp;

    print_items(arr, 10);

    // Return the boundary to inform quicksort how to recurse 
	return boundary;
}

void quick_recurse(int arr[], int low, int high) {
    // Check for base case
    // Did the left and right boundaries pass each other? Then stop.
    if (low >= high) {
        return;
    }

    // Find the pivot's position after partitioning 
    int pivot_position = partition(arr, low, high);

    // Recurse left and right of pivot
    quick_recurse(arr, low, pivot_position - 1);
    quick_recurse(arr, pivot_position + 1, high);
}

void quick_sort(int arr[], int length) {
    // Start the recursion to include all valid indices
    // (length - 1 instead of length because the index starts at 0)
    quick_recurse(arr, 0, length - 1);
}

int main()
{
    srand(time(NULL));

    // Create 10 items
    int items[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // Test quick sort
    cout << "Quick Sort" << endl;
    shuffle(items, 10);

    print_items(items, 10);
	quick_sort(items, 10);
	print_items(items, 10);
    cout << endl;

    return 0;
}
