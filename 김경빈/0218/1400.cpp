#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <climits>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node{
	int y, x, t;
};
struct light {
	char direc;
	int a, b;
};
int m, n, cnt, sy, sx, ey, ex, dr, dc, dy[] = { -1, 1, 0, 0 }, dx[] = { 0, 0, -1, 1 }, visited[20][20];
char arr[20][20];
queue<Node> q;
Node qp;
light li[10];

int cross(int y, int x, int t, int d) {
	light temp_light = li[arr[y][x]-'0'];
	int temp_time = t % (temp_light.a + temp_light.b);
	if (temp_light.direc == '-') {
		if (d <= 1) {
			if (temp_time < temp_light.a) {
				return t + temp_light.a - temp_time + 1;
			}
			else if (temp_time >= temp_light.a) {
				return t + 1;
			}
		}
		else if (d > 1) {
			if (temp_time < temp_light.a) {
				return t + 1;
			}
			else if (temp_time >= temp_light.a) {
				return t + temp_light.a + temp_light.b - temp_time + 1;
			}
		}
	}
	else if (temp_light.direc == '|') {
		if (d <= 1) {
			if (temp_time < temp_light.b) {
				return t + 1;
			}
			else if (temp_time >= temp_light.b) {
				return t + temp_light.a + temp_light.b - temp_time + 1;
			}
		}
		else if (d > 1) {
			if (temp_time < temp_light.b) {
				return t + temp_light.b - temp_time + 1;
			}
			else if (temp_time >= temp_light.b) {
				return t + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		cin >> m >> n;
		if (m == 0 && n == 0) break;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				visited[i][j] = INT_MAX;
				if (arr[i][j] == 'A') {
					sy = i;
					sx = j;
				}
				else if (arr[i][j] == 'B') {
					ey = i;
					ex = j;
				}
				else if (arr[i][j] >= '0' && arr[i][j] <= '9') {
					cnt++;
				}
			}
		}
		for (int i = 0; i < cnt; i++) {
			int idx;
			cin >> idx;
			cin >> li[idx].direc >> li[idx].a >> li[idx].b;
		}

		visited[sy][sx] = 0;
		q.push({ sy, sx, 0 });
		while (!q.empty()) {
			qp = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				dr = qp.y + dy[i];
				dc = qp.x + dx[i];

				if (dr < 0 || dr >= m || dc < 0 || dc >= n) continue;
				if (arr[dr][dc] == '.') continue;

				int temp_time = qp.t;

				if (arr[dr][dc] >= '0' && arr[dr][dc] <= '9') {
					temp_time = cross(dr, dc, qp.t, i);
				}
				else {
					temp_time += 1;
				}

				if (temp_time >= visited[dr][dc]) continue;
				visited[dr][dc] = temp_time;
				q.push({ dr, dc, temp_time });
			}			
		}

		if (visited[ey][ex] == INT_MAX) cout << "impossible\n";
		else cout << visited[ey][ex] << '\n';

		cnt = 0;
	}
}
