#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int T, n, m;
int map[9][9];

// 상하좌우 우상우하좌하좌상
int dr[8] = { -1, 1, 0, 0, -1, 1, 1, -1 };
int dc[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };

int flag = 0;
int black = 0;
int white = 0;

void init()
{
	memset(map, 0, sizeof(map));
	black = 0;
	white = 0;
}

void input()
{
	cin >> n >> m;

	int center = n / 2;

	// 가운데 백돌
	map[center][center] = 2;
	map[center + 1][center + 1] = 2;

	// 가운데 흑돌
	map[center][center + 1] = 1;
	map[center + 1][center] = 1;
}

void dfs(int sy, int sx, int dol, int d)
{
	if (map[sy][sx] == 0) return;
	if (map[sy][sx] == dol)
	{
		flag = 1;
		return;
	}

	int tmp = map[sy][sx];

	map[sy][sx] = dol;
	dfs(sy + dr[d], sx + dc[d], dol, d);

	if (flag == 0) map[sy][sx] = tmp;
}

void solve()
{
	for (int i = 0; i < m; i++)
	{
		int y, x, dol;
		cin >> y >> x >> dol;

		map[y][x] = dol;
		for (int d = 0; d < 8; d++)
		{
			int ny = y + dr[d];
			int nx = x + dc[d];

			if (ny <= 0 || ny > n || nx <= 0 || nx > n) continue;

			// 돌이 없거나 같으면 넘어가기
			if (map[ny][nx] == 0 || map[ny][nx] == dol) continue;

			flag = 0;
			dfs(ny, nx, dol, d);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] == 0) continue;
			else if (map[i][j] == 1) black++;
			else if (map[i][j] == 2) white++;
		}
	}
}

int main()
{
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		init();
		input();

		solve();

		cout << "#" << tc << " " << black << " " << white << "\n";

	}
	return 0;
}
