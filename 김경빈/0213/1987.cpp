#include <iostream>
#include <queue>
#include <map>
#include <climits>
#include <cstring>
using namespace std;

string str[20];
int R, C, max_cnt, visited[20][20], visit_alpha[26];
int dy[] = { -1, 1, 0, 0 }, dx[] = { 0, 0, -1, 1 };

void DFS(int y, int x, int cnt) {
	bool isgo = false;

	for (int i = 0; i < 4; i++) {
		int dr = y + dy[i];
		int dc = x + dx[i];
		if (dr < 0 || dr >= R || dc < 0 || dc >= C) continue;
		if (visited[dr][dc] == 1 || visit_alpha[str[dr][dc] - 'A'] == 1) continue;
		isgo = true;
		visited[dr][dc] = 1;
		visit_alpha[str[dr][dc] - 'A'] = 1;
		DFS(dr, dc, cnt + 1);
		visited[dr][dc] = 0;
		visit_alpha[str[dr][dc] - 'A'] = 0;
	}
	if (not isgo && cnt > max_cnt) max_cnt = cnt;
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> str[i];
	}
	memset(visited, 0, sizeof(visited));
	memset(visit_alpha, 0, sizeof(visit_alpha));
	visit_alpha[str[0][0] - 'A'] = 1;
	DFS(0, 0, 1);
	
	cout << max_cnt;
}
