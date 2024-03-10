#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <climits>
#include <unordered_map>
using namespace std;

int a, b, arr[4][4][2], fishes[17][2], ans;
int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 }, dx[] = { 0, -1, -1, -1, 0, 1, 1, 1 };

void DFS(int eat, int arr[][4][2], int fishes[][2], int sy, int sx) {

    int new_arr[4][4][2], new_fishes[17][2];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 2; k++) {
                new_arr[i][j][k] = arr[i][j][k];
            }
        }
    }
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 2; j++) {
            new_fishes[i][j] = fishes[i][j];
        }
    }

    for (int i = 1; i <= 16; i++) {
        if (new_fishes[i][0] == -1) continue;

        int ny = new_fishes[i][0], nx = new_fishes[i][1];
        for (int d = 0; d < 8; d++) {
            int dr = ny + dy[(new_arr[ny][nx][1] + d) % 8];
            int dc = nx + dx[(new_arr[ny][nx][1] + d) % 8];

            if (dr < 0 || dr >= 4 || dc < 0 || dc >= 4) continue;
            if (dr == sy && dc == sx) continue;

            int temp_fish = new_arr[ny][nx][0];
            int temp_direc = (new_arr[ny][nx][1] + d) % 8;
            new_arr[ny][nx][0] = new_arr[dr][dc][0];
            new_arr[dr][dc][0] = temp_fish;
            new_arr[ny][nx][1] = new_arr[dr][dc][1];
            new_arr[dr][dc][1] = temp_direc;

            new_fishes[new_arr[dr][dc][0]][0] = dr;
            new_fishes[new_arr[dr][dc][0]][1] = dc;
            new_fishes[new_arr[ny][nx][0]][0] = ny;
            new_fishes[new_arr[ny][nx][0]][1] = nx;

            break;
        }
    }

    for (int i = 1; i < 4; i++) {
        int dr = sy + dy[new_arr[sy][sx][1]] * i;
        int dc = sx + dx[new_arr[sy][sx][1]] * i;

        if (dr < 0 || dr >= 4 || dc < 0 || dc >= 4) break;
        if (new_arr[dr][dc][0] == 0) continue;
        int fnum = new_arr[dr][dc][0];
        new_arr[dr][dc][0] = 0;
        new_fishes[fnum][0] = -1;
        DFS(eat + fnum, new_arr, new_fishes, dr, dc);
        new_arr[dr][dc][0] = fnum;
        new_fishes[fnum][0] = dr;
    }

    ans = max(ans, eat);
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> a >> b;
            arr[i][j][0] = a;
            arr[i][j][1] = b - 1;

            fishes[a][0] = i;
            fishes[a][1] = j;
        }
    }

    int fnum = arr[0][0][0];
    fishes[arr[0][0][0]][0] = -1;
    arr[0][0][0] = 0;
    
    DFS(fnum, arr, fishes, 0, 0);
    cout << ans;
}