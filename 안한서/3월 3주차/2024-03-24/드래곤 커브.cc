#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int board[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void dragon_curve(int x, int y, int d, int g) {
	vector<int> dist;
	dist.push_back(d);
	int nx = x + dx[d], ny = y + dy[d];
	board[x][y] = board[nx][ny] = 1;

	for (int t = 0; t < g; t++) {
		for (int i = (dist.size() - 1); i >= 0; i--) {
			int nd = (dist[i] + 1) % 4;

			nx = nx + dx[nd]; 
			ny = ny + dy[nd];

			if(0 <= nx && nx <= 100 && 0 <= ny && ny <= 100) board[nx][ny] = 1;
			dist.push_back(nd);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, d, g; cin >> x >> y >> d >> g;
		dragon_curve(x, y, d, g);
	}

	int ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1]) ans++;
		}
	}

	cout << ans;
	return 0;
}