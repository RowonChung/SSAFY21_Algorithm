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

	bool operator<(Node right) const{
		if (cost < right.cost) return false;
		if (cost > right.cost) return true;
		return false;
	}
};
int V, E, K, u, v, w, visited[20001];
priority_queue<Node> pq;
Node qp;
vector<vector<Node>> graph;

int main() {
	ios::sync_with_stdio;
	cin.tie(0);

	cin >> V >> E >> K;
	graph.resize(V + 1);
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}
	for (int i = 1; i <= V; i++) {
		visited[i] = INT_MAX;
	}
	visited[K] = 0;
	pq.push({ K, 0 });
	while (!pq.empty()) {
		qp = pq.top();
		pq.pop();

		for (Node x : graph[qp.node]) {
			int temp_cost = x.cost + qp.cost;
			if (temp_cost >= visited[x.node]) continue;
			visited[x.node] = temp_cost;
			pq.push({ x.node, temp_cost });
		}
	}
	for (int i = 1; i <= V; i++) {
		if (visited[i] == INT_MAX) {
			cout << "INF\n";
		}
		else {
			cout << visited[i] << "\n";
		}
	}
}