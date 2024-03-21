#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node {
	int to;
	int cost;
};

int T, N, M, W;
int map[501][501];

void init() {
	for (int i = 1; i <= 500; i++) {
		for (int j = 1; j <= 500; j++) {
			map[i][j] = 10000;
		}
	}
}

void input() {
	cin >> N >> M >> W;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		map[a][b] = min(map[a][b], c);
		map[b][a] = min(map[b][a], c);
	}

	for (int i = 0; i < W; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		c *= -1;
		map[a][b] = c;
	}
}

void solve() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {

				if (map[j][i] + map[i][k] < map[j][k])
					map[j][k] = map[j][i] + map[i][k];
			}
		}
	}
}

int main() {
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {

		init();

		input();

		solve();

		int flag = 0;
		for (int i = 1; i <= N; i++) {
			if (map[i][i] < 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}