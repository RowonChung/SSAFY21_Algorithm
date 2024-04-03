#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node {
	int a, b;
	int cost;
};

bool compare(Node l, Node r) {
	return l.cost < r.cost;
}

int N;
vector<Node>v;
int arr[1000];

void init() {
	for (int i = 0; i < N; i++) {
		arr[i] = i;
	}
}

int find(int tar) {
	if (arr[tar] == tar) return tar;
	int ret = find(arr[tar]);

	arr[tar] = ret;

	return ret;
}

void setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);

	if (t1 == t2) return;
	
	arr[t2] = t1;

	return;
}

int main() {
	cin >> N;

	init();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int input;
			cin >> input;
			if (i >= j) continue;
			v.push_back({i,j,input});
		}
	}

	sort(v.begin(), v.end(), compare);

	int target = N - 1;
	long long result = 0;
	int selectCount = 0;

	for (Node sel : v) {
		int a = sel.a;
		int b = sel.b;
		int cost = sel.cost;

		if (find(a) == find(b)) continue;

		setUnion(a, b);

		result += cost;
		selectCount++;

		if (selectCount == target) break;
	}

	cout << result;

	return 0;
}