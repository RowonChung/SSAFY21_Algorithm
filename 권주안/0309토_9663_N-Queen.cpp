#include <iostream>
#include <cstring>
using namespace std;

struct Node { int y, x; };
int N;
int MAP[15][15];
int visited[15][15];
int cnt = 0;
int dr[] = { -1,-1,0,1,1,1,0,-1 };
int dc[] = { 0,1,1,1,0,-1,-1,-1 };

void putQueen(Node Queen) {
	visited[Queen.y][Queen.x] = 1;
	for (int k = 1; k < N; k++) {
		for (int i = 0; i < 8; i++) {
			int ny = Queen.y + dr[i] * k;
			int nx = Queen.x + dc[i] * k;
			if (ny >= N || nx >= N || ny < 0 || nx < 0) continue;
			visited[ny][nx] = 1;
		}
	}
}

void dfs(int level) {
	if (level == N) {
		cnt++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (visited[level][i] == 1) continue;
		int temp[15][15];
		memcpy(temp, visited, sizeof(visited));
		putQueen({ level,i });
		dfs(level + 1);
		memcpy(visited, temp, sizeof(visited));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	dfs(0);
	cout << cnt;

	return 0;
}