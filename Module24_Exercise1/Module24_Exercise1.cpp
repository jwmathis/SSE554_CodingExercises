// Feb 09, 2025
// Module24_Exercise1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Simple Bubble Sort alphabetizer

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void shuffle (string items[], int length) {
    for (int i = 0; i < length; i++) {
		int index = rand() % (length - i) + i;
		string temp = items[index];
		items[index] = items[i];
		items[i] = temp;
	}
}

void print_items (string items[], int length) {

	for (int i = 0; i < length; i++) {
		std::cout << items[i] << " ";
	}
	std::cout << std::endl;
}

void bubble_sort (string items[], int length) {
	for (int i = 0; i < length; i++) {
		int swaps = 0;

		for (int j = 0; j < length - i - 1; j++) {
			if (items[j] > items[j + 1]) {
				string temp = items[j];
				items[j] = items[j + 1];
				items[j + 1] = temp;
				swaps+=1;
			}

		}
		if (swaps == 0) {
			break;
		}
	}
}
int main()
{
	srand(time(NULL));

	cout << "Bubble Sort" << endl;
	cout << "-----------" << endl;
	cout << "Enter 10 random numbers: " << endl;
	string items[10];
	// store uesr input in the array
	for (int i = 0; i < 10; i++) {
		cin >> items[i];
	}
	int length = sizeof(items) / sizeof(items[0]);
	print_items(items, length);
	bubble_sort(items, length);
	print_items(items, length);
	cout << endl;

	return 0;
}

