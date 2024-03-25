#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int map[101][101];
int air[101][101];

int cheese = 0;
int ans = 0;
int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };
queue<pair<int, int>> disappear;

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) cheese++;
		}
	}
}

void checkAir(int sy, int sx) {
	queue<pair<int, int>> q;
	q.push({ sy, sx });

	while (!q.empty()) {
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = nowY + dir[i][0];
			int nx = nowX + dir[i][1];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (map[ny][nx] == 1 || air[ny][nx] == 1) continue;

			air[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
}

void cntAir(int sy, int sx) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int ny = sy + dir[i][0];
		int nx = sx + dir[i][1];

		if (air[ny][nx] == 0) continue;
		if (map[ny][nx] == 0) cnt++;
	}

	if (cnt >= 2) {
		cheese--;
		air[sy][sx] = 1;
		disappear.push({ sy, sx });
	}
}

void checkCheese() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) continue;
			cntAir(i, j);
		}
	}
}

void checkDisappear() {
	while (!disappear.empty()) {
		int nowY = disappear.front().first;
		int nowX = disappear.front().second;

		map[nowY][nowX] = 0;
		disappear.pop();

		checkAir(nowY, nowX);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	checkAir(0, 0);

	while (cheese != 0) {
		ans++;

		checkCheese();
		checkDisappear();
	}

	cout << ans;
}