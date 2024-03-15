#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

struct Node {
	int y;
	int x;
};

int M, N;
vector<int>v[1000];
queue<Node>q;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void bfs() {
	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

			if (v[ny][nx] != 0) continue;

			v[ny][nx] = v[now.y][now.x] + 1;
			q.push({ ny,nx });
		}
	}

	int Max = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] == 0) {
				cout << "-1";
				return;
			}

			Max = max(Max, v[i][j]);
		}
	}

	cout << Max -1;
	return;
}

int main() {
	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int input;
			cin >> input;

			v[i].push_back(input);

			if(v[i][j] == 1)
				q.push({ i, j });
		}
	}

	bfs();

	int de = 0;

	return 0;
}