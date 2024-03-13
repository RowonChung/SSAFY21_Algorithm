#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int N, M, K, a, b, visited[30001];
long long candy[30001], dp[30001];
vector<vector<int>> v;
queue<int> q;
unordered_map<int, int> um;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	v.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> candy[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i]) continue;
		int parent = i;
		um[i] = 1;
		q.push(i);
		visited[i] = 1;
		while (!q.empty()) {
			int qp = q.front();
			q.pop();

			for (int x : v[qp]) {
				if (visited[x]) continue;
				visited[x] = 1;
				um[parent]++;
				candy[parent] += candy[x];
				q.push(x);
			}
		}
	}

	for (auto iter:um) {

		for (int j = K-1; j >= 0; j--) {
			if (iter.second > j) break;
			dp[j] = max(dp[j], candy[iter.first] + dp[j - iter.second]);
		}
	}
	cout << dp[K-1];
}