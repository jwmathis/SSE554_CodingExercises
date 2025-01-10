// Jan 10 2025
// Module19_Exercise2.cpp
// Implementing a book reader using a doubly linked list
// Story obtained from: https://sites.pitt.edu/~dash/type0333.html

#include <iostream>
#include <conio.h>

using namespace std;

// 1. Construct a Node class with data and *next with a constructor
class Node {
public:
    string data;
    Node* prev;
    Node* next;

    Node(string d) {
        data = d;
        prev = next = NULL;
    }
};

// 2. Create a DoublyLinkedList Class with find methods
class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    Node* curr;

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
        curr = NULL;
    }

    void append_node(string d) {
        Node* new_node = new Node (d);
        if (head == NULL) {
            head = tail = curr = new_node;
        }
        else {
            //append to the end
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }
    void moveForward() {
        if (curr == NULL) {
            cout << "No page content found." << endl;
            return;
        }
        if (curr->next != NULL) {
            curr = curr->next;
            cout << curr->data << endl;
        }
        else {
            cout << "You are at the last page.\n\n" << curr->data << endl;
        }
    }

    void moveBackward() {
        if (curr == NULL) {
            cout << "No page content found." << endl;
            return;
        }
        if (curr->prev != NULL) {
            curr = curr->prev;
            cout << curr->data << endl;
        }
        else {
            cout << "You are at the first page.\n\n" << curr->data << endl;
        }
    }

    void display_current() {
        if (curr == NULL) {
            cout << "No content to display." << endl;
        }
        else {
            cout << curr->data << endl;
        }
    }

};

void clearScreen() {
    cout << "\033[2J\033[1;1H";
}


int main()
{
    DoublyLinkedList my_book;
    bool flag = true;

    // User instruction for navigation
    cout << "Use the arrow keys to navigate the book pages or press 'q' to quit.\n\n";

    // add pages to the book
    my_book.append_node("Once upon a time there lived in a certain village a little country girl, the prettiest creature who was ever seen. Her mother was excessively fond of her; and her grandmother doted on her still more. This good woman had a little red riding hood made for her. It suited the girl so extremely well that everybody called her Little Red Riding Hood. ");
    my_book.append_node("One day her mother, having made some cakes, said to her, \"Go, my dear, and see how your grandmother is doing, for I hear she has been very ill.Take her a cake, and this little pot of butter.\" ");
    my_book.append_node("Little Red Riding Hood set out immediately to go to her grandmother, who lived in another village. ");
    my_book.append_node("As she was going through the wood, she met with a wolf, who had a very great mind to eat her up, but he dared not, because of some woodcutters working nearby in the forest. He asked her where she was going. The poor child, who did not know that it was dangerous to stay and talk to a wolf, said to him, \"I am going to see my grandmother and carry her a cake and a little pot of butter from my mother.\" ");

    // Display initial page
    my_book.display_current();


    do {
        int key = _getch(); // Get key input
        if (key == 224) { // Check if its special character
            key = _getch(); // Get specific arrow key
            clearScreen(); // Clear screen

            switch (key) {
            case 75: // Left arrow
                my_book.moveBackward();
                break;

            case 77: // Right arrow
                my_book.moveForward();
                break;

            default: 
                cout << "Use the left and right arrow keys to navigate the book pages or press 'q' to quit.";
                break;
            }
        }
        else if (key == 'q') {
            flag = false;
        }
    } while (flag);

    cout << "Thanks for reading!" << endl;
}

