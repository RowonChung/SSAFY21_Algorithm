#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int y;
	int x;
};

int N, M;
int map[8][8];
queue<Node>ba;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int Max = 0;

void calSize() {
	queue<Node>q(ba);
	int flag[8][8] = { 0 };

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (map[ny][nx] == 1 || map[ny][nx] == 2) continue;
			if (flag[ny][nx] == 1) continue;

			flag[ny][nx] = 1;
			q.push({ ny,nx });
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (flag[i][j] == 1 || map[i][j] == 2 || map[i][j] == 1) continue;
			cnt++;
		}
	}

	Max = max(cnt, Max);
}

void dfs(int sy, int sx, int level) {
	if (level == 3) {
		// 안전 영역 크기 구하기
		calSize();
		return;
	}
	for (int i = sy; i < N; i++) {
		int j;
		if (i == sy) j = sx;
		else j = 0;

		for (; j < M; j++) {
			if (map[i][j] == 1 || map[i][j] == 2) continue;

			if (j + 1 == M) {
				if (i + 1 == N && level != 2) return;
				map[i][j] = 1;
				dfs(i + 1, 0, level + 1);
				map[i][j] = 0;
			}
			else {
				map[i][j] = 1;
				dfs(i, j + 1, level + 1);
				map[i][j] = 0;
			}
		}
	}

	return;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];

			if (map[i][j] == 2)
				ba.push({ i,j });
		}
	}

	dfs(0, 0, 0);

	cout << Max;
}
