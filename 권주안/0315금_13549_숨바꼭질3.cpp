#include <iostream>
#include <queue>
using namespace std;

int N, K;
int board[100001];
int visited[100001];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < 3; i++) {
			if (i == 0) {
				int next = now * 2;
				if (next < 0 || next > 100001) continue;
				if (visited[next] != 0) continue;
				q.push(next);
				visited[next] = visited[now];
			}
			if (i == 1) {
				int next = now - 1;
				if (next < 0 || next > 100001) continue;
				if (visited[next] != 0) continue;
				q.push(next);
				visited[next] = visited[now] + 1;
			}
			if (i == 2) {
				int next = now + 1;
				if (next < 0 || next > 100001) continue;
				if (visited[next] != 0) continue;
				q.push(next);
				visited[next] = visited[now] + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	bfs(N);
	cout << visited[K] - 1;

	return 0;
}