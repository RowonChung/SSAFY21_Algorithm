#include <iostream>
#include <queue>

using namespace std;

struct Position {
    int y;
    int x;
    int cnt;
    int dir;
};

//      0 세로 1 가로
int n, gdir;

// 0 길  // 1 장애물    // 2 통나무    // 3 목적지
int Map[51][51];
//          좌표      방향
bool visited[51][51][2] = { false, };

int diry[4] = { 0, 0, 1, -1 };
int dirx[4] = { 1, -1, 0, 0 };

void print(int y, int x)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == y && j == x) cout << 2 << " ";
            else cout << Map[i][j] << " ";
        }
        cout << endl;
    }
}

int bfs(int y, int x, int dir)
{
    queue<Position> que;
    visited[y][x][dir] = true;
    que.push({ y, x, 0, dir});

    while (!que.empty())
    {
        Position now = que.front();
        que.pop();

        //print(now.y, now.x);
        //cout << endl;

        if (Map[now.y][now.x] == 3) // now.dir == gdir)
        {
            //cout << now.dir << " " << gdir << endl;
            //cout << "결과값: " << now.cnt << endl;
            return now.cnt;
        }

        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + diry[i];
            int nx = now.x + dirx[i];
            int ncnt = now.cnt + 1;

            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if (Map[ny][nx] == 1) continue;

            if (now.dir == 0)
            {
                if (ny - 1 < 0 || ny + 1 >= n) continue;
                if (Map[ny - 1][nx] == 1 || Map[ny + 1][nx] == 1) continue;
            }
            else
            {
                if (nx - 1 < 0 || nx + 1 >= n) continue;
                if (Map[ny][nx - 1] == 1 || Map[ny][nx + 1] == 1) continue;
            }

            if (!visited[ny][nx][now.dir])
            {
                visited[ny][nx][now.dir] = true;
                que.push({ ny, nx, ncnt, now.dir });
            }
        }

        // 턴
        bool turn = true;
        for (int i = now.y - 1; i <= now.y + 1; i++)
        {
            for (int j = now.x - 1; j <= now.x + 1; j++)
            {

                if (i < 0 || j < 0 || i >= n || j >= n)
                {
                    turn = false;
                    break;
                }

                if (Map[i][j] == 1)
                {
                    turn = false;
                    break;
                }
            }
            if (!turn) break;
        }

        if (turn)
        {
            if (!visited[now.y][now.x][(now.dir + 1) % 2])
            {
                visited[now.y][now.x][(now.dir + 1) % 2] = true;
                que.push({ now.y, now.x, now.cnt + 1, (now.dir + 1) % 2 });
            }
        }
    }

    return 0;
}

int main() {

    int y, x, dir;

    cin >> n;

    int tcnt = 0, gcnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char input;
            cin >> input;

            if (input == 'B')
            {
                Map[i][j] = 2;
                tcnt++;
                if (tcnt == 2)
                {
                    if (j - 1 >= 0 && Map[i][j - 1] == 2) dir = 1;
                    else dir = 0;

                    y = i;
                    x = j;
                }
            }
            else if (input == 'E')
            {
                gcnt++;
                if (gcnt == 1) Map[i][j] = 3;
                if (gcnt == 2)
                {
                    if (j - 1 >= 0 && Map[i][j - 1] == 3)
                    {
                        Map[i][j - 1] = 0;
                        gdir = 1;
                    }
                    else
                    {
                        Map[i - 1][j] = 0;
                        gdir = 0;
                    }
                    Map[i][j] = 3;
                }
            }
            else
            {
                Map[i][j] = input - '0';
            }
        }
    }

    cout << bfs(y, x, dir);


    return 0;
}