#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct Node {
	int y, x;
};

struct Ice {
	int y, x, height;
	bool exist;
};

int n, m;
int map[301][301];
int visited[301][301];
vector<Ice> ices;

int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };
int check = 0;
int existNum = 0;

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

			if (map[i][j] == 0) continue;
			ices.push_back({ i, j, map[i][j], true });
			existNum++;
		}
	}
}

void bfs(int sy, int sx) {
	queue<Node> q;

	q.push({ sy, sx });
	visited[sy][sx] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];

			if (ny <= 0 || ny >= n - 1 || nx <= 0 || nx >= m - 1) continue;
			if (map[ny][nx] == 0 || visited[ny][nx] == 1) continue;

			visited[ny][nx] = 1;
			// 확인한 빙산 늘리기
			check++;
			q.push({ ny, nx });
		}
	}
}

int main() {

	input();

	int time = 0;

	while (true) {

		// 빙산 다 녹았으면 바로 빠져나오기
		if (existNum == 0) break;

		memset(visited, 0, sizeof(visited));

		++time;

		for (int i = 0; i < ices.size(); i++) {
			if (!ices[i].exist) continue;

			int sea = 0;

			int nowY = ices[i].y;
			int nowX = ices[i].x;

			for (int d = 0; d < 4; d++) {
				int ny = nowY + dir[d][0];
				int nx = nowX + dir[d][1];

				if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
				if (map[ny][nx] == 0) sea++;
			}

			ices[i].height -= sea;

			if (ices[i].height <= 0) {
				ices[i].exist = false;
				existNum--;
				ices[i].height = 0;
			}
		}

		for (int i = 0; i < ices.size(); i++) {
			int nowY = ices[i].y;
			int nowX = ices[i].x;

			map[nowY][nowX] = ices[i].height;
		}

		int groups = 0;
		
		// 확인한 빙산이 존재하는 빙산과 동일한지
		check = 0;

		for (int i = 0; i < ices.size(); i++) {
			// 존재하는 빙산 다 확인했으면 빠져나오기
			if (check == existNum) break;
			if (!ices[i].exist) continue;
			if (visited[ices[i].y][ices[i].x] == 1) continue;

			groups++;

			// 덩어리가 2 이상이면 빠져나오기
			if (groups >= 2) {
				cout << time;
				return 0;
			}

			check++;
			bfs(ices[i].y, ices[i].x);
		}
	}

	cout << 0;
}