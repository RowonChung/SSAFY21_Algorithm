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

struct SWAN {
    int y, x;
};
int R, C, arr[1501][1501], visited[1501][1501], day;
int dy[] = { -1, 1, 0, 0 }, dx[] = { 0, 0, -1, 1 };
char space;
vector<SWAN> v;
queue<SWAN> q, ice, swan;

bool day0() {
    int sy1 = v[0].y, sx1 = v[0].x, sy2 = v[1].y, sx2 = v[1].x;
    q.push({ sy1, sx1 });
    visited[sy1][sx1] = 1;

    while (!q.empty()) {
        SWAN qp = q.front();
        q.pop();
        if (qp.y == sy2 && qp.x == sx2) return true;

        for (int i = 0; i < 4; i++) {
            int dr = qp.y + dy[i];
            int dc = qp.x + dx[i];

            if (dr < 0 || dr >= R || dc < 0 || dc >= C) continue;
            if (visited[dr][dc]) continue;

            if (arr[dr][dc] == INT_MAX) {
                visited[dr][dc] = 1;
                swan.push({ dr, dc });
            }
            else {
                visited[dr][dc] = 1;
                q.push({ dr, dc });
            }
        }
    }

    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j] != day) continue;

            q.push({ i, j });
            visited[i][j] = 1;

            while (!q.empty()) {
                SWAN qp = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int dr = qp.y + dy[d];
                    int dc = qp.x + dx[d];

                    if (dr < 0 || dr >= R || dc < 0 || dc >= C) continue;
                    if (visited[dr][dc] || (arr[dr][dc] != day && arr[dr][dc] != INT_MAX)) continue;

                    if (arr[dr][dc] == INT_MAX) {
                        visited[dr][dc] = 1;
                        arr[dr][dc] = day + 1;
                        ice.push({ dr, dc });
                    }
                    else {
                        visited[dr][dc] = 1;
                        q.push({ dr, dc });
                    }
                }
            }
        }
    }
    return false;
}

void melt() {
    int q_size = ice.size();
    for (int qs = 0; qs < q_size; qs++) {
        SWAN qp = ice.front();
        ice.pop();

        for (int i = 0; i < 4; i++) {
            int dr = qp.y + dy[i];
            int dc = qp.x + dx[i];

            if (dr < 0 || dr >= R || dc < 0 || dc >= C) continue;
            if (arr[dr][dc] != INT_MAX) continue;
            
            arr[dr][dc] = day + 1;
            ice.push({ dr, dc });
        }
    }
}

bool ismeet() {
    int sy1 = v[0].y, sx1 = v[0].x, sy2 = v[1].y, sx2 = v[1].x;
    int q_size = swan.size();

    for (int qs = 0; qs < q_size; qs++) {
        SWAN qp = swan.front();
        swan.pop();

        if (qp.y == sy2 && qp.x == sx2) return true;

        for (int i = 0; i < 4; i++) {
            int dr = qp.y + dy[i];
            int dc = qp.x + dx[i];

            if (dr < 0 || dr >= R || dc < 0 || dc >= C) continue;
            if (visited[dr][dc]) continue;

            if (arr[dr][dc] == INT_MAX) {
                visited[dr][dc] = 1;
                swan.push({ dr, dc });
            }
            else {
                visited[dr][dc] = 1;
                q.push({ dr, dc });
            }
        }
    }

    while (!q.empty()) {
        SWAN qp = q.front();
        q.pop();

        if (qp.y == sy2 && qp.x == sx2) return true;

        for (int i = 0; i < 4; i++) {
            int dr = qp.y + dy[i];
            int dc = qp.x + dx[i];

            if (dr < 0 || dr >= R || dc < 0 || dc >= C) continue;
            if (visited[dr][dc]) continue;

            if (arr[dr][dc] == INT_MAX) {
                visited[dr][dc] = 1;
                swan.push({ dr, dc });
            }
            else {
                visited[dr][dc] = 1;
                q.push({ dr, dc });
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> space;
            if (space == 'L') v.push_back({ i, j });
            if (space == 'X') arr[i][j] = INT_MAX;
        }
    }

    if (!day0()) {
        day++;

        memset(visited, 0, sizeof(visited));
        while (!ismeet()) {
            melt();
            day++;
        }
    }
    
    cout << day;
}