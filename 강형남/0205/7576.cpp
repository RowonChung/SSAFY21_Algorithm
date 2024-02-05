#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

/*
	1 익은 토마토
	0 익지 않은 토마토
	-1 없음

*/



int map[1000][1000];

int dist[1000][1000];

int N, M;

struct node {
	int y;
	int x;
};

queue<node>q;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void fun() {
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
				continue;
			}
			if (dist[ny][nx] != 0)continue;
			if (map[ny][nx] == -1) {
				dist[ny][nx] = -1;
				continue;
			}
			node next = { ny,nx };
			q.push(next);
			dist[ny][nx] = dist[now.y][now.x] + 1;
		}
	}
}

int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				q.push({ i,j });
				dist[i][j] = 1;
			}
		}
	}
	fun();
	int maxx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (dist[i][j] == 0&&map[i][j]!=-1) {
				cout << "-1";
				return 0;
			}
			maxx = max(maxx, dist[i][j]);
		}
	}
	cout << maxx - 1;
	int aa = -1;

}