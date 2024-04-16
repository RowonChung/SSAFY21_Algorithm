#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <cstring>
using namespace std;

struct Node {
	int y, x;
};
int R, C, N, h, c, visited[101][101];
int dy[] = { -1, 1, 0, 0 }, dx[] = { 0, 0, -1, 1 };
char arr[101][101];
queue<Node> q;
vector<Node> fall;

void throw_stick(int lr){
	if (lr == 0) {
		for (int i = 0; i < C; i++) {
			if (arr[R - h][i] == '.') continue;
			arr[R - h][i] = '.';
			c = i;
			return;
		}
	}
	else if (lr == 1) {
		for (int i = C - 1; i >= 0; i--) {
			if (arr[R - h][i] == '.') continue;
			arr[R - h][i] = '.';
			c = i;
			return;
		}
	}
}

void fall_mineral() {
	memset(visited, 0, sizeof(visited));

	int cnt = 1;
	for (int i = 0; i < R - 1; i++) {
		for (int j = 0; j < C; j++) {
			if (visited[i][j] || arr[i][j] == '.') continue;
			
			int isfall = 1;
			q.push({ i, j });
			fall.push_back({ i, j });
			visited[i][j] = cnt;

			while (!q.empty()) {
				Node qp = q.front();
				q.pop();

				for (int d = 0; d < 4; d++) {
					int dr = qp.y + dy[d];
					int dc = qp.x + dx[d];

					if (dr < 0 || dr >= R || dc < 0 || dc >= C) continue;
					if (visited[dr][dc] || arr[dr][dc] == '.') continue;
					if (dr == R - 1) {
						isfall = 0;
					}

					visited[dr][dc] = cnt;
					q.push({ dr, dc });
					fall.push_back({ dr, dc });
				}
			}

			if (isfall) {
				int fall_n = 200;
				for (int v = 0; v < fall.size(); v++) {
					int y = fall[v].y, x = fall[v].x;
					if (arr[y + 1][x] == 'x') continue;

					int temp_fall = 0;
					for (int f = y + 1; f < R; f++) {
						if (arr[f][x] == 'x' && visited[f][x] != cnt) break;
						temp_fall = max(temp_fall, f - y);
					}
					fall_n = min(fall_n, temp_fall);
				}

				for (int v = 0; v < fall.size(); v++) {
					int y = fall[v].y, x = fall[v].x;
					
					arr[y][x] = '.';
				}
				for (int v = 0; v < fall.size(); v++) {
					int y = fall[v].y, x = fall[v].x;

					arr[y + fall_n][x] = 'x';
				}
				fall.clear();
				return;
			}
			else {
				fall.clear();
			}
			cnt++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
		}
	}

	cin >> N;
	for (int n = 0; n < N; n++) {
		cin >> h;

		throw_stick(n % 2);
		fall_mineral();
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
}