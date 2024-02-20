#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node {
	int y;
	int x;
};

int n, m;
int MAP[501][501];
int visited[501][501];

int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
Node q[200001];

int bfs(Node node) {
	int h = 0;
	int t = 0;
	q[t++] = node;
	visited[node.y][node.x] = 1;
	while (h != t) {
		Node now = q[h++];
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dr[i];
			int nx = now.x + dc[i];
			if (ny >= n || nx >= m || ny < 0 || nx < 0) continue;
			if (visited[ny][nx] == 1) continue;
			if (MAP[ny][nx] == 0) continue;
			visited[ny][nx] = 1;
			q[t++] = { ny,nx };
		}
	}
	return t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> MAP[y][x];
		}
	}
	int maxBig = 0;
	int cnt = 0;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (MAP[y][x] == 1 && visited[y][x] == 0) {
				int t = bfs({ y,x });
				if (maxBig < t) maxBig = t;
				cnt++;
			}
		}
	}
	cout << cnt << "\n" << maxBig;

	return 0;
}