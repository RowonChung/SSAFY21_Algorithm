#include <iostream>
#include <vector>
using namespace std;

int n;
vector<char> biTree[150];
vector<char> preorder;
vector<char> inorder;
vector<char> postorder;

void dfs(int node) {
	preorder.push_back(node);
	for (int i = 0; i < 2; i++) {
		if (i == 1) inorder.push_back(node);
		int next = biTree[node][i];
		if (next == 46) continue;
		dfs(next);
	}
	postorder.push_back(node);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		char parent, child1, child2;
		cin >> parent >> child1 >> child2;
		biTree[parent].push_back(child1);
		biTree[parent].push_back(child2);
	}
	dfs((int)'A');
	for (int i = 0; i < preorder.size(); i++) {
		cout << preorder[i];
	}
	cout << "\n";
	for (int i = 0; i < inorder.size(); i++) {
		cout << inorder[i];
	}
	cout << "\n";
	for (int i = 0; i < postorder.size(); i++) {
		cout << postorder[i];
	}

	return 0;
}