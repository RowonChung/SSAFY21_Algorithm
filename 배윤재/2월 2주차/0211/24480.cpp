#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, r;
vector<int> alis[100001];
int visited[100001];
int cnt = 1;

void dfs(int now)
{
	for (int i = 0; i < alis[now].size(); i++)
	{
		int next = alis[now][i];

		if (visited[next] != 0) continue;

		visited[next] = cnt++;
		dfs(next);
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
		if (alis[i].size() == 0) continue;
		sort(alis[i].begin(), alis[i].end(), greater<>());
	}


	visited[r] = cnt++;
	dfs(r);

	for (int i = 1; i <= n; i++)
	{
		cout << visited[i] << "\n";
	}

	return 0;
}