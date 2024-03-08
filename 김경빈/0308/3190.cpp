#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <climits>
using namespace std;

struct SNAKE {
	int y, x;
};
struct MOVE {
	int sec;
	char direc;
};
int N, K, L, ay, ax, hy, hx, ty, tx, arr[101][101], ans, idx, direc = 1;
int dr, dc, dy[] = { -1, 0, 1, 0 }, dx[] = { 0, 1, 0, -1 };
deque<SNAKE> snake;
MOVE mv[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> ay >> ax;
		arr[ay-1][ax-1] = -1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> mv[i].sec >> mv[i].direc;
	}

	arr[0][0] = 1;
	snake.push_back({ 0, 0 });
	while (true) {
		ans++;

		dr = hy + dy[direc];
		dc = hx + dx[direc];
		if (dr < 0 || dr >= N || dc < 0 || dc >= N) break;
		if (arr[dr][dc] == 1) break;

		if (arr[dr][dc] == 0) {
			auto tail = snake.back();
			snake.pop_back();
			arr[tail.y][tail.x] = 0;
		}

		
		hy = dr; hx = dc;
		snake.push_front({ hy, hx });
		arr[hy][hx] = 1;

		if (mv[idx].sec == ans) {
			if (mv[idx].direc == 'L') {
				direc = (direc + 3) % 4;
			}
			else if (mv[idx].direc == 'D') {
				direc = (direc + 1) % 4;
			}

			idx++;
		}

		cout << endl;
		cout << ans << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	cout << ans;
 }