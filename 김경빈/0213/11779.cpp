#include <iostream>
#include <queue>
#include <map>
#include <climits>
#include <cstring>
using namespace std;

struct graph {
	int node, cost;
};
struct Node {
	int node, cost;

	bool operator<(Node right) const {
		if (cost < right.cost) return false;
		if (cost > right.cost) return true;
		return false;
	}
};
int n, m, s, e, c, visited[1001], dist[1001];
priority_queue<Node> pq;
Node qp;
vector<vector<graph>> g;
vector<int> ans;

void dijkstra() {
	fill(visited, visited + n + 1, INT_MAX);
	pq.push({ s, 0 });
	visited[s] = 0;
	while (!pq.empty()) {
		qp = pq.top();
		pq.pop();

		for (graph x : g[qp.node]) {
			int temp_cost = x.cost + qp.cost;
			if (temp_cost >= visited[x.node]) continue;
			visited[x.node] = temp_cost;
			dist[x.node] = qp.node;
			pq.push({ x.node, temp_cost });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	g.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> s >> e >> c;
		g[s].push_back({ e, c });
	}
	cin >> s >> e;

	dijkstra();
	cout << visited[e] << '\n';
	while (e) {
		ans.push_back(e);
		e = dist[e];
	}
	cout << ans.size() << '\n';
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << ' ';
	}
}
