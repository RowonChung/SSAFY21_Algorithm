#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge {
	int num, cost;

	bool operator<(Edge right) const{
		return cost > right.cost;
	}
};

int v, e;
int start;
vector<Edge> alis[300001];
int dist[20001] = { 0, };

void dijkstra(int node)
{
	// 1. pq 준비
	priority_queue<Edge> pq;

	// 2. 정답 배열 준비
	for (int i = 1; i <= v; i++) dist[i] = 21e8;

	// 3. 시작점 기록
	dist[node] = 0;

	// 4. pq에 시작점 넣기
	pq.push({ node, 0 });

	while (!pq.empty())
	{
		Edge now = pq.top();
		pq.pop();

		for (int i = 0; i < alis[now.num].size(); i++)
		{
			Edge next = alis[now.num][i];
			int nextCost = dist[now.num] + next.cost;

			if (dist[next.num] <= nextCost) continue;

			dist[next.num] = nextCost;
			pq.push({ next.num, nextCost });
		}
	}

}

int main()
{
	cin >> v >> e >> start;

	for (int i = 0; i < e; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		alis[from].push_back({ to, cost });
	}

	dijkstra(start);

	for (int i = 1; i <= v; i++)
	{
		if (dist[i] == 21e8) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
}