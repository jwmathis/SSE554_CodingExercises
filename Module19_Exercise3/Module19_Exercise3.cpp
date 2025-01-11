// Jan 10 2025
// Module19_Exercise3.cpp
// Implementing a spinning wheel that simulates a game using circular linked list

#include <iostream>
#include <thread>

using namespace std;

void clearScreen();

class Node {
public:
    string data;
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
    Node* curr; // used for determining player's turn

    CircularLinkedList() {
        head = NULL;
        tail = NULL;
        curr = NULL;
    }

    void append_node(string d) {
        Node* new_node = new Node(d); // creates a new node cotaining a data value
        if (head == NULL) {
            head = new_node; // initalize head with the first node
            tail = new_node; // update tail
            tail->next = head; // complete circular link
            curr = head;
        }
        else {
            tail->next = new_node; // update previous node to point to added node
            tail = new_node; // update tail
            tail->next = head; // circular link
            
        }
    }

    // Method to cycle through players
    void nextPlayer() {
        if (curr == NULL) {
            cout << "No players!" << endl;
        }
        else {
            cout << "\n" << curr->data << "'s turn: \n" << endl;
            curr = curr->next;
        }
    }
    string spin_wheel(int spins) {
        Node* temp = head;
        int remaining_speed = spins;

        while (remaining_speed > 0) {
            cout << "Spinning...Current subject:" << temp->data << endl; // Show category
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
    int choice;
    int value;
    bool flag = true;

    CircularLinkedList wheel;
    wheel.append_node("Math");
    wheel.append_node("Science");
    wheel.append_node("History");
    wheel.append_node("Geography");
    wheel.append_node("Pop Culture");

    CircularLinkedList players;
    cout << "Enter number of players: ";
    cin >> value;

    // Add players to circular linked list players
    for (int i = 1; i <= value; i++) {
        char str[100];
        sprintf_s(str, "Player %d", i);
        players.append_node(str);
    }

    // Initialize random seed
    srand(time(0));
    cout << "The categories are: Math, Science, History, Geography, and Pop Culture.\n";

    do {
        players.nextPlayer();
        cout << "Type \"1\" to spin the wheel to select a category. ";
        cin >> choice;

        if (choice == 1) {
            int initial_speed = rand() % 30;
            cout << "Spinning with initial speed of: " << initial_speed << endl;
            string result = wheel.spin_wheel(initial_speed);
            cout << "Final Category is: " << result << endl;
        }
        else {
            cout << "Thanks for playing!" << endl;
            flag = false;
        }
    } while (flag);
}

