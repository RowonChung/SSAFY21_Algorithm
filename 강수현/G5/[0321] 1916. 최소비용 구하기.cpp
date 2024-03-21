#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 100000000

struct Node {
	int to;
	int cost;

	bool operator<(Node r) const {
		if (cost > r.cost) return true;
		else return false;
	}
};

struct Edge {
	int prev;
	int cost;
};

int N, M;
vector<Node>v[1001];
Edge dist[1001];
int s, e;

void dijkstra(int start) {
	for (int i = 1; i <= N; i++) {
		dist[i] = { i, INF };
	}

	priority_queue<Node>pq;
	pq.push({ start, 0 });
	dist[start].cost = 0;

	while (!pq.empty()) {
		Node now = pq.top();
		if (now.to == e) {
			return;
		}
		pq.pop();
		for (int i = 0; i < v[now.to].size(); i++) {
			Node next = v[now.to][i];
			int nextcost = next.cost + dist[now.to].cost;
			if (dist[next.to].cost <= nextcost) continue;
			pq.push({ next.to, nextcost });
			dist[next.to].prev = now.to;
			dist[next.to].cost = nextcost;
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to, cost });
	}

	cin >> s >> e;

	dijkstra(s);

	cout << dist[e].cost;


	return 0;
}