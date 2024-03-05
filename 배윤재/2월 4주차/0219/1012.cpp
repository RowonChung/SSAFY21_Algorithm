#define _CRT_SECURE_NO_WARNINGS
#include <iostream>=
#include <queue>
#include <cstring>
using namespace std;

struct Node {
	int y, x;
};

int T;
int N, M, K;
int X, Y;
int map[51][51];
int visited[51][51];
int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };

int minWorm;

void init()
{
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));

	minWorm = 1e9;
}

void input()
{
	cin >> N >> M >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> X >> Y;
		map[X][Y] = 1;
	}
}

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

			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (map[ny][nx] == 0) continue;
			if (visited[ny][nx] == 1) continue;

			visited[ny][nx] = 1;
			map[ny][nx] = map[now.y][now.x] + 1;
			q.push({ ny, nx });
		}
	}
}

int findMinWorm()
{
	int sumWorm = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == 1) sumWorm++;

	if (minWorm > sumWorm) minWorm = sumWorm;

	return minWorm;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		init();
		input();

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (visited[i][j] == 0 && map[i][j] == 1)
					bfs(i, j);

		cout << findMinWorm() << "\n";
	}

	return 0;
}