#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct qInfo {
	int level;
	int pos;
};

int n, m;
unordered_map<int, int> ladder;
unordered_map<int, int> snake;
unordered_set<int> visited;

int bfs() {
	queue<qInfo> q;
	q.push({ 0, 1 });
	visited.insert(1);

	while (!q.empty()) {
		qInfo now = q.front();
		q.pop();

		if (now.pos == 100) return now.level;

		for (int i = 1; i <= 6; i++) {
			int nextPos = now.pos + i;

			if (nextPos > 100) continue;
			if (visited.find(nextPos) != visited.end()) continue;

			if (ladder.find(nextPos) != ladder.end()) {
				nextPos = ladder[nextPos];
			}
			else if (snake.find(nextPos) != snake.end()) {
				nextPos = snake[nextPos];
			}

			if (visited.find(nextPos) == visited.end()) {
				visited.insert(nextPos);
				q.push({ now.level + 1, nextPos });
			}
		}
	}

	return -1;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		ladder[x] = y;
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		snake[u] = v;
	}

	cout << bfs();

	return 0;
}
