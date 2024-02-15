#include <iostream>
using namespace std;

struct Node {
	int value;
	Node* left;
	Node* right;
};

Node node_pool[10000];
int node_count;

Node* new_node(int value) {
	node_pool[node_count].value = value;
	node_pool[node_count].left = nullptr;
	node_pool[node_count].right = nullptr;

	return &node_pool[node_count++];
}

Node* root;

void init()
{
	root = nullptr;
	node_count = 0;
}

Node* insert_rec(Node* node, int value)
{
	if (node == nullptr) {
		return new_node(value);
	}

	if (value < node->value) {
		node->left = insert_rec(node->left, value);
	}
	else if (value > node->value) {
		node->right = insert_rec(node->right, value);
	}

	return node;
}

void insert(int value)
{
	root = insert_rec(root, value);
}

void traversal_rec(Node* node)
{
	if (node == nullptr) return;
	traversal_rec(node->left);
	traversal_rec(node->right);
	cout << node->value << '\n';
}

int main()
{
	init();

	int value;
	while (cin >> value) {
		insert(value);
	}
	traversal_rec(root);

	return 0;
}
