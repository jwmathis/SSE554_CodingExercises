// Jan 14 2025
// Module21_Exercise1.cpp
// 

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
public:
	string data;
	vector<Node*> children;

	Node(string data) : data(data) {}

	// Method to add child node
	void add_child(Node* child) { children.push_back(child); }
};

// Implementing a Depth First Search Traversal
bool find_path_to_exit(Node* root, vector<string>& path) {
	if (root == nullptr) return false; // No exit

	path.push_back(root->data); // Add path to vector

	if (root->data == "Exit") return true; // Exit is found

	for (Node* child : root->children) { // Move to a child leaf and search
		if (find_path_to_exit(child, path)) return true;
	}

	path.pop_back(); // remove direction if dead end
	return false; // No path found for exit
}
//void print_tree(Node* root, int level = 0) {
//	if (root == nullptr) {
//		cout << "end";
//		return;
//	}
//
//	for (int i = 0; i < level; i++) {
//		cout << "  ";
//	}
//	cout << root->data << endl;
//
//	for (Node* child : root->children) {
//		print_tree(child, level + 1);
//	}
//}
//void print_tree(Node* tree, int level = 0) {
//	string s = "";
//	if (tree != NULL) {
//		print_tree(tree->right, level + 1);
//
//		for (int i = 0; i < level; i++) {
//			s += "| ";
//		}
//		s += to_string(tree->data);
//		cout << s << endl;
//		print_tree(tree->left, level + 1);
//	}
//}

int main()
{
	// Create maze non-binary tree
	Node* root = new Node("A");

	Node* child1 = new Node("B");
	Node* child2 = new Node("C");
	root->add_child(child1);
	root->add_child(child2);

	Node* child3 = new Node("D");
	Node* child4 = new Node("E");
	Node* child5 = new Node("F");
	Node* child6 = new Node("G");
	Node* child7 = new Node("Exit");

	child1->add_child(child3);
	child1->add_child(child4);
	child2->add_child(nullptr);
	child2->add_child(child5);

	child3->add_child(nullptr);
	child3->add_child(child6);
	child4->add_child(nullptr);
	child4->add_child(nullptr);
	child4->add_child(child7);
	child5->add_child(nullptr);
	child5->add_child(nullptr);

	child6->add_child(nullptr);
	child6->add_child(nullptr);

	//print_tree(root);

	vector<string> path;
	if (find_path_to_exit(root, path)) {
		cout << "Path to exit: ";
		for (const string& step : path) {
			cout << step << " ";
		}
		cout << endl;
	}
	else {
		cout << "No exit found." << endl;
	}

	return 0;
}