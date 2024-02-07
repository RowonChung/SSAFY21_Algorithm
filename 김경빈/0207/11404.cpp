#include <iostream>
#include <queue>
#include <map>
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
int n, m, a, b, c, visited[101];
vector<vector<Node>> v;
priority_queue<Node> pq;
Node qp;

void dijkstra(int now) {
	for (int i = 1; i <= n; i++) {
		visited[i] = INT_MAX;
	}
	visited[now] = 0;
	pq.push({ now, 0 });

	while (!pq.empty()) {
		qp = pq.top();
		pq.pop();

		for (Node x : v[qp.node]) {
			int temp_cost = x.cost + qp.cost;
			if (temp_cost >= visited[x.node]) continue;
			visited[x.node] = temp_cost;
			pq.push({ x.node, temp_cost });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
	}

	for (int i = 1; i <= n; i++) {
		dijkstra(i);
		for (int j = 1; j <= n; j++) {
			if (visited[j] == INT_MAX) {
				cout << 0 << " ";
			}
			else {
				cout << visited[j] << " ";
			}
		}
		cout << "\n";
	}

}