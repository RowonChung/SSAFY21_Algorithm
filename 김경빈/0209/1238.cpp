#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

struct Node {
	int node, cost;

	bool operator<(Node right) const {
		if (cost > right.cost) return true;
		if (cost < right.cost) return false;
		return false;
	}
};
int N, M, X, s, e, t, visited[1001], visited2[1001], max_time = 0;
priority_queue<Node> pq;
Node qp;
vector<vector<Node>> v;

void back(int now) {
	for (int i = 1; i <= N; i++) {
		visited[i] = INT_MAX;
	}
	pq.push({ now, 0 });
	visited[now] = 0;

	while (!pq.empty()) {
		qp = pq.top();
		pq.pop();

		for (Node x : v[qp.node]) {
			int temp_cost = qp.cost + x.cost;
			if (temp_cost >= visited[x.node]) continue;
			visited[x.node] = temp_cost;
			pq.push({ x.node, temp_cost });
		}
	}

}

int go(int now) {
	if (now == X) return 0;
	for (int i = 1; i <= N; i++) {
		visited2[i] = INT_MAX;
	}
	pq.push({ now, 0 });
	visited2[now] = 0;

	while (!pq.empty()) {
		qp = pq.top();
		pq.pop();

		for (Node x : v[qp.node]) {
			int temp_cost = qp.cost + x.cost;
			if (temp_cost >= visited2[x.node]) continue;
			visited2[x.node] = temp_cost;
			pq.push({ x.node, temp_cost });
		}
	}
	return visited2[X];
}

int main() {
	ios::sync_with_stdio;
	cin.tie(0);

	cin >> N >> M >> X;
	v.resize(N + 1);
	for (int i = 0; i < M; i++) {
		cin >> s >> e >> t;
		v[s].push_back({ e, t });
	}
	back(X);
	for (int i = 1; i <= N; i++) {
		max_time = max(max_time, go(i) + visited[i]);
	}
	cout << max_time;
}