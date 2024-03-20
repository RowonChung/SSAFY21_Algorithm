#include <iostream>
#include <queue>

using namespace std;

int n, m, k;
int answer;

int diry[4] = { 0, 0, 1, -1 };
int dirx[4] = { 1, -1, 0, 0 };

bool visited[51][51] = { false, };
int Map[51][51];

void init()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
            Map[i][j] = 0;
        }
    }

    answer = 0;
}

void bfs(int y, int x)
{
    queue<pair<int, int>> que;

    que.push({ y, x });
    visited[y][x] = true;

    while (!que.empty())
    {
        pair<int, int> now = que.front();
        que.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = now.first + diry[i];
            int nx = now.second + dirx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (Map[ny][nx] == 0) continue;

            if (!visited[ny][nx])
            {
                que.push({ ny, nx });
                visited[ny][nx] = true;
            }
        }
    }
}

int main()
{
    int t;

    cin >> t;

    for (int T = 0; T < t; T++)
    {
        cin >> m >> n >> k;

        init();

        for (int j = 0; j < k; j++)
        {
            int y, x;
            cin >> x >> y;

            Map[y][x] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && Map[i][j] == 1)
                {
                    bfs(i, j);
                    answer++;
                }
            }
        }

        cout << answer << "\n";

    }
    return 0;
}