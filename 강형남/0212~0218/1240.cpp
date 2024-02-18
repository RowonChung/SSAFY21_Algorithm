#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct node {
	int dest;
	int cost;
};

vector<node> v[1005];
int dist[1005] = { 0, };

int bfs(int start, int end) {
	int sum = 0;
	fill(dist, dist + 1005, -1);
	queue<int> q;
	q.push(start);
	dist[start] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (auto i : v[now]) {
			if (dist[i.dest] != -1) continue;
			dist[i.dest] = dist[now] + i.cost;
			q.push(i.dest);
		}
	}

	return dist[end];
}

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N - 1; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to,cost });
		v[to].push_back({ from,cost });
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << bfs(a, b) << "\n";
	}

}