#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int y;
	int x;
};
int N, M;
int MAP[1001][1001];
int visited[1001][1001];
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
queue<Node> q;

void ff() {
	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dr[i];
			int nx = now.x + dc[i];
			if (ny >= N || nx >= M || ny < 0 || nx < 0) continue;
			if (MAP[ny][nx] == -1 || MAP[ny][nx] == 1) continue;
			if (visited[ny][nx] != 0) continue;
			visited[ny][nx] = visited[now.y][now.x] + 1;
			q.push({ ny,nx });
		}
	}
}

int main() {
	cin >> M >> N;
	int flagAlreadyZero = 1;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> MAP[y][x];
			if (MAP[y][x] == 1) {
				q.push({ y,x });
				visited[y][x] = 1;
			}
			if (MAP[y][x] == 0) flagAlreadyZero = 0;
		}
	}
	if (flagAlreadyZero) {
		cout << 0;
		return 0;
	}
	ff();
	int flagFindUnripenTomato = 0;
	int maxDay = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (MAP[y][x] == 0 && visited[y][x] == 0) {
				flagFindUnripenTomato = 1;
				break;
			}
			if (maxDay < visited[y][x]) {
				maxDay = visited[y][x];
			}
		}
		if (flagFindUnripenTomato) break;
	}
	if (flagFindUnripenTomato) cout << -1;
	else cout << maxDay - 1;

	return 0;
}