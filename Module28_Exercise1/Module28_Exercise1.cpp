// Module28_Exercise1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Utilizes colons to show entry points for user inputs. Uses ANSI color codes to format output. Uses locale to set encoding to UTF-8 to 
// make the CLI more user-friendly.

#include <iostream>
#include <vector>
#include <string>
#include <locale>

using namespace std;

// ANSI color codes
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

void clearScreen() {
	system("cls");
}

void displayBox(const std::string& title) {
	std::cout << u8"┌───────────────────────────┐\n";
	std::cout << u8"│ " << title << std::string(26 - title.size(), ' ') << "│\n";
	std::cout << u8"└───────────────────────────┘\n";
}

void displayMenu() {
	cout << BOLD << BLUE;
	displayBox("To-Do List Manager");
	cout << RESET;
    cout << "------------------\n";
    cout << CYAN << "1. Add Task\n";
	cout << "2. View Tasks\n";
    cout << "3. Remove Task\n";
	cout << "4. Exit\n" << RESET;
    cout << "------------------\n";
    cout << YELLOW <<"Enter your choice: " << RESET;
}

void addTask(vector<string>& tasks) {
    cout << GREEN << "Enter the task: " << RESET;
    cin.ignore();
    string task;
    getline(cin, task);
    tasks.push_back(task);
    cout << GREEN << "Task added successfully!\n" << RESET;
}

void viewTasks(const vector<string>& tasks) {
	if (tasks.empty()) {
		cout << RED << "No tasks found.\n" << RESET;
	}
	else {
		cout << BOLD << BLUE << "Tasks:\n" << RESET;
		for (size_t i = 0; i < tasks.size(); i++) {
			cout << YELLOW  << i + 1 << ". " << RESET << tasks[i] << endl;
		}
	}
}

void removeTask(vector<string>& tasks) {
	if (tasks.empty()) {
		cout << RED << "No tasks to delete.\n" << RESET;
		return;
	}
	viewTasks(tasks);
	cout << GREEN << "Enter the task number to remove: " << RESET;
	int taskNumber;
	cin >> taskNumber;
	if (taskNumber >= 1 && taskNumber <= tasks.size()) {
		tasks.erase(tasks.begin() + taskNumber - 1);
		cout << GREEN << "Task removed successfully!\n" << RESET;
	}
	else {
		cout << RED << "Invalid task number.\n" << RESET;
	}
}
int main()
{
	locale::global(std::locale("en-US.UTF-8"));
    vector<string> tasks;
	int choice;

	do {
		displayMenu();
		cin >> choice;
		clearScreen();

		switch (choice)
		{
			case 1:
				addTask(tasks);
				break;
			case 2:
				viewTasks(tasks);
				break;
			case 3:
				removeTask(tasks);
				break;
			case 4:
				cout << BOLD << BLUE << "Goodbye!\n" << RESET;
				break;
		default:
			cout << RED << "Invalid choice. Please try again.\n" << RESET;
			break;
		}
	} while (choice != 4);

	return 0;
}

