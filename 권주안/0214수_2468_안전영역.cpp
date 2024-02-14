#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int y;
	int x;
};

int N;
int map[101][101];
int visited[101][101];
int cnt[101];
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };

void bfs(Node depart, int height) {
	queue<Node> q;
	q.push(depart);
	visited[depart.y][depart.x] = 1;
	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dr[i];
			int nx = now.x + dc[i];
			if (ny >= N || nx >= N || ny < 0 || nx < 0) continue;
			if (map[ny][nx] <= height) continue;
			if (visited[ny][nx] != 0) continue;
			visited[ny][nx] = visited[now.y][now.x] + 1;
			q.push({ ny,nx });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}
	int maxCnt = -1;
	for (int i = 0; i <= 100; i++) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (map[y][x] > i && visited[y][x] == 0) {
					bfs({ y,x }, i);
				}
			}
		}
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (visited[y][x] == 1) cnt[i]++;
				visited[y][x] = 0;
			}
		}
		if (maxCnt < cnt[i]) maxCnt = cnt[i];
	}
	cout << maxCnt;

	return 0;
}