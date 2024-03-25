#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
string board[51];

int minCnt = 1e9;

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
}

void sameRC(int row, int col, char color, int cnt) {
	for (int i = row; i < row + 8; i++) {
		for (int j = col; j < col + 8; j++) {
			if (i == row && j == col) continue;

			if (i % 2 == j % 2) {
				if (board[i][j] == color) cnt--;
			}
			else {
				if (board[i][j] != color) cnt--;
			}
		}
	}

	minCnt = min(minCnt, cnt);
}

void diffRC(int row, int col, char color, int cnt) {
	for (int i = row; i < row + 8; i++) {
		for (int j = col; j < col + 8; j++) {
			if (i == row && j == col) continue;

			if (i % 2 != j % 2) {
				if (board[i][j] == color) cnt--;
			}
			else {
				if (board[i][j] != color) cnt--;
			}
		}
	}

	minCnt = min(minCnt, cnt);
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();

	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			if (i % 2 == j % 2) {
				if (board[i][j] == 'W') {
					// 시작점 그대로 뒀을 때
					sameRC(i, j, 'W', 63);

					// 시작점 다시 칠했을 때
					sameRC(i, j, 'B', 64);
				}
				else {
					sameRC(i, j, 'B', 63);
					sameRC(i, j, 'W', 64);
				}
			}
			else {
				if (board[i][j] == 'W') {
					diffRC(i, j, 'W', 63);
					diffRC(i, j, 'B', 64);
				}
				else {
					diffRC(i, j, 'B', 63);
					diffRC(i, j, 'W', 64);
				}
			}
		}
	}

	cout << minCnt;
}