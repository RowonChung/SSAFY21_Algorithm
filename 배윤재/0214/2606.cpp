#include <iostream>
#include <vector>
using namespace std;

int coms, lines;
vector<int> v[101];
int visited[101];
int cnt = 0;

void dfs(int node)
{
	for (int i = 0; i < v[node].size(); i++)
	{
		int next = v[node][i];
		if (visited[next] == 1) continue;

		visited[next] = 1;
		cnt++;

		dfs(next);
	}
}


int main()
{
	cin >> coms >> lines;

	for (int i = 0; i < lines; i++)
	{
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	visited[1] = 1;
	dfs(1);

	cout << cnt;

	return 0;
}