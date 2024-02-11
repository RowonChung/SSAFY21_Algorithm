#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, cnt, len;
int board[13][13];

// dir : 위 아래 좌 우
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int core;
vector<pair<int, int>> loc;

bool check(int x, int y, int dir) {
	int nx = x + dx[dir], ny = y + dy[dir];
	while (!(nx < 0 || nx >= n || ny < 0 || ny >= n)) {
		if (board[nx][ny] != 0) return false;
		nx += dx[dir]; ny += dy[dir];
	}
	return true;
}

void dfs(int idx, int temp) {
	if (temp + (core - idx) < cnt) return;
	if (idx == core) {
		if (temp >= cnt) { // 연결 된 core 개수가 기존보다 크면
			// 전선 길이 count
			int line = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (board[i][j] == 2) line++;
				}
			}

			// 전선 길이 갱신 (core 개수 같으면 최소로)
			if (temp > cnt) { cnt = temp; len = line; }
			else if (temp == cnt) len = min(len, line);
		}
		return;
	}
	
	// 보드 복사
	int copy[13][13];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) copy[i][j] = board[i][j];
	}

	int x = loc[idx].first, y = loc[idx].second;
	for (int d = 0; d < 4; d++) {
		if (check(x, y, d)) {
			// 전선 설치 가능하면 설치 후 dfs
			int nx = x + dx[d], ny = y + dy[d];
			while (!(nx < 0 || nx >= n || ny < 0 || ny >= n)) {
				board[nx][ny] = 2;
				nx += dx[d]; ny += dy[d];
			}
			dfs(idx + 1, temp + 1);

			// 전선 철거
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) board[i][j] = copy[i][j];
			}
		}
	}
	// 연결 안하고 다음 core로 이동
	dfs(idx + 1, temp);
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cnt = 0, len = 1e9;
		loc.clear();

		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
				// 끝에 위치한 core 제외하고 위치 저장
				if (board[i][j] == 1 && !(i == 0 ||  i == n-1 || j ==0 || j == n-1)) loc.push_back({ i, j });
			}
		}
		core = loc.size();
		dfs(0, 0);
		cout << "#" << tc << ' ' << len << '\n';
	}
	return 0;
}