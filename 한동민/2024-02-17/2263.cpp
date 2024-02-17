#include <iostream>
#include <stack>
using namespace std;

struct NODE {
	int left = 0, right = 0;
};
int N;
stack<int> postorder;
int inorder[200000];
NODE nodepool[200000];

int search(int left, int right) {
	int pivot = 0;
	if (right < left) {
		return pivot;
	}
	for (int i = left; i <= right; i++) {
		if (inorder[i] == postorder.top()) {
			pivot = i;
			postorder.pop();
			break;
		}
	}
	nodepool[inorder[pivot]].right = search(pivot + 1, right);
	nodepool[inorder[pivot]].left = search(left, pivot - 1);
	return inorder[pivot];
}

void recursion(int current) {
	cout << current << " ";
	if (nodepool[current].left != 0) {
		recursion(nodepool[current].left);
	}
	if (nodepool[current].right != 0) {
		recursion(nodepool[current].right);
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> inorder[i];
	}
	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		postorder.push(tmp);
	}
	/*for (int i = 1; i <= N; i++) {
		cout << "node = " << i << " left = " << nodepool[i].left << " right = " << nodepool[i].right << endl;
	}*/
	recursion(search(1, N));
}
