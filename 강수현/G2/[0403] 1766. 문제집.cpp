#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int N, M;
vector<int>v[32001];
int inDegree[32001];

void bfs() {
	priority_queue<int, vector<int>, greater<int>>pq;

	// init
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] != 0) continue;
		pq.push(i);
	}

	while (!pq.empty()) {
		int now = pq.top();
		pq.pop();
		cout << now << " ";

		for (int i = 0; i < v[now].size(); i++) {
			inDegree[v[now][i]]--;

			if (inDegree[v[now][i]] == 0) pq.push(v[now][i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		inDegree[b]++;
	}

	bfs();

	return 0;
}