#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

char map[100][100];
int dist[100][100];
int dist2[100][100];
int N;

struct node {
	int y;
	int x;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };


// 일반인

int cnt1 = 0;
void fun(int y,int x) {
	node input = { y,x };
	char ch = map[y][x];
	queue<node> q;
	q.push(input);
	dist[y][x] = cnt1;
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N)continue;
			if (dist[ny][nx] != 0)continue;
			if (map[ny][nx] != ch)continue;
			dist[ny][nx] = cnt1;
			q.push({ ny,nx });
		}
	}
}

//색약
int cnt2 = 0;
void fun2(int y, int x) {
	node input = { y,x };
	char ch = map[y][x];
	queue<node> q;
	q.push(input);
	dist2[y][x] = cnt1;
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N)continue;
			if (dist2[ny][nx] != 0)continue;
			if (ch != 'R' && ch != 'G') {
				if (map[ny][nx] != ch)continue;
			}
			if (ch == 'R') {
				if (map[ny][nx] != 'R' && map[ny][nx] != 'G') {
					continue;
				}
			}
			if (ch == 'G') {
				if (map[ny][nx] != 'R' && map[ny][nx] != 'G') {
					continue;
				}
			}
			dist2[ny][nx] = cnt2;
			q.push({ ny,nx });
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			map[i][j] = s.at(j);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dist[i][j] == 0) {
				cnt1++;
				fun(i, j);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dist2[i][j] == 0) {
				cnt2++;
				fun2(i, j);
			}
		}
	}
	cout << cnt1 << " " << cnt2;
}