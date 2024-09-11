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

void Preorder(Node* root) {
	if (root == NULL) return;
	printf("%d ", root->data);
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(Node* root) {
	if (root == NULL) return;
	Inorder(root->left);
	printf("%d ", root->data);
	Inorder(root->right);
}

void Postorder(Node* root) {
	if (root == NULL) return;
	Postorder(root->left);
	Postorder(root->right);
	printf("%d ", root->data);
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
	printf("Preorder: ");
	Preorder(root);
	printf("\n");
	printf("Inorder: ");
	Inorder(root);
	printf("\n");
	printf("Postorder: ");
	Postorder(root);
	return 0;
}
