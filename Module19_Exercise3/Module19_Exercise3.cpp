// Jan 10 2025
// Module19_Exercise3.cpp
// Implementing a spinning wheel that simulates a game using circular linked list

#include <iostream>
#include <thread>

using namespace std;

void clearScreen();

class Node {
public:
    string data; // game category
    Node* next;

    Node(string d) {
        data = d;
        next = NULL;
    }
};

class CircularLinkedList {
public:
    Node* head;
    Node* tail;

    CircularLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void append_node(string d) {
        Node* new_node = new Node(d); // creates a new node cotaining a data value
        if (head == NULL) {
            head = new_node; // initalize head with the first node
            tail = new_node; // update tail
            tail->next = head; // complete circular link
        }
        else {
            tail->next = new_node; // update previous node to point to added node
            tail = new_node; // update tail
            tail->next = head; // circular link
            
        }
    }

    string spin_wheel(int spins) {
        Node* temp = head;
        int remaining_speed = spins;

        while (remaining_speed > 0) {
            clearScreen();
            cout << temp->data << endl; // Show category
            temp = temp->next; // Update category
            remaining_speed--; // decrease speed
            this_thread::sleep_for(chrono::milliseconds(100)); // small delay for simulating slowing down
        }

        return temp->data;
    }


};

void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

int main()
{
    int value;

    CircularLinkedList wheel;
    wheel.append_node("Math");
    wheel.append_node("Science");
    wheel.append_node("History");
    wheel.append_node("Geography");
    wheel.append_node("Pop Culture");

    // Initialize random seed
    srand(time(0));
    cout << "THe categories are: Math, Science, History, Geography, and Pop Culture.\n";
    cout << "Type \"1\" when you are ready to spin the wheel to select a category. ";
    cin >> value;

    if (value == 1) {
        int initial_speed = rand() % 10 + 10;
        /*cout << "Spin with initial speed: " << initial_speed << endl;*/
        string result = wheel.spin_wheel(initial_speed);
        clearScreen();
        cout << "Final Category is: " << result << endl;
    }
    else {
        cout << "Thanks for playing!" << endl;
        return 0;
    }
}

