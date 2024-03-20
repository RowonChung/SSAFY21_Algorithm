#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int N, M;
vector<int>v[20001];
int dist[20001];

void checkDist(int start) {
	priority_queue<int>pq;
	pq.push(start);

	while (!pq.empty()) {
		int now = pq.top();
		pq.pop();

		for (int i = 0;i < v[now].size();i++) {
			int dest = v[now][i];

			if (dist[dest] <= dist[now] + 1) continue;

			dist[dest] = dist[now] + 1;

			pq.push(dest);
		}
	}
	
	return;
}

int main() {
	cin >> N >> M;

	for (int i = 0;i < M;i++) {
		int from, to;
		cin >> from >> to;

		v[from].push_back(to);
		v[to].push_back(from);
	}

	for (int i = 1;i <= N;i++) {
		dist[i] = 21e8;
	}

	dist[1] = 0;
	
	checkDist(1);

	int minIndex = 0;
	for (int i = 1;i <= N;i++) {
		if (dist[i] > dist[minIndex])
			minIndex = i;
	}

	int cnt = 0;
	for (int i = 1;i <= N;i++) {
		if (dist[i] == dist[minIndex])
			cnt++;
	}

	cout << minIndex << " " << dist[minIndex] << " " << cnt;

	return 0;
}