#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF (1 << 31) - 1
struct Node {
	int loc, w, cnt;
	bool operator < (const Node& a) const {
		return w > a.w;
	}
};

int n, m, k;
int s, d;
vector<pair<int, int>> adj[1001];
int dist[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m >> k;
	cin >> s >> d;
	for (int i = 0; i < m; i++) {
		int a, b, w; cin >> a >> b >> w;
		adj[a].push_back({ b, w });
		adj[b].push_back({ a, w });
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) dist[i][j] = INF;
	}

	priority_queue<Node> pq;
	pq.push({ s, 0, 0 });
	dist[s][0] = 0;

	while (!pq.empty()) {
		int curr = pq.top().loc;
		int w = pq.top().w;
		int cnt = pq.top().cnt;
		pq.pop();

		if (dist[curr][cnt] < w) continue;

		for (auto nxt : adj[curr]) {
			int idx = nxt.first;
			int nw = nxt.second;
			if (dist[idx][cnt + 1] <= (nw + w)) continue;
			dist[idx][cnt + 1] = (nw + w);
			pq.push({ idx, (nw + w), cnt + 1 });
		}
	}
	int sum = 0;
	for (int tc = 0; tc <= k; tc++) {
		if (tc > 0) {
			int tax; cin >> tax;
			sum += tax;
		}

		int ans = INF;
		for (int i = 1; i < n; i++) {
			if (dist[d][i] == INF) continue;
			ans = min(ans, dist[d][i] + i * sum);
		}
		cout << ans << "\n";
	}
	return 0;
}