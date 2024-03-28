#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

struct Position {
    int y;
    int x;
};

int n, m, answer = -21e8;
int Map[9][9];
vector<Position> virus;

int diry[4] = { 0, 0, 1, -1 };
int dirx[4] = { 1, -1, 0, 0 };

void bfs()
{
    bool visited[9][9] = { false, };
    queue<Position> que;

    for (int i = 0; i < virus.size(); i++)
    {
        visited[virus[i].y][virus[i].x] = true;
        que.push({ virus[i].y, virus[i].x });
    }

    while (!que.empty())
    {
        Position now = que.front();
        que.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + diry[i];
            int nx = now.x + dirx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (!visited[ny][nx] && Map[ny][nx] == 0)
            {
                visited[ny][nx] = true;
                que.push({ ny, nx });
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && Map[i][j] == 0) cnt++;
        }
    }

    answer = max(answer, cnt);
}

void dfs(int y, int x, int depth)
{
    if (depth == 3)
    {
        // 바이러스 퍼트리고
        // 안전영역 검사
        bfs();

        return;
    }

    for (int j = x; j < m; j++)
    {
        if (Map[y][j] == 0)
        {
            Map[y][j] = 1;
            dfs(y, x + 1, depth + 1);
            Map[y][j] = 0;
        }
    }

    for (int i = y + 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (Map[i][j] == 0)
            {
                Map[i][j] = 1;
                dfs(y, x + 1, depth + 1);
                Map[i][j] = 0;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> Map[i][j];
            if (Map[i][j] == 2) virus.push_back({ i, j });
        }
    }
       
    dfs(0, 0, 0);

    cout << answer;


    return 0;
}