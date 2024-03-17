#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 10000000

int v, e;
int start;
vector<pair<int,int>> adj[20001];
int dist[20001];

struct NODE {
	int index;
	int cost;
	bool operator<(const NODE& n)const {
		return cost > n.cost;
	}
};

priority_queue<NODE> pq;

void solve() {
	for (int i = 1; i <= v; i++) {
		dist[i] = INF;
	}
	dist[start] = 0;
	pq.push({ start,0 });
	while (!pq.empty()) {
		NODE current = pq.top();
		pq.pop();
		for (int i = 0; i < adj[current.index].size(); i++) {
			int next = adj[current.index][i].first;
			int cost = adj[current.index][i].second + current.cost;
			if (cost < dist[next]) {
				pq.push({ next,cost });
				dist[next] = cost;
			}
		}
	}
	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF) {
			cout << "INF\n";
		}
		else {
			cout << dist[i] << "\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> v >> e;
	cin >> start;
	for (int i = 0; i < e; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back({ b,w });
	}
	solve();
}
