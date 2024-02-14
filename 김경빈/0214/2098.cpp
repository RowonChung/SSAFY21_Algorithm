#include <iostream>
#include <queue>
#include <map>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;

int N, arr[16][16], dp[1 << 16][16];

int dfs(int visited, int now) {
	if (dp[visited][now]) return dp[visited][now];

	if (visited == (1 << N) - 1) {
		if (arr[now][0] == 0) {
			return 219876543;
		}
		return arr[now][0];
	}

	int temp = 219876543;

	for (int i = 0; i < N; i++) {
		if (!(visited & (1 << i)) && arr[now][i]) {
			temp = min(temp, dfs(visited | (1 << i), i) + arr[now][i]);
		}
	}
	return dp[visited][now] = temp;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	cout << dfs(1, 0);
}
