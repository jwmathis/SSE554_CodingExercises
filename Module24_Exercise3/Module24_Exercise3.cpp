// Module24_Exercise3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

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

void merge(int items[], int left, int middle, int right) {
    // Create enough storage to merge the two sections fo the items array
    vector<int> storage(right - left + 1);

    // Three indexes to keep track of the place in the left section, middle section, and right section
    int left_index = left;
    int right_index = middle + 1;
    int storage_index = 0;

    // While there is something in both the left and right sections
    while (left_index <= middle && right_index <= right) {
        // If the left section has a number smaller than the right section copy it over to the storage
        if (items[left_index] <= items[right_index]) {
			storage[storage_index++] = items[left_index++];
		}
		// Otherwise copy the number from the right section to storage
		else {
			storage[storage_index++] = items[right_index++];
		}
	}

    // Check to see if there are any numbers in the left section and copy them over
    // Numbers would only be in the left section if the right section ran out
    while (left_index <= middle) {
		storage[storage_index++] = items[left_index++];
	}

    // Check to see if there are any numbers in the right section and copy them over
    // Numbers would onl y be in the right section if the left section ran out
    while (right_index <= right) {
        storage[storage_index++] = items[right_index++];
    }
    // Copy the merged numbers back into the correct place in the items array
    for (int i = left; i <= right; i++) {
        items[i] = storage[i - left];
    }

    print_items(items, 10);
}

void merge_recurse(int items[], int left, int right) {
    // If the left and right indexes pass each other it is the base case
    if (left >= right) {
        return;
    }

    // Find the middle
    int middle = (left + right) / 2;

    // Recurse the left and right
    merge_recurse(items, left, middle);
    merge_recurse(items, middle + 1, right);

    // Merged the sorted left and right sections
    merge(items, left, middle, right);
}

void merge_sort(int items[], int length) {
    // Start the recursion with all valid indexes
    // (length - 1 instead of length because the index starts at 0)
    merge_recurse(items, 0, length - 1);
}

int main()
{
    srand (time(NULL));
	// Crete 10 items
    int items[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // Test merge sort
    cout << "Merge Sort" << endl;
    shuffle(items, 10);
    print_items(items, 10);
    merge_sort(items, 10);
    print_items(items, 10);
    cout << endl;

    return 0;
}

