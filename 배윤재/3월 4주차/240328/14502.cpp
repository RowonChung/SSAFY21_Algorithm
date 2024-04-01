#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int map[8][8];
int copyMap[8][8];
int visited[8][8];
int safeArea = 0;
int copySafe = 0;
pair<int, int>beok[3];
vector<pair<int, int>> vGroup;

int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };
int maxSafe = 0;

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

			if (map[i][j] == 0) safeArea++;
			else if (map[i][j] == 2) vGroup.push_back({ i, j });
		}
	}
}

void virusBfs(int sy, int sx) {

	int vVisit[8][8] = { 0 };

	queue<pair<int, int>> q;
	q.push({ sy, sx });
	vVisit[sy][sx] = 1;

	while (!q.empty()) {
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = nowY + dir[i][0];
			int nx = nowX + dir[i][1];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (vVisit[ny][nx] == 1) continue;
			
			if (copyMap[ny][nx] == 0) {
				vVisit[ny][nx] = 1;
				copyMap[ny][nx] = 1;
				copySafe--;
				q.push({ ny, nx });
			}
		}
	}
}

void virus() {
	for (int i = 0; i < vGroup.size(); i++) {
		virusBfs(vGroup[i].first, vGroup[i].second);
		if (copySafe == 0) return;
	}
}

void dfs(int sy, int sx, int num) {

	if (num == 3) {
		for (int i = 0; i < 3; i++) {
			copyMap[beok[i].first][beok[i].second] = 1;
			copySafe--;
		}

		virus();
		maxSafe = max(maxSafe, copySafe);

		copySafe = safeArea;
		memcpy(copyMap, map, sizeof(map));
		
		return;
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == 1) continue;
			if (copyMap[i][j] == 0) {

				visited[i][j] = 1;
				copyMap[i][j] = 1;
				beok[num] = { i, j };

				dfs(i, j, num + 1);

				visited[i][j] = 0;
				copyMap[i][j] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();

	copySafe = safeArea;
	memcpy(copyMap, map, sizeof(map));
	dfs(0, 0, 0);

	cout << maxSafe;
}