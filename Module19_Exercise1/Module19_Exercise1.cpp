// Jan 09 2025
// Module19_Exercise1.cpp
// Coding linked list with user input

#include <iostream>
#include <string>

using namespace std;

// 1. Construct a Node class
// 2. Create a LinkedList class
// 3. Create methods to append nodes, traverse the list, and display the elements

class Node {
public:
    string data;
    Node* next;
    
    // define the constructor
    Node(string d) {
        data = d;
        next = NULL;
    }

};

class LinkedList {
public:

    Node* head;

    LinkedList() {
        head = NULL;
    }

    // create the append method
    void append_node(string d) {
        Node* new_node = new Node(d); // creates a new node cotaining a data value
        if (head == NULL) {
            head = new_node;
        }
        else {
            Node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = new_node;
        }
    }

    // create display method
    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
        }
        else {
            Node* temp = head;
            while (temp != NULL) {
                cout << temp->data << endl;
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    // instantiate a list
    LinkedList my_list;
    string value;
    int choice = 0;

    cout << "Enter data to populate a singly linked list." << endl;

    do {
        cout << "Enter a value: ";
        cin >> value;
        my_list.append_node(value);

        cout << "Do you want to add another value? (1 for Yes / 0 for No): ";
        cin >> choice;

    } while (choice == 1);

    cout << "\nDisplaying the linked list:" << endl;
    my_list.display();

    return 0;
}

