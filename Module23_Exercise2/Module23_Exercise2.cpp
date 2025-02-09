// Feb 09, 2025
// Module23_Exercise2.cpp
// Program that opens a text file containing a paragraph and calculates:
// the total number of words in the paragraph
// the number of words that end with "ing"
// the number of words with more than six letters.
// https://www.geeksforgeeks.org/count-occurrences-of-a-word-in-string-set-2-using-regular-expressions/
// Random paragraph was generated from: https://randomwordgenerator.com/paragraph.php

#include <iostream>
#include <fstream>
#include <regex>
#include <string>

using namespace std;

int countOccurrences(string str, string regex_pattern) {
	regex pattern(regex_pattern);

	int count = 0;

	auto it = sregex_iterator(str.begin(), str.end(), pattern);

	for (it; it != sregex_iterator(); it++) {
		count++;
	}

	return count;
}

int main()
{
	// Open file for reading
	ifstream file("input.txt");
	if (!file.is_open()) {
		cerr << "Unable to open file.\n";
		return 1;
	}
	
	string line;
	int count_ing = 0;
	int count_words = 0;
	int count_six = 0;
	while (getline(file, line)) {
		count_ing += countOccurrences(line, "\\w+ing");
		count_words += countOccurrences(line, "\\w+");
		count_six += countOccurrences(line, "\\w{6}");
	}
	cout << "Number of words in the paragraph: " << count_words << endl;
	cout << "Number of words that end with \"ing\" in the paragraph: " << count_ing << endl;
	cout << "Number of words with more than six letters in the paragraph: " << count_six << endl;

	file.close();
	return 0;
}
