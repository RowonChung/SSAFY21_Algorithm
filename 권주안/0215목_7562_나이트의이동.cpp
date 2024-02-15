#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Node {
	int y;
	int x;
};

int T;
int L;
int map[301][301];
Node start, dest;
int dr[] = { -2,-1,1,2,2,1,-1,-2 };
int dc[] = { 1,2,2,1,-1,-2,-2,-1 };

void init() {
	memset(map, 0, sizeof(map));
}

void solve() {
	queue<Node> q;
	q.push(start);
	map[start.y][start.x] = 1;
	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int ny = now.y + dr[i];
			int nx = now.x + dc[i];
			if (ny >= L || nx >= L || ny < 0 || nx < 0) continue;
			if (map[ny][nx] != 0) continue;
			map[ny][nx] = map[now.y][now.x] + 1;
			q.push({ ny,nx });
		}
	}
	cout << map[dest.y][dest.x] - 1 << "\n";
}

int main() {
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> L;
		cin >> start.y >> start.x >> dest.y >> dest.x;
		init();
		solve();
	}

	return 0;
}