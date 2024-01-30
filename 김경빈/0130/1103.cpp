#include <iostream>
#include <vector>
#include <string>
#define endl "\n"
using namespace std;

int N, M, dy[] = { -1, 1, 0, 0 }, dx[] = { 0, 0, -1, 1 }, isvisited = false, max_cnt = -1;
string str[51];
bool visited[51][51] = { false, };
int cnt[51][51] = { 0, };

int dfs(int y, int x) {
	if (cnt[y][x]) {
		return cnt[y][x];
	}
	int dr, dc;
	int ismove = 0, move = str[y][x] - '0';
	for (int i = 0; i < 4; i++) {
		dr = y + dy[i] * move;
		dc = x + dx[i] * move;

		if (dr >= 0 && dr < N && dc >= 0 && dc < M) {
			if (visited[dr][dc]) {
				isvisited = true;
				return 0;
			}
			else if(not visited[dr][dc] && str[dr][dc] != 'H'){
				ismove++;
				visited[dr][dc] = true;
				cnt[y][x] = max(cnt[y][x], dfs(dr, dc) + 1);
				visited[dr][dc] = false;
			}
		}
	}
	if (ismove == 0) {
		cnt[y][x] = 1;
	}
	return cnt[y][x];
}

int main() {
	cin >> N >> M;
	for (int n = 0; n < N; n++) {
		cin >> str[n];
	}

	visited[0][0] = true;
	cnt[0][0] = dfs(0, 0);
	
	if (isvisited) {
		cout << -1 << endl;
	}
	else {
		cout << cnt[0][0] << endl;
	}
}