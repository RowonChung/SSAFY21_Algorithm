#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 10000000

struct NODE {
	int index;
	int cost;
	bool operator < (const NODE& n) const {
		return cost > n.cost;
	}
};

int n, e;
int node1, node2;
int dist[801];
vector<pair<int, int>> adj[801];

int Dijkstra(int start, int end) {
	priority_queue<NODE> pq;
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	dist[start] = 0;
	pq.push({ start,0 });
	while (!pq.empty()) {
		NODE current = pq.top();
		if (current.index == end) {
			return current.cost;
		}
		pq.pop();
		for (int i = 0; i < adj[current.index].size(); i++) {
			int nextIndex = adj[current.index][i].first;
			int nextCost = adj[current.index][i].second + current.cost;
			if (nextCost < dist[nextIndex]) {
				dist[nextIndex] = nextCost;
				pq.push({ nextIndex,nextCost });
			}
		}
	}
	return INF;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int n1, n2, cost;
		cin >> n1 >> n2 >> cost;
		adj[n1].push_back({ n2,cost });
		adj[n2].push_back({ n1,cost });
	}
	cin >> node1 >> node2;
	int sum = 0;
	//cout << "first = " << Dijkstra(1, node1) << "\n";
	//cout << "second = " << Dijkstra(node1, node2) << "\n";
	//cout << "third = " << Dijkstra(node2, n) << "\n";
	bool flag1 = true;
	bool flag2 = true;
	int tmp;
	tmp = Dijkstra(1, node1);
	if (tmp == INF) {
		flag1 = false;
	}
	sum += tmp;
	tmp = Dijkstra(node1, node2);
	if (tmp == INF) {
		flag1 = false;
	}
	sum += tmp;
	tmp = Dijkstra(node2, n);
	if (tmp == INF) {
		flag1 = false;
	}
	sum += tmp;

	int sum2 = 0;
	tmp = Dijkstra(1, node2);
	if (tmp == INF) {
		flag2 = false;
	}
	sum2 += tmp;
	tmp = Dijkstra(node2, node1);
	if (tmp == INF) {
		flag2 = false;
	}
	sum2 += tmp;
	tmp = Dijkstra(node1, n);
	if (tmp == INF) {
		flag2 = false;
	}
	sum2 += tmp;
	if (!flag1 && !flag2) {
		cout << -1;
	}
	else {
		cout << min(sum, sum2);
	}
}
