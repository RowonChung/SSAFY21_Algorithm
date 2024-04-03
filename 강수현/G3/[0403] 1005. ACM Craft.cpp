#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;

struct Node {
	int num;
	int cost;

	bool operator<(Node r) const {
		return cost > r.cost;
	}
};

int T, N, K, tar;
int Time[1001];
vector<int>v[1001];
int inDegree[1001];

void init() {
	memset(Time, 0, sizeof(Time));
	for (int i = 1; i <= N; i++) v[i].clear();
	memset(inDegree, 0, sizeof(inDegree));
}

void input() {
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> Time[i];
	}

	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		inDegree[b]++;
	}

	cin >> tar;
}

void solve() {
	priority_queue<Node>pq;

	// init
	for (int i = 1; i <= N; i++)
		if (inDegree[i] == 0) pq.push({ i, Time[i]});

	while (pq.top().num != tar) {
		Node now = pq.top();
		pq.pop();

		for (int i = 0; i < v[now.num].size(); i++) {
			inDegree[v[now.num][i]]--;

			if (inDegree[v[now.num][i]] == 0) pq.push({ v[now.num][i] , now.cost+Time[v[now.num][i]] });
		}
	}

	cout << pq.top().cost << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		init();

		input();

		solve();
	}

	return 0;
}