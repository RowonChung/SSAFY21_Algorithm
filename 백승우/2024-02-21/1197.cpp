#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
	int a, b;
	int price;
	bool operator<(Edge right) const {
		return price < right.price;
	}
};

vector<Edge> edges;

int parent[10001];

void init(int v) {
	for (int i = 0; i < v; i++) parent[i] = i;
}

int findParent(int x) {
	if (parent[x] != x) parent[x] = findParent(parent[x]);
	return parent[x];
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a == b) return;
	parent[b] = a;
}

int v, e;
int a, b, price;

int main() {

	cin >> v >> e;

	init(v);

	for (int i = 0; i < e; i++) {
		cin >> a >> b >> price;
		edges.push_back({ a, b, price });
	}

	sort(edges.begin(), edges.end());

	int target = v - 1;
	int result = 0;
	int selectCount = 0;

	for (Edge sel : edges) {
		int a = sel.a;
		int b = sel.b;
		int price = sel.price;

		if (findParent(a) == findParent(b)) continue;
		unionParent(a, b);

		result += price;
		selectCount += 1;
		if (selectCount == target) break;
	}

	cout << result;
}
