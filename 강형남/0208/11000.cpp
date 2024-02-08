#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include<algorithm>
using namespace std;

priority_queue<int,vector<int>,greater<int>> pq;

int N;

struct node {
	int s;
	int e;
};

vector<node> v;

bool op (node left, node right) {
	if (left.s < right.s)return true;
	if (left.s > right.s)return false;
	return false;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end(), op);
	int size = v.size();
	for (int i = 0; i < size; i++) {
		node now = v[i];
		if (pq.empty()) {
			pq.push(now.e);
			continue;
		}
		pq.push(now.e);

		if (pq.top() <= now.s) {
			pq.pop();

			continue;
		}
	}

	cout << pq.size();
}