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

struct SHARK {
    int r, c, s, d, z;
};
int R, C, M, d, arr[101][101], ans;
int dy[] = { -1, 1, 0, 0 }, dx[] = { 0, 0, 1, -1 };
SHARK shark[100001];

void fishing(int loc) {
    for (int i = 1; i <= R; i++) {
        if (arr[i][loc]) {
            ans += shark[arr[i][loc]].z;
            shark[arr[i][loc]].s = -1;
            arr[i][loc] = 0;
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> M;
    for (int i = 1; i <= M; i++) {
        cin >> shark[i].r >> shark[i].c >> shark[i].s >> d >> shark[i].z;
        shark[i].d = d - 1;
        arr[shark[i].r][shark[i].c] = i;
    }

    for (int c = 1; c <= C; c++) {
        fishing(c);
        memset(arr, 0, sizeof(arr));
        for (int i = 1; i <= M; i++) {
            if (shark[i].s == -1) continue;

            int dr = shark[i].r + dy[shark[i].d] * shark[i].s;
            int dc = shark[i].c + dx[shark[i].d] * shark[i].s;

            if (dr > R) {
                dr %= 2 * (R - 1);
                if (dr >= R) {
                    dr = 2 * R - dr;
                    shark[i].d ^= 1;
                }
                else if (dr <= 1) {
                    dr = 2 - dr;
                    shark[i].d ^= 1;
                }
            }
            else if (dr <= 0) {
                dr %= 2 * (R - 1);
                if (abs(dr) < R - 1) {
                    dr = abs(dr) + 2;
                    shark[i].d ^= 1;
                }
                else {
                    dr += 2 * (R - 1);
                }
            }
            else if (dc > C) {
                dc %= 2 * (C - 1);
                if (dc >= C) {
                    dc = 2 * C - dc;
                    shark[i].d ^= 1;
                }
                else if (dc <= 1) {
                    dc = 2 - dc;
                    shark[i].d ^= 1;
                }
            }
            else if (dc <= 0) {
                dc %= 2 * (C - 1);
                if (abs(dc) < C - 1) {
                    dc = abs(dc) + 2;
                    shark[i].d ^= 1;
                }
                else {
                    dc += 2 * (C - 1);
                }
            }

            if (arr[dr][dc]) {
                if (shark[arr[dr][dc]].z > shark[i].z) {
                    shark[i].s = -1;
                }
                else {
                    shark[arr[dr][dc]].s = -1;
                    arr[dr][dc] = i;
                }
            }
            else {
                arr[dr][dc] = i;
            }
            shark[i].r = dr;
            shark[i].c = dc;
        }
    }

    cout << ans;
}