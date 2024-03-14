#include <iostream>
#include <queue>

using namespace std;

int n, maxi;
int Map[101][101];
bool visited[101][101] = { false, };

int diry[4] = { 0, 0, 1, -1 };
int dirx[4] = { 1, -1, 0, 0 };

void init()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			visited[i][j] = false;
		}
	}
}

void bfs(int y, int x, int day)
{
	queue<pair<int, int>> que;

	visited[y][x] = true;
	que.push({ y, x });

	while (!que.empty())
	{
		pair<int, int> now = que.front();
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = now.first + diry[i];
			int nx = now.second + dirx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (Map[ny][nx] <= day) continue;

			if (!visited[ny][nx])
			{
				visited[ny][nx] = true;
				que.push({ ny, nx });
			}
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;

		maxi = -21e8;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> Map[i][j];
				maxi = max(maxi, Map[i][j]);
			}
		}

		int answer = 1;

		for (int day = 1; day <= maxi; day++)
		{
			init();

			int cnt = 0;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (!visited[i][j] && Map[i][j] > day)
					{
						bfs(i, j, day);
						cnt++;
					}
				}
			}
			answer = max(answer, cnt);
		}

		cout << "#" << test_case << " " << answer << "\n";
		

	}
	return 0;
}