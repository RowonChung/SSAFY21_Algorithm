#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <climits>
#include <unordered_map>\
using namespace std;

struct FISH {
    int y, x;

    bool operator<(FISH right) const{
        if (y > right.y) return true;
        if (y == right.y && x > right.x) return true;
        return false;
    }
};
int N, arr[21][21], sy, sx, sz = 2, cnt;
int dr, dc, dy[] = { -1, 1, 0, 0 }, dx[] = { 0, 0, -1, 1 };
queue<FISH> q;
priority_queue<FISH> fishes;
FISH qp;

void eatfish(int sec) {

    int visited[21][21];
    memset(visited, 0, sizeof(visited));
    visited[sy][sx] = 1;
    q.push({ sy, sx });
    
    int cycle = 0;
    while (!q.empty()) {
        int q_size = q.size();
        cycle++;
        for (int qs = 0; qs < q_size; qs++) {
            qp = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                dr = qp.y + dy[i];
                dc = qp.x + dx[i];

                if (dr < 0 || dr >= N || dc < 0 || dc >= N) continue;
                if (visited[dr][dc]) continue;
                if (arr[dr][dc] > sz) continue;
                if (arr[dr][dc] < sz && arr[dr][dc] > 0) {
                    fishes.push({ dr, dc });
                }
                else {
                    q.push({ dr, dc });
                }
                visited[dr][dc] = 1;
            }
        }
        if (fishes.size()) break;
    }

    if (fishes.size() == 0) {
        cout << sec;
        return;
    }
    auto fish = fishes.top();
    arr[fish.y][fish.x] = 0;
    cnt++;
    if (cnt == sz) {
        sz++;
        cnt = 0;
    }
    sy = fish.y; sx = fish.x;
    while (!q.empty()) q.pop();
    while (!fishes.empty()) fishes.pop();
    eatfish(sec + cycle);

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 9) {
                arr[i][j] = 0;
                sy = i;
                sx = j;
            }
        }
    }

    eatfish(0);
}