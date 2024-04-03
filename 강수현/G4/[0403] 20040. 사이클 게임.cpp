#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node {
	int a, b;
};

int N, M;
vector<Node>v;
int arr[500000];

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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	init();

	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		v.push_back({ from, to });
	}

	int target = N - 1;

	for (int i = 0; i < v.size(); i++) {
		int a = v[i].a;
		int b = v[i].b;

		// cycle 확인
		if (find(a) == find(b)) {
			cout << i + 1;
			return 0;
		}

		setUnion(a, b);
	}

	cout << "0";

	return 0;
}