#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

struct Node {
	int v, w;
};

struct compare {
	bool operator() (const Node &a, const Node &b){
		return a.w > b.w;
	}
};

int n, m;
vector<Node> road[1001];
int dist[1001];
int path[1001];
priority_queue<Node, vector<Node>, compare> pq;

void dijkstra(int start) {
	for (int i = 1; i <= n; i++) dist[i] = 1e9;

	pq.push({ 1, 0 });
	dist[1] = 0;

	while (!pq.empty()) {
		int now = pq.top().v, d = pq.top().w;
		pq.pop();

		// 현재까지 거리가 최소면 continue
		if (dist[now] < d) continue;

		for (auto nxt : road[now]) {
			// 파괴한 경로 배제 (양방향)
			if (now == start && nxt.v == path[start]) continue;
			if (now == path[start] && nxt.v == start) continue;

			if (dist[nxt.v] > (d + nxt.w)) {
				// 초기에 돌렸다면 경로 저장 (이후는 저장 필요 X)
				if (start == 0) path[nxt.v] = now;
				dist[nxt.v] = (d + nxt.w);
				pq.push({ nxt.v, dist[nxt.v] });
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z; cin >> x >> y >> z;
		road[x].push_back({ y, z });
		road[y].push_back({ x, z });
	}

	// 초기 최소 경로 탐색
	dijkstra(0);

	// N부터 1까지 최소 경로 중 한 곳 지워주며 다시 탐색
	int ans = dist[n];
	for (int curr = n; curr > 1;) {
		// 다시 1부터 N 거리 탐색
		dijkstra(curr);
		// 최소 거리 갱신 (최대로)
		ans = max(ans, dist[n]);
		// 다음 경로로 이동
		curr = path[curr];
	}

	cout << ans;
	return 0;
}