#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

struct Node {
	int num;
	int cost;

	bool operator<(Node r) const {
		return cost > r.cost;
	}
};

int N, E;
int a, b; // 경유 지점
vector<Node>v[801];
int dist[801];

void dijkstra(int start) {
	// init
	for (int i = 1; i < 801; i++) {
		dist[i] = 21e8;
	}
	dist[start] = 0;

	priority_queue<Node>pq;
	pq.push({ start, 0 });

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
	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to, cost });
		v[to].push_back({ from, cost });
	}

	cin >> a >> b;

	int resa = 0, resb = 0;
	int res;

	dijkstra(1);

	if (dist[a] == 21e8 || dist[b] == 21e8) {
		cout << "-1";
		return 0;
	}

	resa += dist[a];
	resb += dist[b];

	dijkstra(a);
	resa += dist[b];
	dijkstra(b);
	resa += dist[N];

	dijkstra(b);
	resb += dist[a];
	dijkstra(a);
	resb += dist[N];

	if (dist[N] == 21e8) cout << "-1";
	else {
		res = min(resa, resb);
		cout << res;
	}

	return 0;
}