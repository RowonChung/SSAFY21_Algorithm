#include <iostream>
#include <queue>
using namespace std;

struct coord {
	int y, x;
};
int N, M, arr[100][100], visited[100][100];
int dy[] = { -1, 1, 0, 0 }, dx[] = { 0, 0, -1, 1 }, dr, dc;
queue<coord> q;
coord qp;

bool melt() {
	bool ismelt = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = arr[i][j];
		}
	}
	q.push({ 0, 0 });
	while (!q.empty()) {
		qp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			dr = qp.y + dy[i];
			dc = qp.x + dx[i];
			if (dr < 0 || dr >= N || dc < 0 || dc >= M) continue;
			if (arr[dr][dc] == 1) {
				ismelt = true;
				visited[dr][dc]++;
				if (visited[dr][dc] >= 3) {
					arr[dr][dc] = 0;
					visited[dr][dc] = 1;
				}
			}
			else {
				if (visited[dr][dc] == 0) {
					visited[dr][dc] = 1;
					q.push({ dr, dc });
				}
			}
		}
	}
	return ismelt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int cnt = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	while (melt()) {
		cnt++;
	}
	cout << cnt;

}