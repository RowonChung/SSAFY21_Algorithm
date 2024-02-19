#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int F, S, G, U, D;
int visited[1000001];

void bfs(int depart) {
	queue<int> q;
	q.push(depart);
	visited[depart] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < 2; i++) {
			if (i == 0) {
				int next = now + U;
				if (next > F) continue;
				if (visited[next] != 0) continue;
				visited[next] = visited[now] + 1;
				q.push(next);
			}
			else {
				int next = now - D;
				if (next < 1) continue;
				if (visited[next] != 0) continue;
				visited[next] = visited[now] + 1;
				q.push(next);
			}
		}
	}
}

int main() {
	cin >> F >> S >> G >> U >> D;
	bfs(S);

	if (visited[G] == 0) cout << "use the stairs\n";
	else cout << visited[G] - 1;

	return 0;
}