#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int n, m;
struct edge {
	int to, cost;
};
int dist[1001] = {};
vector<edge> edges[1001];
bool operator<(edge l, edge r) {
	if (l.cost < r.cost)
		return false;
	if (l.cost > r.cost)
		return true;
	if (l.to < r.to)
		return false;
	if (l.to > r.to)
		return true;
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		dist[i] = 21e7;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({ b,c });
	}
	int s, e;
	cin >> s >> e;
	dist[s] = 0;
	priority_queue<edge> pq;
	pq.push({ s,0 });
	bool used[1001] = {};
	while (!pq.empty())
	{
		int nowpos = pq.top().to;
		int nowcost = pq.top().cost;
		pq.pop();
		if (used[nowpos])
			continue;
		used[nowpos] = true;
		for (int i = 0; i < edges[nowpos].size(); i++)
		{
			int nextpos = edges[nowpos][i].to;
			int nextcost = edges[nowpos][i].cost + nowcost;
			if (dist[nextpos] <= nextcost)
				continue;
			dist[nextpos] = nextcost;
			pq.push({ nextpos,nextcost });
		}
	}
	cout << dist[e];
}