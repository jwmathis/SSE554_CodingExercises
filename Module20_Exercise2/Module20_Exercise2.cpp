// Module20_Exercise2.cpp
//

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int d) {
        data = d;
        next = NULL;
    }
};

class Queue {
public:
    Node* front, * rear;
    int size;

    Queue() {
        front = rear = NULL;
        size = 0;
    }

    void enqueue(int d) {
        Node* temp = new Node(d);

        if (rear == NULL) {
            front = rear = temp;
            cout << front->data;
            cout << " is first in line for the slide." << endl;
        }
        else {
            rear->next = temp;
            rear = temp;
            cout << rear->data << " is now at the end of the line for the slide." << endl;
        }
        size++;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "No one's in line for the slide" << endl;
        }
        else {
            Node* temp = front;
            front = temp->next;
            cout << temp->data << " is sliding down!" << endl;
            delete(temp);
        }
        size--;
    }

    int length() {
        return size;
    }
};

int main()
{
    Queue my_queue;
    int num, len;
    while (true) {
        cout << "Enter a number: ";
        cin >> num;
        if (num == -1) {
            break;
        }
        my_queue.enqueue(num);
    }

    len = my_queue.length();

    for (int i = 0; i < len; i++) {
        my_queue.dequeue();
    }

}

