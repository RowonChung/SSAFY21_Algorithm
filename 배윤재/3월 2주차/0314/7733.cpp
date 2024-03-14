#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Node {
    int y, x, taste;

    bool operator<(Node right) const {
        return taste > right.taste;
    }
};

int T, N;
int cheese[101][101];
bool check[101][101];
bool visited[101][101];
priority_queue<Node> pq;

int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
int maxCnt = 0;

void input()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> cheese[i][j];
            pq.push({ i, j, cheese[i][j] });
        }
    }
}

void bfs(int sy, int sx, int num)
{
    queue<Node> q;

    q.push({ sy, sx, num });
    visited[sy][sx] = true;

    while (!q.empty())
    {
        Node now = q.front();
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int ny = now.y + dir[d][0];
            int nx = now.x + dir[d][1];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if (check[ny][nx] == true) continue;
            if (visited[ny][nx] == true) continue;

            visited[ny][nx] = true;
            q.push({ ny, nx, num });
        }
    }
}

int findCnt()
{
    memset(visited, false, sizeof(visited));

    int num = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (cheese[i][j] == 0) continue;
            if (check[i][j] == true) continue;
            if (visited[i][j] == true) continue;

            bfs(i, j, ++num);
        }
    }
    return num;
}

void solve()
{
    int day = 0;

    while (!pq.empty())
    {
        if (pq.top().taste > day)
        {
            maxCnt = max(maxCnt, findCnt());
            day++;
            continue;
        }

        Node now = pq.top();
        if (now.taste == day)
        {
            cheese[now.y][now.x] = 0;
            check[now.y][now.x] = true;

            pq.pop();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        maxCnt = 0;
        memset(check, false, sizeof(check));

        input();
        solve();

        cout << "#" << tc << " " << maxCnt << "\n";
    }
}