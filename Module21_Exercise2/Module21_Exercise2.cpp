// Jan 18 2025
// Module21_Exercise2.cpp
// Uses a binary tree to implement a job application. Outputs questions and response and the final application decision.
//

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Class to build a binary tree
class Node {
public:
    string data;
    Node* yes; // Left child for "Yes" responses
    Node* no; // Right child for "No" responses

    // Constructor
    Node(string data) : data(data), yes(nullptr), no(nullptr) {}
};


// Function to create lower case words
string lower(string word) {
    for (char& c : word) {
        c = tolower(c);
    }

    return word;
}

// Function to traverse the treee and handle the questionaire
void conduct_interview(Node* tree) {
    string response;

    if (tree == nullptr) { return; }

    // If at end of leaf, print node
    if (tree->yes == nullptr && tree->no == nullptr) {
        cout << "Outcome: " << tree->data << endl;
        return;
    }

    cout << tree->data << "(Yes/No)" << endl;
    cin >> response;
   
    // Traverse the tree based on the response
    if (lower(response) == "yes") {
        conduct_interview(tree->yes);
    }
    else if (lower(response) == "no") {
        conduct_interview(tree->no);
    }
    else {
        conduct_interview(tree); // Retry the question
    }


}
int main()
{
    // Create binary tree
    Node* root = new Node("Do you have experience in developing applications?");
    root->yes = new Node("Have you worked as a developer for more than 5 years?");
    root->no = new Node("Have you completed the university?");

    root->yes->yes = new Node("Apply as a senior developer!");
    root->yes->no = new Node("Apply as a middle developer!");
    root->no->yes = new Node("Apply as a junior devleoper!");
    root->no->no = new Node("Will you find some time during the semester?");

    root->no->no->yes = new Node("Apply for our long-time internship program!");
    root->no->no->no = new Node("Apply for summer internship program!");

    // Conduct Interview
    cout << "Welcome to Job application system" << endl;
    conduct_interview(root);

    return 0;
}
