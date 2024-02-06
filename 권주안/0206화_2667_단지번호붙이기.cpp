#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int y;
	int x;
};

int N;
string input[25];
char mapchar[25][25];
int map[25][25];
int visited[25][25];
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
int dat[700];

int bfs(int sy, int sx) {
	Node q[700] = { 0 };
	int h = 0;
	int t = 0;
	q[t++] = { sy,sx };
	visited[sy][sx] = 1;
	int num = map[sy][sx];
	while (h != t) {
		Node now = q[h++];
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dr[i];
			int nx = now.x + dc[i];
			if (ny >= N || nx >= N || ny < 0 || nx < 0) continue;
			if (map[ny][nx] != num) continue;
			if (visited[ny][nx] == 1) continue;
			visited[ny][nx] = 1;
			q[t++] = { ny,nx };
		}
	}
	return t;
}

int main() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		cin >> input[y];
	}
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			mapchar[y][x] = input[y][x];
			map[y][x] = mapchar[y][x] - '0';
		}
	}
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (visited[y][x] == 0 && map[y][x] == 1) {
				int ret = bfs(y, x);
				dat[ret]++;
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i < 700; i++) {
		if (dat[i] != 0) {
			for (int j = 0; j < dat[i]; j++) {
				cnt++;
			}
		}
	}
	cout << cnt << "\n";
	for (int i = 1; i < 700; i++) {
		if (dat[i] != 0) {
			for (int j = 0; j < dat[i]; j++) {
				cout << i << "\n";
			}
		}
	}

	return 0;
}