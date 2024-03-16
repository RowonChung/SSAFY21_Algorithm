#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Node {
	int y, x, cost;

	bool operator<(Node right) const {
		return cost > right.cost;
	}
};

int n;
string map[101];
int dist[101][101];
int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };

void input() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
}

void dijkstra(int sy, int sx) {
	priority_queue<Node> pq;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = 1e9;
		}
	}
	dist[sy][sx] = 0;
	pq.push({ sy, sx, 0 });

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			
			int nextCost = now.cost + (map[ny][nx] - '0');
			if (dist[ny][nx] <= nextCost) continue;

			dist[ny][nx] = nextCost;
			pq.push({ ny, nx, nextCost });
		}

	}
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		input();

		dijkstra(0, 0);

		cout << "#" << tc << " " << dist[n - 1][n - 1] << "\n";
	}
}