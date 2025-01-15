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

	Node(string data) {
		this->data = data;
	}

	void add_child(Node* child) {
		children.push_back(child);
	}
};

void print_tree(Node* tree, int level = 0) {
	string s = "";
	if (tree != nullptr) {
		for (int i = tree->children.size() - 1; i >= 0; --i) {
			print_tree(tree->children[i], level + 1);
		}

		for (int i = 0; i < level; i++) {
			s += "| ";
		}

		s += tree->data;
		cout << s << endl;

		for (Node* child : tree->children) {
			print_tree(child, level + 1);
		}
	}
}

int main()
{
	Node* tree = new Node("A");

	tree->add_child(new Node("B"));
	tree->add_child(new Node("C"));

	Node* nodeB = tree->children[0];
	nodeB->add_child(new Node("D"));
	nodeB->add_child(new Node("E"));
	nodeB->add_child(new Node("F"));

	Node* nodeE = nodeB->children[1];
	nodeE->add_child(new Node("NULL"));
	nodeE->add_child(new Node("NULL"));
	nodeE->add_child(new Node("EXIT"));



	print_tree(tree);
	return 0;
}