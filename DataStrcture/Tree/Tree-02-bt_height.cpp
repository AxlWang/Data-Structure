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

int FindHeight(Node* root) {
	if (root == NULL) return -1;
	int LeftHeight = FindHeight(root->left);
	int RightHeight = FindHeight(root->right);
	return ((LeftHeight < RightHeight) ? RightHeight : LeftHeight) + 1;
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
	root = Insert(root, 19);
	int height = FindHeight(root);
	cout << "The height of the tree is: " << height << endl;
	return 0;
}

