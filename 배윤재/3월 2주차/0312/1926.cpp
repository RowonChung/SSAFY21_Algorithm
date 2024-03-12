#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int y, x;
};

int n, m;
int mat[501][501];
int visited[501][501];
int maxArea = 0;
int cntArea = 0;

int num = 0;

int dir[4][2] = { 1, 0, -1, 0, 0, -1, 0, 1 };

void bfs(int sy, int sx)
{
	num++;

	queue<Node> q;

	q.push({ sy, sx });
	visited[sy][sx] = num;

	while (!q.empty())
	{
		Node now = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (visited[ny][nx] != 0) continue;
			if (mat[ny][nx] == 0) continue;

			visited[ny][nx] = num;
			cntArea++;

			q.push({ ny, nx });
		}
	}


	maxArea = max(maxArea, cntArea);

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> mat[i][j];
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mat[i][j] == 0) continue;
			if (visited[i][j] != 0) continue;
			cntArea = 1;
			bfs(i, j);
		}
	}

	cout << num << "\n" << maxArea;
}