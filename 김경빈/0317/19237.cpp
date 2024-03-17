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

struct SHARKS {
    int y, x, direc;
};
int N, M, k, arr[21][21][2], direc[401][5][4], cnt;
int dy[] = { 0, -1, 1, 0, 0 }, dx[] = { 0, 0, 0, -1, 1 };
SHARKS sharks[401];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> k;
    cnt = M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j][0];
            if (arr[i][j][0]) {
                arr[i][j][1] = k;
                sharks[arr[i][j][0]].y = i;
                sharks[arr[i][j][0]].x = j;
            }
        }
    }
    for (int i = 1; i <= M; i++) {
        cin >> sharks[i].direc;
    }
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= 4; j++) {
            for (int k = 0; k < 4; k++) {
                cin >> direc[i][j][k];
            }
        }
    }

    int depth = 1;
    while (1) {
        SHARKS temp_sharks[401];
        for (int i = 1; i <= M; i++) {
            if (sharks[i].y == -1) continue;
            int noone[5][2], mine[5][2], other[5][2];
            memset(noone, -1, sizeof(noone));
            memset(mine, -1, sizeof(mine));
            memset(other, -1, sizeof(other));
            int nnum = 0, mnum = 0, onum = 0;

            for (int j = 1; j <= 4; j++) {
                int dr = sharks[i].y + dy[j];
                int dc = sharks[i].x + dx[j];

                if (dr < 0 || dr >= N || dc < 0 || dc >= N) continue;
                if ((arr[dr][dc][0] != 0 && arr[dr][dc][1] < depth) || arr[dr][dc][0] == 0) {
                    noone[j][0] = dr; noone[j][1] = dc;
                    nnum++;
                }
                else if (arr[dr][dc][0] == i && arr[dr][dc][1] >= depth) {
                    mine[j][0] = dr; mine[j][1] = dc;
                    mnum++;
                }
                else {
                    other[j][0] = dr; other[j][1] = dc;
                    onum++;
                }
            }

            if (nnum) {
                for (int x : direc[i][sharks[i].direc]) {
                    if (noone[x][0] == -1) continue;
                    temp_sharks[i].y = noone[x][0];
                    temp_sharks[i].x = noone[x][1];
                    temp_sharks[i].direc = x;
                    break;
                }
            }
            else if (mnum) {
                for (int x : direc[i][sharks[i].direc]) {
                    if (mine[x][0] == -1) continue;
                    temp_sharks[i].y = mine[x][0];
                    temp_sharks[i].x = mine[x][1];
                    temp_sharks[i].direc = x;
                    break;
                }
            }
            else {
                for (int x : direc[i][sharks[i].direc]) {
                    if (other[x][0] == -1) continue;
                    temp_sharks[i].y = other[x][0];
                    temp_sharks[i].x = other[x][1];
                    temp_sharks[i].direc = x;
                    break;
                }
            }
        }

        for (int i = 1; i <= M; i++) {
            if (sharks[i].y == -1) continue;
            if (arr[temp_sharks[i].y][temp_sharks[i].x][1] < depth + k) {
                arr[temp_sharks[i].y][temp_sharks[i].x][0] = i;
                arr[temp_sharks[i].y][temp_sharks[i].x][1] = depth + k;

                sharks[i].y = temp_sharks[i].y;
                sharks[i].x = temp_sharks[i].x;
                sharks[i].direc = temp_sharks[i].direc;
            }
            else {
                sharks[i].y = -1;
                cnt--;
            }
        }

        if (cnt == 1) {
            cout << depth;
            break;
        }
        if (depth == 1000) {
            cout << -1;
            break;
        }

        depth++;
    }
}