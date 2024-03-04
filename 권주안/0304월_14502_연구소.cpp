#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

struct Node { int y, x; };
Node wall[3];
int N, M;
int MAP[8][8];
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
queue<Node> q;

void bfs() {
    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = now.y + dr[i];
            int nx = now.x + dc[i];
            if (ny >= N || nx >= M || ny < 0 || nx < 0) continue;
            if (MAP[ny][nx] != 0) continue;
            MAP[ny][nx] = 2;
            q.push({ ny,nx });
        }
    }
}

int main() {
    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> MAP[y][x];
        }
    }
    int temp[8][8];
    int ans = 0;
    memcpy(temp, MAP, sizeof(MAP));
    for (int y1 = 0; y1 < N; y1++) {
        for (int x1 = 0; x1 < M; x1++) {
            if (MAP[y1][x1] == 1) continue;
            if (MAP[y1][x1] == 2) continue;
            for (int y2 = 0; y2 < N; y2++) {
                for (int x2 = 0; x2 < M; x2++) {
                    if (MAP[y2][x2] == 1) continue;
                    if (MAP[y2][x2] == 2) continue;
                    if (y1 == y2 && x1 == x2) continue;
                    for (int y3 = 0; y3 < N; y3++) {
                        for (int x3 = 0; x3 < M; x3++) {
                            if (MAP[y3][x3] == 1) continue;
                            if (MAP[y3][x3] == 2) continue;
                            if (y1 == y3 && x1 == x3) continue;
                            if (y2 == y3 && x2 == x3) continue;
                            wall[0] = { y1,x1 };
                            wall[1] = { y2,x2 };
                            wall[2] = { y3,x3 };
                            for (int i = 0; i < 3; i++) {
                                MAP[wall[i].y][wall[i].x] = 1;
                            }
                            for (int y = 0; y < N; y++) {
                                for (int x = 0; x < M; x++) {
                                    if (MAP[y][x] == 2) {
                                        q.push({ y,x });
                                    }
                                }
                            }
                            bfs();
                            int cnt = 0;
                            for (int y = 0; y < N; y++) {
                                for (int x = 0; x < M; x++) {
                                    if (MAP[y][x] == 0) {
                                        cnt++;
                                    }
                                }
                            }
                            ans = max(ans, cnt);
                            memcpy(MAP, temp, sizeof(temp));
                        }
                    }
                }
            }
        }
    }
    cout << ans;

    return 0;
}