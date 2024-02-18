#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, V;
int arr[1001][10001] = { 0 };
int visited[1001] = { 0 };

void dfs(int node) {
	cout << node << " ";
	for (int i = 1;i <= N;i++) {
		if (arr[node][i] == 0) continue;

		if (visited[i] == 1) continue;

		visited[i] = 1;
		dfs(i);
	}

	return;
}

void bfs(int start) {
	queue<int> q;

	q.push(start);

	while (!q.empty()) {
		int now = q.front();

		q.pop();

		cout << now << " ";

		for (int i = 1;i <= N;i++) {
			if (arr[now][i] == 0) continue;

			if (visited[i] == 1) continue;

			visited[i] = 1;

			q.push(i);
		}
	}

	return;
}

int main() {

	cin >> N >> M >> V;

	for (int i = 0;i < M;i++) {
		int from, to;

		cin >> from >> to;

		arr[from][to] = 1;
		arr[to][from] = 1;
	}

	visited[V] = 1;
	dfs(V);
	cout << "\n";

	// 초기화
	memset(visited, 0, sizeof(visited));
	
	visited[V] = 1;
	bfs(V);

	return 0;
} 