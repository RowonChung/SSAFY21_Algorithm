#include <iostream>
using namespace std;

int N, M;
int arr[2000];
int dp[2000][2000];

void dfs(int nowY, int nowX, int level) {
	int ny = nowY - 1;
	int nx = nowX + 1;
	if (ny < 0 || nx >= N) return;
	int cmp = nx - 2 * (level + 1);
	if (arr[nx] != arr[cmp]) return;
	dp[ny][nx] = 1;
	dfs(ny, nx, level + 1);
}

void dfss(int nowY, int nowX, int level) {
	int ny = nowY - 1;
	int nx = nowX + 1;
	if (ny < 0 || nx >= N) return;
	int cmp = nx - 2 * (level + 1) - 1;
	if (arr[nx] != arr[cmp]) return;
	dp[ny][nx] = 1;
	dfs(ny, nx, level + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	// dp 계산
	for (int y = 0; y < N; y++) {
		dp[y][y] = 1;
		dfs(y, y, 0);
		if (y < N - 1) {
			if (arr[y] == arr[y + 1]) {
				dp[y][y + 1] = 1;
				dfss(y, y + 1, 0);
			}
		}
	}
	cin >> M;
	for (int tc = 0; tc < M; tc++) {
		int q1, q2;
		cin >> q1 >> q2;
		int left = q1 - 1;
		int right = q2 - 1;
		int ans = dp[left][right];
		cout << ans << "\n";
	}

	return 0;
}