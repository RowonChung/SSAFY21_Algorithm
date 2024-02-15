#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, v;
vector<int> alis[1001];
int visited[1001];

void dfs(int now)
{
	cout << now << " ";

	visited[now] = 1;

	for (int i = 0; i < alis[now].size(); i++)
	{
		int next = alis[now][i];
		if (visited[next] == 1) continue;

		dfs(next);
	}
}

void bfs(int start)
{
	queue<int> q;

	q.push(start);
	visited[start] = 1;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		cout << now << " ";

		for (int i = 0; i < alis[now].size(); i++)
		{
			int next = alis[now][i];
			if (visited[next] == 1) continue;

			visited[next] = 1;
			q.push(next);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> n >> m >> v;

	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;
		alis[from].push_back(to);
		alis[to].push_back(from);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(alis[i].begin(), alis[i].end());
	}

	dfs(v);

	memset(visited, 0, sizeof(visited));
	cout << "\n";

	bfs(v);

	return 0;
}