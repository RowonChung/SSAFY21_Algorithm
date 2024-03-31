#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Info {
	int idx, dir;
};
Info board[4][4]; // -1 술래, 0 빈칸, 1 ~ 16 도둑
int ans;
// ↑, ↖, ←, ↙, ↓, ↘, →, ↗ 
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

void move(int idx) {
	// 방향 반대로 이동, 한번에 한 칸, 이동 X -> 45도 회전
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			if (board[x][y].idx == idx) {
				int dir = board[x][y].dir;
				while (1) {
					int nx = x + dx[dir], ny = y + dy[dir];
					if (nx < 0 || nx > 3 || ny < 0 || ny > 3 || board[nx][ny].idx == -1) dir = (dir + 1) % 8;
					else {
						board[x][y] = board[nx][ny];
						board[nx][ny] = { idx, dir };
						return;
					}
				}
			}
		}
	}
}

bool check(int x, int y, int dir) {
	for (int i = 1; i < 4; i++) {
		int nx = x + dx[dir] * i, ny = y + dy[dir] * i;
		if (nx < 0 || nx > 3 || ny < 0 || ny > 3) continue;
		if (board[nx][ny].idx != 0) return true;
	}
	return false;
}

void sulrae(int x, int y, int dir, int cnt) {
	if (!check(x, y, dir)) { ans = max(ans, cnt); return; }

	Info temp[4][4];
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) temp[x][y] = board[x][y];
	}

	for (int k = 1; k < 4; k++) {
		int nx = x + dx[dir] * k, ny = y + dy[dir] * k;
		if (nx < 0 || nx > 3 || ny < 0 || ny > 3) continue;
		if (board[nx][ny].idx == 0) continue;

		board[x][y].idx = 0;
		int idx = board[nx][ny].idx;
		board[nx][ny].idx = -1;

		for (int i = 1; i < 17; i++) move(i);

		sulrae(nx, ny, board[nx][ny].dir, cnt + idx);
		
		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 4; y++) board[x][y] = temp[x][y];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int p, d; cin >> p >> d;
			board[i][j] = { p, d-1 };
		}
	}

	ans = board[0][0].idx;
	board[0][0].idx = -1;
	for (int i = 1; i < 17; i++) move(i);
	sulrae(0, 0, board[0][0].dir, ans);

	cout << ans;
	return 0;
}