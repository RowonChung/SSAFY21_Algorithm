#include <iostream>
#include <algorithm>
using namespace std;

#define INF int(1e9)

int coin[100];
int memo[101][10001];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i < n + 1; i++) cin >> coin[i];

	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < m + 1; j++) memo[i][j] = INF;
	}
	memo[0][0] = 0;

	for (int i = 1; i < n + 1; i++) {
		for (int next = 0; next < m + 1; next++) {
			if (next >= coin[i]) memo[i][next] = min(memo[i - 1][next - coin[i]] + 1, memo[i - 1][next]);
			else memo[i][next] = memo[i - 1][next];
		}
	}

	if (memo[n][m] == INF) cout << -1;
	else cout << memo[n][m];

	return 0;
}
