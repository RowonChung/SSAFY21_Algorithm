#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Node {
	int y, x;
};

int n;
string map[25];
int visited[25][25];
priority_queue<int, vector<int>, greater<int>> homes;

int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };
int num = 0;
int cnt = 0;

void bfs(int sy, int sx)
{
	queue<Node> q;

	q.push({ sy, sx });
	visited[sy][sx] = 1;

	while (!q.empty())
	{
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if (visited[ny][nx] == 1) continue;
			if (map[now.y][now.x] != map[ny][nx]) continue;

			visited[ny][nx] = 1;
			cnt++;
			q.push({ ny, nx });
		}
	}

	homes.push(cnt);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == '0') continue;
			if (visited[i][j] == 1) continue;

			num++;
			cnt = 1;
			bfs(i, j);
		}
	}

	cout << num << "\n";

	for (int i = 0; i < num; i++)
	{
		int home = homes.top();
		homes.pop();
		cout << home << "\n";
	}

	return 0;
}