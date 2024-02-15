#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Info {
	int weight;
	int v;
	bool operator<(Info right) const {
		if (weight < right.weight) return false;
		if (weight > right.weight) return true;
		return false;
	}
};

vector <Info> aList[20005];
int dist[20005];

int V, E;
int K;
int u, v, w;

int main()
{
	cin >> V >> E;
	cin >> K;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		aList[u].push_back({ w, v });
	}
	// dijkstra
	for (int i = 1; i <= V; i++) {
		dist[i] = 1e9;
	}

	priority_queue<Info> pq;

	pq.push({ 0, K });
	dist[K] = 0;

	while (!pq.empty()) {
		int nowWeight = pq.top().weight;
		int now = pq.top().v;

		pq.pop();

		for (int i = 0; i < aList[now].size(); i++) {
			int weight = aList[now][i].weight;
			int next = aList[now][i].v;

			int nextWeight = weight + nowWeight;

			if (dist[next] > nextWeight) {
				dist[next] = nextWeight;
				pq.push({ nextWeight, next });
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == 1e9) cout << "INF";
		else cout << dist[i];
		cout << '\n';
	}

	return 0;
}
