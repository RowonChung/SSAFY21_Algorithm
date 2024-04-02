#include <iostream>
#include <queue>
using namespace std;

int n;
int tarA, tarB;
int m;
int alis[101][101];
queue<int> q;
int visit[101];

void bfs() {
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (alis[now][i] == 0) continue;
			if (visit[i] != 0) continue;
			q.push(i);
			visit[i] = visit[now] + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> tarA >> tarB;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		alis[x][y] = 1;
		alis[y][x] = 1;
	}
	q.push(tarA);
	visit[tarA] = 1;
	bfs();
	cout << visit[tarB] - 1;

	return 0;
}