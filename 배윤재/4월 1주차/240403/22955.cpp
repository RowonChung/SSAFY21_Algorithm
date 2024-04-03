#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

struct Node {
	int y, x, cost;

	bool operator<(Node right) const {
		return cost > right.cost;
	}
};


int n, m;
string map[1001];
int dist[1001][1001];
int startY, startX;
int destY, destX;

int flag = false;
int xDestY, xDestX;
int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'C') {
				startY = i;
				startX = j;
			}
			if (map[i][j] == 'E') {
				destY = i;
				destX = j;
			}
		}
	}
}

void findFloor(int sy, int sx, int direct) {

	int ny = sy + dir[direct][0];
	int nx = sx + dir[direct][1];
	if (ny < 0 || ny >= n || nx < 0 || nx >= m) return;
	if (map[ny][nx] == 'D') return;
	if (map[ny][nx] == 'F' || map[ny][nx] == 'L') {
		xDestY = ny;
		xDestX = nx;
		flag = true;
		return;
	}
	findFloor(ny, nx, direct);
}

void dijkstra(int sy, int sx) {
	priority_queue<Node> pq;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
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

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (map[ny][nx] == 'D') continue;
			if (map[now.y][now.x] == 'C') {
				if (i == 0 || (i == 1 && map[ny][nx] == 'F')) continue;
			}
			if (map[now.y][now.x] == 'F') {
				if (i == 0 || (i == 1 && map[ny][nx] != 'L')) continue;
			}
			if (map[now.y][now.x] == 'L') {
				// 위쪽은 개만 아니면 됨
				// 아래쪽은 L인 경우에만 갈 수 있음
				if (i == 1 && map[ny][nx] != 'L') continue;
			}

			int nextCost = now.cost + 1;

			if (i == 0) {
				if (map[now.y][now.x] == 'L') nextCost = now.cost + 5;
			}
			else if (i == 1){
				if ((map[now.y][now.x] == 'C' && map[ny][nx] == 'L') || 
					(map[now.y][now.x] == 'L' && map[ny][nx] == 'L') ||
					(map[now.y][now.x] == 'F' && map[ny][nx] == 'L'))
					nextCost = now.cost + 5;
			}
			else if (map[ny][nx] == 'X') {
				flag = false; 
				findFloor(ny, nx, 1);
				if (flag) {
					nextCost = now.cost + 11;
					if (dist[xDestY][xDestX] <= nextCost) continue;
					dist[xDestY][xDestX] = nextCost;
					pq.push({ xDestY, xDestX, nextCost });
				}
				else nextCost = 1e9;
			}

			if (map[ny][nx] == 'X') continue;
			if (dist[ny][nx] <= nextCost) continue;
			dist[ny][nx] = nextCost;

			int de = -1;

			pq.push({ ny, nx, nextCost });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();

	dijkstra(startY, startX);

	if (dist[destY][destX] == 1e9) cout << "dodo sad";
	else cout << dist[destY][destX];
}