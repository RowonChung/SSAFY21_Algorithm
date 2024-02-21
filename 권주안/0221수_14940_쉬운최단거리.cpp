#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int y;
	int x;
};

int n, m;
int MAP[1001][1001];
int visited[1001][1001];
Node start;
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };

void bfs() {
	queue<Node> q;
	q.push(start);
	visited[start.y][start.x] = 1;
	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dr[i];
			int nx = now.x + dc[i];
			if (ny >= n || nx >= m || ny < 0 || nx < 0) continue;
			if (visited[ny][nx] != 0) continue;
			if (MAP[ny][nx] == 0) continue;
			visited[ny][nx] = visited[now.y][now.x] + 1;
			q.push({ ny,nx });
		}
	}
}

int main() {
	cin >> n >> m;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> MAP[y][x];
			if (MAP[y][x] == 2) {
				start.y = y;
				start.x = x;
			}
		}
	}
	bfs();
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (visited[y][x] > 0 && MAP[y][x] > 0) {
				cout << visited[y][x] - 1 << " ";
			}
			else if (visited[y][x] == 0 && MAP[y][x] == 1) {
				cout << -1 << " ";
			}
			else if (visited[y][x] == 0 && MAP[y][x] == 0) {
				cout << 0 << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}