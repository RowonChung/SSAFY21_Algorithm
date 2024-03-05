#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

struct Node {
	int y, x;
};

int T, N;
string mat[301];
int check[301][301];
int visited[301][301];

int dy[8] = { -1, 1, 0, 0, -1, 1, 1, -1 };
int dx[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };

int clickBomb = 0;
int bomb = 0;
int minClick = 0;

void init()
{
	for (int i = 0; i < N; i++)
	{
		mat[i] = "";
	}

	memset(check, -1, sizeof(check));
	memset(visited, 0, sizeof(visited));

	bomb = 0;
	minClick = 0;
}

void input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> mat[i];
	}
}

int countBomb(int sy, int sx)
{
	bomb = 0;

	for (int i = 0; i < 8; i++)
	{
		int ny = sy + dy[i];
		int nx = sx + dx[i];
		
		if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
		if (mat[ny][nx] == '*') bomb++;
	}

	check[sy][sx] = bomb;

	return bomb;
}

void search(int sy, int sx)
{
	queue<Node> q;
	
	q.push({ sy, sx });

	while (!q.empty())
	{
		Node now = q.front();
		q.pop();

		visited[now.y][now.x] = 1;

		for (int i = 0; i < 8; i++)
		{
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if (visited[ny][nx] == 1) continue;

			visited[ny][nx] = 1;

			if (countBomb(ny, nx) == 0)
			{
				q.push({ ny, nx });
			}
		}

		check[now.y][now.x] = clickBomb;
	}

}

void solve()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (mat[i][j] == '.' && visited[i][j] == 0)
			{
				if (countBomb(i, j) == 0)
				{
					check[i][j] = 0;
					visited[i][j] = 1;
					minClick++;
					search(i, j);
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (check[i][j] != -1 && visited[i][j] == 0)
				minClick++;
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
		
		cout << "#" << tc << " " << minClick << "\n";
	}

}