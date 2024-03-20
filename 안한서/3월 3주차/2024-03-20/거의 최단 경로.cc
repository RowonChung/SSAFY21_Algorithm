#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#define INF (1 << 31) - 1

struct Node {
	int v, w;

	bool operator < (const Node &a) const {
		return w > a.w;
	}
};

int ans;
int n, m;
int s, d;
int dist[501];
int road[501][501];
vector<int> path[501];
priority_queue<Node> pq;

int dijkstra() {
	for (int i = 0; i <= n; i++) dist[i] = INF;

	pq.push({ s, 0 });
	dist[s] = 0;

	while (!pq.empty()) {
		int now = pq.top().v, d = pq.top().w;
		pq.pop();

		// 현재까지 거리가 최소면 continue
		if (dist[now] < d) continue;

		for (int i = 0; i < n; i++) {
			if (road[now][i] == 0) continue;
			if (dist[i] < (d + road[now][i])) continue;

			if (dist[i] > (d + road[now][i])){
				// 거리 더 작으면 갱신 후 이동
				dist[i] = d + road[now][i];
				pq.push({ i, dist[i] });
				// 거리 더 작으면 기존 경로는 삭제
				path[i].clear();
			}
			// 경로 추가
			path[i].push_back(now);
		}
	}
	return dist[d];
}

void remove_path() {
	// 저장 된 경로 삭제
	queue<int> q;
	q.push(d);
	bool visited[501] = { false, };
	visited[d] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int nxt : path[now]) {
			// 일단 경로면 다 삭제
			road[nxt][now] = 0;
			// 방문 안한 지점만 queue에 삽입
			if (!visited[nxt]) {
				visited[nxt] = true;
				q.push(nxt);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		cin >> s >> d;
		memset(road, 0, sizeof(road));
		for (int i = 0; i <= n; i++) path[i].clear();

		for (int i = 0; i < m; i++) {
			int u, v, p; cin >> u >> v >> p;
			road[u][v] = p;
		}

		// 최단 경로 찾기 위한 다익스트라
		dijkstra();
		// 최단 경로 삭제
		remove_path();
		// 거의 최단 경로 탐색
		ans = dijkstra();

		if (ans == INF) cout << "-1\n";
		else cout << ans << "\n";
	}
	return 0;
}