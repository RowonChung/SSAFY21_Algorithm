#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Node {
	int y, x, time;
};

int r, c;
string map[1001];
int startY, startX;
int fireMap[1003][1003];
int miro[1003][1003];

int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };

queue<Node> fires;
int minTime = 1e9;

void input() {
	cin >> r >> c;

	for (int i = 0; i < r; i++) cin >> map[i];

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'F') {
				fires.push({ i, j, 1 });
				fireMap[i][j] = 1;
			}
			if (map[i][j] == 'J') {
				startY = i;
				startX = j;
			}
		}
	}
}

void firePath(int sy, int sx) {
	while (!fires.empty()) {
		Node now = fires.front();
		fires.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];

			if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
			if (map[ny][nx] == '#' || fireMap[ny][nx] != 0) continue;
			
			int nextTime = now.time + 1;
			if (fireMap[ny][nx] != 0 && fireMap[ny][nx] <= nextTime) continue;

			fireMap[ny][nx] = nextTime;
			fires.push({ ny, nx, nextTime });
		}
	}
}

void jihoon(int sy, int sx) {
	queue<Node> q;
	
	q.push({ sy, sx, 1 });
	miro[sy][sx] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];

			if (ny < 0 || ny >= r|| nx < 0 || nx >= c) {
				if (minTime > now.time) {
					minTime = now.time;
				}
				continue;
			}

			if (map[ny][nx] == '#' || miro[ny][nx] != 0) continue;

			int nextTime = now.time + 1;
			if (fireMap[ny][nx] != 0 && fireMap[ny][nx] <= nextTime) continue;
			miro[ny][nx] = nextTime;

			q.push({ ny, nx, nextTime });
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();

	if (!fires.empty()) firePath(fires.front().y, fires.front().x);
	
	jihoon(startY, startX);

	if (minTime == 1e9) cout << "IMPOSSIBLE";
	else cout << minTime;
}