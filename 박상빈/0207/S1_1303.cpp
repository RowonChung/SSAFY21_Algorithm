#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 동 남 서 북 대각선
int dirx[8] = { 1, 0, -1, 0, -1, -1, 1, 1 };
int diry[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };

int n, m;
int Map[101][101];
bool visited[101][101] = { false, };
int Wanswer = 0;
int Banswer = 0;

int BFS(int y, int x)
{
    int size = 0;
    int type = Map[y][x];

    queue<pair<int, int>> q;

    q.push({ y, x });
    visited[y][x] = true;

    while(!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();

        // 병사 수 카운트
        size++;

        // 대각선 제외
        for(int i=0;i<4;i++)
        {
            int ny = now.first + diry[i];
            int nx = now.second + dirx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (Map[ny][nx] != type) continue;

            if (!visited[ny][nx])
            {
                visited[ny][nx] = true;

                q.push({ ny, nx });
            }
        }
    }

    return size;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    // n^2의 위력

    // B 의 붙어있는 병사들 => n^2 + n`^2 ...
    // W 의 붙어있는 병사들 => n^2 + n`^2 ...

    cin >> m >> n;

    for(int i=0;i<n;i++)
    {
	    for(int j=0;j<m;j++)
	    {
            char input;
            cin >> input;

            if (input == 'W') Map[i][j] = 1;
            else Map[i][j] = 0;
	    }
    }

    for(int i=0;i<n;i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j]) continue;

            int result = BFS(i, j);
            if (Map[i][j] == 1) Wanswer += (result * result);
            else if (Map[i][j] == 0) Banswer += (result * result);
        }
    }

    cout << Wanswer << " " << Banswer ;

    return 0;
}