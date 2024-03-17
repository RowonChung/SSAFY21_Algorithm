#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, K;

char map[100][100];

int visited[100][100];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int level = 1;

int dat[200];

struct node {
	int y;
	int x;
};

void fun(int y, int x) {
	queue<node> q;
	q.push({ y,x });
	visited[y][x] = level;
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + now.y;
			int nx = dx[i] + now.x;
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
			if (visited[ny][nx] != 0)continue;
			if (map[ny][nx] == '*')continue;
			q.push({ ny,nx });
			visited[ny][nx] = level;
		}
	}
}

int main() {
	cin >> N >> M >> K;

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			map[i][j] = '*';
		}
	}

	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		map[a-1][b-1] = '-';
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == '-'&&visited[i][j]==0) {
				fun(i, j);
				level++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] != 0) {
				dat[visited[i][j]]++;
			}
		}
	}

	int maxx = -1;

	for (int i = 0; i < 200; i++) {
		maxx = max(maxx, dat[i]);
	}

	cout << maxx;
}