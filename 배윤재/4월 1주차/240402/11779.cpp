#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
	int num, cost;

	bool operator<(Edge right) const {
		return cost > right.cost;
	}
};

int n, m;
vector<Edge> city[1001];
int start, dest;
vector<int> path;

void dijkstra(int s) {
	priority_queue<Edge> pq;

	pair<int, int> dist[1001];
	for (int i = 1; i <= n; i++) dist[i].first = 1e9;
	dist[s].first = 0;
	dist[s].second = s;

	pq.push({ s, 0 });

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (now.num == dest) {
			cout << dist[dest].first << "\n";
			break;
		}

		for (int i = 0; i < city[now.num].size(); i++) {
			Edge next = city[now.num][i];

			int nextCost = next.cost + dist[now.num].first;
			if (nextCost >= dist[next.num].first) continue;

			dist[next.num].first = nextCost;
			dist[next.num].second = now.num;
			pq.push({ next.num, nextCost });
		}
	}
	int now = dest;
	path.push_back(dest);
	while (now != s) {
		path.push_back(dist[now].second);
		now = dist[now].second;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;

		city[from].push_back({ to, cost });
	}

	cin >> start >> dest;

	dijkstra(start);

	cout << path.size() << "\n";

	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i] << " ";
	}
}