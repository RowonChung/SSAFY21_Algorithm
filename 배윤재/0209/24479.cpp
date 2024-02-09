#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
	int n, m, r;
	cin >> n >> m >> r;

	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;
		alis[from].push_back(to);
		alis[to].push_back(from);
	}

	// Á¤·Ä
	for (int i = 0; i < n; i++)
	{
		if (alis[i].size() == 0) continue;

		sort(alis[i].begin(), alis[i].end());
	}

	visited[r] = cnt++;
	dfs(r);

	for (int i = 1; i <= n; i++)
	{
		cout << visited[i] << "\n";
	}

	return 0;
}