#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Node { int y, x; };
int N, M;
char board[20][20];
int visited[26];
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
int ans = 0;
int cnt = 1;

void dfs(int nowY, int nowX) {
    ans = max(ans, cnt);
    for (int i = 0; i < 4; i++) {
        int ny = nowY + dr[i];
        int nx = nowX + dc[i];
        if (ny >= N || nx >= M || ny < 0 || nx < 0) continue;
        int next = board[ny][nx] - 'A';
        if (visited[next] == 1) continue;
        visited[next] = 1;
        cnt++;
        dfs(ny, nx);
        visited[next] = 0;
        cnt--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> board[y][x];
        }
    }
    visited[board[0][0] - 'A'] = 1;
    dfs(0, 0);
    cout << ans << "\n";

    return 0;
}