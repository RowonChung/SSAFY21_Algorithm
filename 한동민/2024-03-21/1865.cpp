#include <iostream>
using namespace std;

#define INF 100000000

int N, M, W;
int adj[501][501];
bool flag;

void solve(int index) {

}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N >> M >> W;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				adj[i][j] = INF;
				if (i == j) {
					adj[i][j] = 0;
				}
			}
		}
		for (int i = 0; i < M; i++) {
			int start, end, cost;
			cin >> start >> end >> cost;
			if (adj[start][end] == INF) {
				adj[start][end] = cost;
			}
			else {
				adj[start][end] = min(adj[start][end], cost);
			}
			if (adj[end][start] == INF) {
				adj[end][start] = cost;
			}
			else {
				adj[end][start] = min(adj[end][start], cost);
			}
		}
		for (int i = 0; i < W; i++) {
			int start, end, cost;
			cin >> start >> end >> cost;
			if (adj[start][end] == INF) {
				adj[start][end] = -(cost);
			}
			else {
				adj[start][end] = min(adj[start][end], -(cost));
			}
		}
		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
				}
			}
		}
		bool flag = false;
		for (int i = 1; i <= N; i++) {
			if (adj[i][i] < 0) {
				flag = true;
				break;
			}
		}
		if (flag) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}
