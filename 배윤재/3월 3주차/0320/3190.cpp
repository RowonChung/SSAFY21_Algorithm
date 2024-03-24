#include <iostream>
#include <queue>
using namespace std;

struct Move {
	int time;
	char dir;
};

int snake[101][101];
int apple[101][101];

// 우 하 좌 상
int dir[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };
int direct = 0;

int n;
int headY, headX;
int tailY, tailX;
queue<Move> q;
deque<pair<int, int>> deq;

void input() {
	cin >> n;

	int k;
	cin >> k; 

	for (int i = 0; i < k; i++) {
		int y, x;
		cin >> y >> x;

		y -= 1;
		x -= 1;

		apple[y][x] = 1;
	}

	int l;
	cin >> l;

	for (int i = 0; i < l; i++) {
		int x;
		char c;
		cin >> x >> c;

		q.push({ x, c });
	}
}

int main() {
	input();

	int time = 0;
	snake[0][0] = 1;
	headY = 0, headX = 0;
	tailY = 0, tailX = 0;

	deq.push_back({ tailY, tailX });

	while (true) {
		++time;

		int ny = headY + dir[direct][0];
		int nx = headX + dir[direct][1];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n) break;
		if (snake[ny][nx] == 1) break;

		snake[ny][nx] = 1;
		deq.push_back({ ny, nx });

		headY = ny;
		headX = nx;

		if (apple[ny][nx] == 0) {
			snake[tailY][tailX] = 0;
			deq.pop_front();

			tailY = deq.front().first;
			tailX = deq.front().second;
		}
		else {
			apple[ny][nx] = 0;
		}


		if (!q.empty() && q.front().time == time) {
			if (q.front().dir == 'D') {
				direct = (direct + 1) % 4;
			}
			else if (q.front().dir == 'L') {
				direct = direct - 1;
				if (direct < 0) direct = 3;
			}
			q.pop();
		}
	}

	cout << time;
}
