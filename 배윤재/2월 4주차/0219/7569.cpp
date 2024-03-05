#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int h, y, x;
};

int m, n, h;
int box[101][101][101];
queue<Node> q;

// 위, 아래, 상하좌우
int dir[6][3] = { {-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1} };

int minDay = 0;

void input()
{
	cin >> m >> n >> h;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> box[i][j][k];
			}
		}
	}
}

void bfs()
{
	while (!q.empty())
	{
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nh = now.h + dir[i][0];
			int ny = now.y + dir[i][1];
			int nx = now.x + dir[i][2];

			if (nh < 0 || nh >= h || ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (box[nh][ny][nx] == -1 || box[nh][ny][nx] != 0) continue;

			box[nh][ny][nx] = box[now.h][now.y][now.x] + 1;
			q.push({ nh, ny, nx });
		}
	}
}

void ripe()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (box[i][j][k] == 0)
				{
					minDay = -1;
					return;
				}

				if (minDay < box[i][j][k]) minDay = box[i][j][k] - 1;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();

	int flag = 0;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (box[i][j][k] == 0)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1) break;
		}
		if (flag == 1) break;
	}

	if (flag == 0)
	{
		cout << 0;
		return 0;
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (box[i][j][k] == 1)
				{
					q.push({ i, j, k });
				}
			}
		}
	}

	bfs();
	ripe();

	cout << minDay;

	return 0;
}