#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
	int num;
	int cost;

	bool operator<(Node r) const {
		return cost > r.cost;
	}
};

int V, E;
int start;
vector<Node>v[20001];
int dist[20001];

void dijkstra() {
	for (int i = 1; i <= V; i++) {
		dist[i] = 21e8;
	}

	priority_queue<Node>pq;
	pq.push({ start, 0 });
	dist[start] = 0;

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		for (int i = 0; i < v[now.num].size(); i++) {
			Node next = v[now.num][i];

			if (next.cost + now.cost >= dist[next.num]) continue;

			dist[next.num] = next.cost + now.cost;

			pq.push({ next.num, dist[next.num] });
		}
	}
}

int main() {
	cin >> V >> E;

	cin >> start;
	
	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;

		v[from].push_back({ to, cost });
	}

	dijkstra();

	for (int i = 1; i <= V; i++) {
		if (dist[i] == 21e8) {
			cout << "INF\n";
			continue;
		}

		cout << dist[i] << "\n";
	}
	
	return 0;
}