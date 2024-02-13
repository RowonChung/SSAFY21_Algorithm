#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, r;
vector<int> alis[100001];
int visited[100001];
int cnt = 1;

void bfs(int start)
{
	queue<int> q;

	q.push(start);

	while (!q.empty())
	{

		int now = q.front();
		q.pop();

		for (int i = 0; i < alis[now].size(); i++)
		{
			int next = alis[now][i];

			if (visited[next] != 0) continue;

			visited[next] = cnt++;
			q.push(next);

		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> r;

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

	visited[r] = cnt++;
	bfs(r);

	for (int i = 1; i <= n; i++)
	{
		cout << visited[i] << "\n";
	}

	return 0;
}