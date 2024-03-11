#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node { int wb, y, x; };
struct Point { int noB, yesB; };
int N, M;
string MAP[1000];
int visited[2][1000][1000];
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
int ans;

void bfs() {
    queue<Node> q;
    q.push({ 0,0,0 });
    visited[0][0][0] = 1;
    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = now.y + dr[i];
            int nx = now.x + dc[i];
            int nwb = now.wb;
            if (ny >= N || nx >= M || ny < 0 || nx < 0) continue;
            if (MAP[ny][nx] == '1') {
                nwb++;
                if (nwb > 1) continue;
                if (visited[nwb][ny][nx] != 0) continue;
                visited[nwb][ny][nx] = visited[now.wb][now.y][now.x] + 1;
                q.push({ nwb, ny, nx });
            }
            if (visited[nwb][ny][nx] != 0) continue;
            visited[nwb][ny][nx] = visited[now.wb][now.y][now.x] + 1;
            q.push({ nwb, ny, nx });
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        cin >> MAP[y];
    }
    bfs();
    if (visited[0][N - 1][M - 1] == 0) {
        if (visited[1][N - 1][M - 1] == 0) {
            ans = -1;
        }
        else {
            ans = visited[1][N - 1][M - 1];
        }
    }
    else {
        if (visited[1][N - 1][M - 1] == 0) {
            ans = visited[0][N - 1][M - 1];
        }
        else {
            ans = min(visited[0][N - 1][M - 1], visited[1][N - 1][M - 1]);
        }
    }

    cout << ans;

    return 0;
}