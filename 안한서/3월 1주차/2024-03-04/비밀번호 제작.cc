#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m; cin >> n >> m;
	vector<int> dist(n + 1, -1);
	queue<int> q;
	for (int i = 0; i < m; i++) {
		int num; cin >> num;
		dist[num] = 0;
		q.push(num);
	}

	int mx = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		mx = max(mx, dist[cur]);
		// 1000000 -> 2^20 까지
		for (int i = 0; i < 20; i++) {
			int nxt = cur ^ (1 << i); // 한 곳 씩 바꾸면서 검사
			// 범위 들어오고 검사 안했으면
			// 하나만 바꿨으니 안전도 1 증가
			if (0 <= nxt && nxt <= n && dist[nxt] == -1) {
				dist[nxt] = dist[cur] + 1;
				q.push(nxt);
			}
		}
	}

	cout << mx;
	return 0;
}