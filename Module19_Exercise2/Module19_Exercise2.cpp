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

// 2. Create a DoublyLinkedList Class with append methods and traversal methods
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

        // Initialize list if empty
        if (head == NULL) {
            head = tail = curr = new_node;
        }
        else {
            //append node to the end of the list
            tail->next = new_node; // update tail to point to new_node
            new_node->prev = tail; // update new_node to point back to previous node
            tail = new_node; // update what is considered the tail of the list
        }
    }

    // Method to flip one page forward
    void moveForward() {
        if (curr == NULL) {
            cout << "No page content found." << endl;
            return;
        }
        if (curr->next != NULL) {
            curr = curr->next; // update current page to the next page
            cout << curr->data << endl; // print content of next page
        }
        else { // error handling if end of list is reached
            cout << "You are at the last page.\n\n" << curr->data << endl;
        }
    }

    // Method to flip one page back
    void moveBackward() {
        if (curr == NULL) {
            cout << "No page content found." << endl;
            return;
        }
        if (curr->prev != NULL) {
            curr = curr->prev; // update current page to the previous page content
            cout << curr->data << endl; // show content on update current page
        }
        else { // error handling if beginning of list is reached
            cout << "You are at the first page.\n\n" << curr->data << endl;
        }
    }

    // Method to display 1st page of the book
    void display_current() {
        if (curr == NULL) {
            cout << "No content to display." << endl;
        }
        else {
            cout << curr->data << endl;
        }
    }

};

// Function to clear terminal screen
void clearScreen() {
    cout << "\033[2J\033[1;1H";
}


int main()
{
    // Initialization of doubly linked list
    DoublyLinkedList my_book;
    bool flag = true; // flag to exit book

    // User instruction for navigation
    cout << "Use the arrow keys to navigate the book pages or press 'q' to quit.\n\n";

    // add pages to the book
    my_book.append_node("Once upon a time there lived in a certain village a little country girl, the prettiest creature who was ever seen. "
        "Her mother was excessively fond of her; and her grandmother doted on her still more. This good woman had a little red riding hood made "
        "for her. It suited the girl so extremely well that everybody called her Little Red Riding Hood.\n"
        "One day her mother, having made some cakes, said to her, \"Go, my dear, and see how your grandmother is doing, for I hear she has been "
        "very ill. Take her a cake, and this little pot of butter.\"\n"
        "Little Red Riding Hood set out immediately to go to her grandmother, who lived in another village.");

    my_book.append_node("As she was going through the wood, she met with a wolf, who had a very great mind to eat her up, but he dared not, "
        "because of some woodcutters working nearby in the forest. He asked her where she was going. The poor child, who did not know that it "
        "was dangerous to stay and talk to a wolf, said to him, \"I am going to see my grandmother and carry her a cake and a little pot of butter "
        "from my mother.\"\n"
        "\"Does she live far off?\" said the wolf. \"Oh I say,\" answered Little Red Riding Hood; \"it is beyond that mill you see there, at the "
        "first house in the village.\"\n"
        "\"Well,\" said the wolf, \"and I'll go and see her too. I'll go this way and go you that, and we shall see who will be there first.\""
        "The wolf ran as fast as he could, taking the shortest path, and the little girl took a roundabout way, entertaining herself by gathering "
        "nuts, running after butterflies, and gathering bouquets of little flowers.It was not long before the wolf arrived at the old woman's house. "
        "He knocked at the door: tap, tap.");

    my_book.append_node("\"Who's there?\" \"Your grandchild, Little Red Riding Hood,\" replied the wolf, counterfeiting her voice; \"who has brought you "
        "a cake and a little pot of butter sent you by mother.\"\n"
        "The good grandmother, who was in bed, because she was somewhat ill, cried out, \"Pull the bobbin, and the latch will go up.\"\n"
        "The wolf pulled the bobbin, and the door opened, and then he immediately fell upon the good woman and ate her up in a moment, for it been "
        "more than three days since he had eaten.He then shut the door and got into the grandmother's bed, expecting Little Red Riding Hood, who "
        "came some time afterwards and knocked at the door: tap, tap. \"Who's there?\"\n");

    my_book.append_node("Little Red Riding Hood, hearing the big voice of the wolf, was at first afraid; but believing her grandmother had a cold "
        "and was hoarse, answered, \"It is your grandchild Little Red Riding Hood, who has brought you a cake and a little pot of butter mother "
        "sends you.\" The wolf cried out to her, softening his voice as much as he could, \"Pull the bobbin, and the latch will go up.\""
        "Little Red Riding Hood pulled the bobbin, and the door opened. The wolf, seeing her come in, said to her, hiding himself under the "
        "bedclothes, \"Put the cake and the little pot of butter upon the stool, and come get into bed with me.\"");

    my_book.append_node("Little Red Riding Hood took off her clothes and got into bed. She was greatly amazed to see how her grandmother looked "
        "in her nightclothes, and said to her, \"Grandmother, what big arms you have!\"\n"

        "\"All the better to hug you with, my dear.\"\n"

        "\"Grandmother, what big legs you have!\"\n"

        "\"All the better to run with, my child.\"\n"

        "\"Grandmother, what big ears you have!\"\n"

        "\"All the better to hear with, my child.\"\n"

        "\"Grandmother, what big eyes you have!\"\n"

        "\"All the better to see with, my child.\"\n"

        "\"Grandmother, what big teeth you have got!\"\n"

        "\"All the better to eat you up with.\"\n"

        "And, saying these words, this wicked wolf fell upon Little Red Riding Hood, and ate her all up.");

    // Display initial page
    my_book.display_current();


    do {
        int key = _getch(); // Get keyboard input
        if (key == 224) { // Check if the keyboard input is a special character
            key = _getch(); // Get specific code for arrow keys
            clearScreen(); // Clear screen

            switch (key) {
            case 75: // if key press is Left arrow
                my_book.moveBackward();
                break;

            case 77: // if key press is Right arrow
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

    clearScreen();
    cout << "Thanks for reading!" << endl;
}

