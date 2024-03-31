#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Position {
    int y;
    int x;
};

int r, c, t;

// 시계방향
// 북 동 남 서
int diry[4] = { -1, 0, 1, 0 };
int dirx[4] = { 0, 1, 0, -1 };
int Map[51][51];
Position aircon[2];

void print()
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << Map[i][j] << " ";
        }
        cout << endl;
    }
}

void up()
{
    Position now = aircon[0];

    // 위에거 아래로
    for (int i = 0; i < 4; i++)
    {
        for(int j=0;;j++)
        {
           int ny = now.y + diry[i];
           int nx = now.x + dirx[i];

           if (ny < 0 || nx < 0 || ny >= r || nx >= c) break;

           // now 의 위치에다가 ny nx 의 값을 담을 것
           Map[now.y][now.x] = Map[ny][nx];
           now = { ny, nx };

           if (i != 3 && ny == aircon[0].y) break;
        }
        Map[aircon[0].y][aircon[0].x] = 0;
    }
}

void down()
{
    Position now = aircon[1];

    // 아래거
    for (int i = 2; i >= 0; i--)
    {
        for (int j = 0;; j++)
        {
            int ny = now.y + diry[i];
            int nx = now.x + dirx[i];

            if (ny < 0 || nx < 0 || ny >= r || nx >= c) break;

            // now 의 위치에다가 ny nx 의 값을 담을 것
            Map[now.y][now.x] = Map[ny][nx];
            now = { ny, nx };

            if (i != 3 && ny == aircon[1].y) break;
        }
        Map[aircon[1].y][aircon[1].x] = 0;
    }

    for (int j = 0;; j++)
    {
        int ny = now.y + diry[3];
        int nx = now.x + dirx[3];

        if (ny < 0 || nx < 0 || ny >= r || nx >= c) break;

        // now 의 위치에다가 ny nx 의 값을 담을 것
        Map[now.y][now.x] = Map[ny][nx];
        now = { ny, nx };
    }
}

void spread()
{
    int tmp[51][51] = { 0, };
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (Map[i][j] == 0) continue;
            // i, j 를 기준으로 사방으로 퍼질 것
            int cnt = 0;
            for (int idx = 0; idx < 4; idx++)
            {
                int ny = i + diry[idx];
                int nx = j + dirx[idx];

                if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
                bool flag = false;
                for (int i = 0; i < 2; i++)
                {
                    if (ny == aircon[i].y && nx == aircon[i].x) flag = true;
                }
                if (flag) continue;

                tmp[ny][nx] += (Map[i][j] / 5);
                cnt += (Map[i][j] / 5);
            }
            tmp[i][j] -= cnt;
        }
    }

    // 퍼트려 ~
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == aircon[0].y && j == aircon[0].x) continue;
            if (i == aircon[1].y && j == aircon[1].x) continue;

            Map[i][j] += tmp[i][j];
            if (Map[i][j] < 0) Map[i][j] = 0;
        }
    }
}

int main()
{
    cin >> r >> c >> t;

    int idx = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> Map[i][j];
            if (Map[i][j] == -1)
            {
                aircon[idx++] = { i, j };
                Map[i][j] = 0;
            }
        }
    }

    int time = 0;
    while (time < t)
    {
        // 미세먼지 확산
        spread();
        
        up();

        down();

        for (int i = 0; i < 2; i++)
        {
            Map[aircon[i].y][aircon[i].x] = 0;
        }

        time++;
    }

    int answer = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (Map[i][j] == 0) continue;
            answer += Map[i][j];
        }
    }

    cout << answer;

    return 0;
}