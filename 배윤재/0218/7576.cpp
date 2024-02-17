#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Locate {
	int y, x;
};

int m, n;
int box[1001][1001];

int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };

queue<Locate> q;

void input()
{
	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> box[i][j];
			if (box[i][j] == 1) q.push({ i, j });
		}
	}
}

void ripe()
{
	while (!q.empty())
	{
		Locate now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];

			if (ny < 0 || ny >= n|| nx < 0 || nx >= m) continue;
			if (box[ny][nx] == -1 || box[ny][nx] != 0) continue;

			box[ny][nx] = box[now.y][now.x] + 1;
			q.push({ ny, nx });
		}
	}


}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();

	ripe();

	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// 안 익은 토마토가 존재할 경우
			if (box[i][j] == 0)
			{
				cout << -1;
				return 0;
			}

			if (ans < box[i][j])
				ans = box[i][j];
		}
	}

	cout << ans - 1;

	return 0;
}