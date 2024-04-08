#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <unordered_map>
using namespace std;

struct BLOCK {
	int y, x;
};
int N, M, ans, arr[21][21], visited[21][21];
int dy[] = { -1, 1, 0, 0 }, dx[] = { 0, 0, -1, 1 };
queue<BLOCK> q;
vector<BLOCK> group;

void bomb(int y, int x) {
	memset(visited, 0, sizeof(visited));
	int color = arr[y][x];
	int cnt = 0;
	visited[y][x] = 1;
	arr[y][x] = -2;
	q.push({ y, x });
	while (!q.empty()) {
		BLOCK qp = q.front();
		q.pop();
		cnt++;

		for (int i = 0; i < 4; i++) {
			int dr = qp.y + dy[i];
			int dc = qp.x + dx[i];

			if (dr < 0 || dr >= N || dc < 0 || dc >= N) continue;
			if (visited[dr][dc]) continue;
			if (arr[dr][dc] != color && arr[dr][dc] != 0) continue;

			visited[dr][dc] = 1;
			arr[dr][dc] = -2;
			q.push({ dr, dc });
		}
	}
	
	ans += cnt * cnt;
}

bool find_group() {
	memset(visited, 0, sizeof(visited));
	int sy = -1, sx = -1, sz = 2, rainbow = -1;
	int cnt = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] <= 0 || visited[i][j]) continue;

			int color = arr[i][j];
			int rain_cnt = 0;
			visited[i][j] = cnt;
			q.push({ i, j });
			group.push_back({ i, j });
			while (!q.empty()) {
				BLOCK qp = q.front();
				q.pop();

				for (int d = 0; d < 4; d++) {
					int dr = qp.y + dy[d];
					int dc = qp.x + dx[d];

					if (dr < 0 || dr >= N || dc < 0 || dc >= N) continue;
					if (arr[dr][dc] < 0) continue;
					if (arr[dr][dc] == 0 && visited[dr][dc] == cnt) continue;
					if (arr[dr][dc] > 0 && arr[dr][dc] != color) continue;
					if (arr[dr][dc] == color && visited[dr][dc]) continue;

					if (arr[dr][dc] == 0) rain_cnt++;
					visited[dr][dc] = cnt;
					q.push({ dr, dc });
					group.push_back({ dr, dc });
				}
			}

			BLOCK g = group[0];
			if (group.size() > sz) {
				sy = g.y;
				sx = g.x;
				rainbow = rain_cnt;
				sz = group.size();
			}
			else if (group.size() == sz) {
				if (rain_cnt > rainbow) {
					sy = g.y;
					sx = g.x;
					rainbow = rain_cnt;
					sz = group.size();
				}
				else if (rain_cnt == rainbow) {
					if (g.y > sy) {
						sy = g.y;
						sx = g.x;
						rainbow = rain_cnt;
						sz = group.size();
					}
					else if (g.y == sy && g.x > sx) {
						sy = g.y;
						sx = g.x;
						rainbow = rain_cnt;
						sz = group.size();
					}
				}
			}
			group.clear();
			cnt++;
		}
	}

	if (sy == -1) return false;
	bomb(sy, sx);
	return true;
}

void rotate() {
	int temp_arr[21][21];
	memcpy(temp_arr, arr, sizeof(arr));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[j][i] = temp_arr[i][N - j - 1];
		}
	}
}

void gravity() {
	for (int c = 0; c < N; c++) {
		int change = N - 1;
		for (int r = N - 1; r >= 0; r--) {
			if (arr[r][c] == -1) {
				change = r - 1;
			}
			else if (arr[r][c] >= 0) {
				if (change != r) {
					arr[change][c] = arr[r][c];
					arr[r][c] = -2;
				}
				change--;
			}
		}
	}
}

int main() {	
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	while (find_group()) {
		gravity();
		rotate();
		gravity();
	}

	cout << ans << '\n';
}