#include <iostream>
#include <queue>
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

void LevelOrder(Node* root) {
	if (root == NULL) return;
	queue<Node*> Q;
	Q.push(root);
	while (!Q.empty()) {
		cout << Q.front()->data << " ";
		if (Q.front()->left != NULL) Q.push(Q.front()->left);
		if (Q.front()->right != NULL) Q.push(Q.front()->right);
		Q.pop();
	}
	return;
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
	root = Insert(root, 18);
	LevelOrder(root);
	return 0;
}

