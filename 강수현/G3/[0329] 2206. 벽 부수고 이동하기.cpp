#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
	int y;
	int x;
	int flag;
};

int N, M;
vector<int>map[1000];
int visited[2][1000][1000];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void bfs() {
	queue<Node>q;
	q.push({ 0,0,0 });
	visited[0][0][0] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (visited[now.flag][ny][nx] != 0) continue;

			if (map[ny][nx] == 1) {
				if (now.flag == 1) continue;

				q.push({ ny,nx,1 });
				visited[1][ny][nx] = visited[now.flag][now.y][now.x] + 1;
			}
			else {
				q.push({ ny,nx, now.flag });
				visited[now.flag][ny][nx] = visited[now.flag][now.y][now.x] + 1;
			}

		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; j++) {
			map[i].push_back(tmp[j] - '0');
		}
	}

	bfs();
	
	if (visited[0][N - 1][M - 1] == 0 && visited[1][N - 1][M - 1] == 0)
		cout << "-1";
	else if (visited[0][N - 1][M - 1] == 0)
		cout << visited[1][N - 1][M - 1];
	else if (visited[1][N - 1][M - 1] == 0)
		cout << visited[0][N - 1][M - 1];
	else
		cout << min(visited[0][N - 1][M - 1], visited[1][N - 1][M - 1]);

	return 0;
}