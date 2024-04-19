#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, visited[1001][1001][2], ans;
char arr[1001][1001];
unordered_map<char, pair<int, int>> um;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	um['N'] = make_pair(-1, 0);
	um['S'] = make_pair(1, 0);
	um['E'] = make_pair(0, 1);
	um['W'] = make_pair(0, -1);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int cnt = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j][0]) continue;

			int y = i, x = j;
			visited[i][j][0] = cnt;
			visited[i][j][1] = 1;

			while (true) {
				int dy = y + um[arr[y][x]].first;s
				int dx = x + um[arr[y][x]].second;

				if (visited[dy][dx][0] != 0 && visited[dy][dx][0] != cnt) {
					break;
				}
				else if (visited[dy][dx][0] == cnt) {
					ans += 1;
					break;
				}
				else if (visited[dy][dx][0] == 0) {
					visited[dy][dx][0] = cnt;
					visited[dy][dx][1] = visited[y][x][1] + 1;

					y = dy;
					x = dx;
				}
			}
			cnt++;
		}
	}
	cout << ans;
}