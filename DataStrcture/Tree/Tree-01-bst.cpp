#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* Insert(Node* root, int data) {
	if (root == NULL) {
		Node* NewNode = new Node();
		NewNode->data = data;
		NewNode->left = NULL;
		NewNode->right = NULL;
		root = NewNode;
	}
	else if (data <= root->data) {
		root->left = Insert(root->left, data);
	}
	else {
		root->right = Insert(root->right, data);
	}
	return root;
};

bool Search(Node* root, int data) {
	if (root == NULL) return false;
	else if (data == root->data) return true;
	else if (data <= root->data) return Search(root->left, data);
	else return Search(root->right, data);
}

int FindMin(Node* root) { //loop
	if (root == NULL) {
		cout << "Empty tree!\n";
		return -1;
	}
	while (root->left != NULL) {
		root = root->left;
	}
	return root->data;
}

int FindMax(Node* root) { //recursion
	if (root == NULL) {
		cout << "Empty tree!\n";
		return -1;
	}
	else {
		if (root->right != NULL) {
			return FindMax(root->right);
		}
		return root->data;
	}
}

int main() {
	Node* root = NULL;
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 12);
	root = Insert(root, 17);
	int number;
	cout << "Print your number: ";
	cin >> number;
	if (Search(root, number)) {
		cout << "Found it.\n";
	}
	else cout << "Not found.\n";
	int min = FindMin(root);
	cout << "The Min is: " << min << endl;
	int max = FindMax(root);
	cout << "The Max is: " << max << endl;
	return 0;
}

