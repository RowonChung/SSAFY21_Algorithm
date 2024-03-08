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

struct CCTV {
    int num, y, x;
};
int N, M, arr[10][10], cctv_num, wall, ans = INT_MAX;
int dy[] = { -1, 0, 1, 0 }, dx[] = { 0, -1, 0, 1 };
vector<CCTV> cctv;

void DFS(int depth, int area) {
    if (depth == cctv_num) {
        ans = min(ans, area);
        return;
    }

    CCTV ncctv = cctv[depth];

    if (ncctv.num == 1) {
        for (int i = 0; i < 4; i++) {
            int go = 1, cnt = 0;
            while (1) {
                int dr = ncctv.y + dy[i] * go;
                int dc = ncctv.x + dx[i] * go;
                if (dr < 0 || dr >= N || dc < 0 || dc >= M) break;
                if (arr[dr][dc] == 6) break;
                if (arr[dr][dc] == 0) cnt++;
                if(arr[dr][dc] <= 0) arr[dr][dc] -= ncctv.num;
                go++;
            }
            DFS(depth + 1, area - cnt);
            go = 1;
            while (1) {
                int dr = ncctv.y + dy[i] * go;
                int dc = ncctv.x + dx[i] * go;
                if (dr < 0 || dr >= N || dc < 0 || dc >= M) break;
                if (arr[dr][dc] == 6) break;
                if (arr[dr][dc] < 0) arr[dr][dc] += ncctv.num;
                go++;
            }
        }
    }
    else if (ncctv.num == 2) {
        for (int i = 0; i < 2; i++) {
            int go = 1, cnt = 0;
            while (1) {
                int dr = ncctv.y + dy[i] * go;
                int dc = ncctv.x + dx[i] * go;
                if (dr < 0 || dr >= N || dc < 0 || dc >= M) break;
                if (arr[dr][dc] == 6) break;
                if (arr[dr][dc] == 0) cnt++;
                if (arr[dr][dc] <= 0)arr[dr][dc] -= ncctv.num;
                go++;
            }
            go = 1;
            while (1) {
                int dr = ncctv.y + dy[i+2] * go;
                int dc = ncctv.x + dx[i+2] * go;
                if (dr < 0 || dr >= N || dc < 0 || dc >= M) break;
                if (arr[dr][dc] == 6) break;
                if (arr[dr][dc] == 0) cnt++;
                if (arr[dr][dc] <= 0)arr[dr][dc] -= ncctv.num;
                go++;
            }
            DFS(depth + 1, area - cnt);
            go = 1;
            while (1) {
                int dr = ncctv.y + dy[i] * go;
                int dc = ncctv.x + dx[i] * go;
                if (dr < 0 || dr >= N || dc < 0 || dc >= M) break;
                if (arr[dr][dc] == 6) break;
                if (arr[dr][dc] < 0) arr[dr][dc] += ncctv.num;
                go++;
            }
            go = 1;
            while (1) {
                int dr = ncctv.y + dy[i + 2] * go;
                int dc = ncctv.x + dx[i + 2] * go;
                if (dr < 0 || dr >= N || dc < 0 || dc >= M) break;
                if (arr[dr][dc] == 6) break;
                if (arr[dr][dc] < 0) arr[dr][dc] += ncctv.num;
                go++;
            }
        }
    }
    else if (ncctv.num == 3) {
        for (int i = 0; i < 4; i++) {
            int go = 1, cnt = 0;
            while (1) {
                int dr = ncctv.y + dy[i] * go;
                int dc = ncctv.x + dx[i] * go;
                if (dr < 0 || dr >= N || dc < 0 || dc >= M) break;
                if (arr[dr][dc] == 6) break;
                if (arr[dr][dc] == 0) cnt++;
                if (arr[dr][dc] <= 0)arr[dr][dc] -= ncctv.num;
                go++;
            }
            go = 1;
            while (1) {
                int dr = ncctv.y + dy[(i + 1) % 4] * go;
                int dc = ncctv.x + dx[(i + 1) % 4] * go;
                if (dr < 0 || dr >= N || dc < 0 || dc >= M) break;
                if (arr[dr][dc] == 6) break;
                if (arr[dr][dc] == 0) cnt++;
                if (arr[dr][dc] <= 0)arr[dr][dc] -= ncctv.num;
                go++;
            }
            DFS(depth + 1, area - cnt);
            go = 1;
            while (1) {
                int dr = ncctv.y + dy[i] * go;
                int dc = ncctv.x + dx[i] * go;
                if (dr < 0 || dr >= N || dc < 0 || dc >= M) break;
                if (arr[dr][dc] == 6) break;
                if (arr[dr][dc] < 0) arr[dr][dc] += ncctv.num;
                go++;
            }
            go = 1;
            while (1) {
                int dr = ncctv.y + dy[(i + 1) % 4] * go;
                int dc = ncctv.x + dx[(i + 1) % 4] * go;
                if (dr < 0 || dr >= N || dc < 0 || dc >= M) break;
                if (arr[dr][dc] == 6) break;
                if (arr[dr][dc] < 0) arr[dr][dc] += ncctv.num;
                go++;
            }
        }
    }
    else if (ncctv.num == 4) {
        for (int i = 0; i < 4; i++) {
            int go = 1, cnt = 0;
            while (1) {
                int dr = ncctv.y + dy[i] * go;
                int dc = ncctv.x + dx[i] * go;
                if (dr < 0 || dr >= N || dc < 0 || dc >= M) break;
                if (arr[dr][dc] == 6) break;
                if (arr[dr][dc] == 0) cnt++;
                if (arr[dr][dc] <= 0)arr[dr][dc] -= ncctv.num;
                go++;
            }
            go = 1;
            while (1) {
                int dr = ncctv.y + dy[(i + 1) % 4] * go;
                int dc = ncctv.x + dx[(i + 1) % 4] * go;
                if (dr < 0 || dr >= N || dc < 0 || dc >= M) break;
                if (arr[dr][dc] == 6) break;
                if (arr[dr][dc] == 0) cnt++;
                if (arr[dr][dc] <= 0)arr[dr][dc] -= ncctv.num;
                go++;
            }
            go = 1;
            while (1) {
                int dr = ncctv.y + dy[(i + 2) % 4] * go;
                int dc = ncctv.x + dx[(i + 2) % 4] * go;
                if (dr < 0 || dr >= N || dc < 0 || dc >= M) break;
                if (arr[dr][dc] == 6) break;
                if (arr[dr][dc] == 0) cnt++;
                if (arr[dr][dc] <= 0)arr[dr][dc] -= ncctv.num;
                go++;
            }
            DFS(depth + 1, area - cnt);
            go = 1;
            while (1) {
                int dr = ncctv.y + dy[i] * go;
                int dc = ncctv.x + dx[i] * go;
                if (dr < 0 || dr >= N || dc < 0 || dc >= M) break;
                if (arr[dr][dc] == 6) break;
                if (arr[dr][dc] < 0) arr[dr][dc] += ncctv.num;
                go++;
            }
            go = 1;
            while (1) {
                int dr = ncctv.y + dy[(i+1)%4] * go;
                int dc = ncctv.x + dx[(i+1)%4] * go;
                if (dr < 0 || dr >= N || dc < 0 || dc >= M) break;
                if (arr[dr][dc] == 6) break;
                if (arr[dr][dc] < 0) arr[dr][dc] += ncctv.num;
                go++;
            }
            go = 1;
            while (1) {
                int dr = ncctv.y + dy[(i+2)%4] * go;
                int dc = ncctv.x + dx[(i+2)%4] * go;
                if (dr < 0 || dr >= N || dc < 0 || dc >= M) break;
                if (arr[dr][dc] == 6) break;
                if (arr[dr][dc] < 0) arr[dr][dc] += ncctv.num;
                go++;
            }
        }
    }
    else if (ncctv.num == 5) {
        int go = 1, cnt = 0;
        while (1) {
            int dr = ncctv.y + dy[0] * go;
            int dc = ncctv.x + dx[0] * go;
            if (dr < 0 || dr >= N || dc < 0 || dc >= M) break;
            if (arr[dr][dc] == 6) break;
            if (arr[dr][dc] == 0) cnt++;
            if (arr[dr][dc] <= 0)arr[dr][dc] -= ncctv.num;
            go++;
        }
        go = 1;
        while (1) {
            int dr = ncctv.y + dy[1] * go;
            int dc = ncctv.x + dx[1] * go;
            if (dr < 0 || dr >= N || dc < 0 || dc >= M) break;
            if (arr[dr][dc] == 6) break;
            if (arr[dr][dc] == 0) cnt++;
            if (arr[dr][dc] <= 0)arr[dr][dc] -= ncctv.num;
            go++;
        }
        go = 1;
        while (1) {
            int dr = ncctv.y + dy[2] * go;
            int dc = ncctv.x + dx[2] * go;
            if (dr < 0 || dr >= N || dc < 0 || dc >= M) break;
            if (arr[dr][dc] == 6) break;
            if (arr[dr][dc] == 0) cnt++;
            if (arr[dr][dc] <= 0)arr[dr][dc] -= ncctv.num;
            go++;
        }
        go = 1;
        while (1) {
            int dr = ncctv.y + dy[3] * go;
            int dc = ncctv.x + dx[3] * go;
            if (dr < 0 || dr >= N || dc < 0 || dc >= M) break;
            if (arr[dr][dc] == 6) break;
            if (arr[dr][dc] == 0) cnt++;
            if (arr[dr][dc] <= 0)arr[dr][dc] -= ncctv.num;
            go++;
        }
        DFS(depth + 1, area - cnt);
        go = 1;
        while (1) {
            int dr = ncctv.y + dy[0] * go;
            int dc = ncctv.x + dx[0] * go;
            if (dr < 0 || dr >= N || dc < 0 || dc >= M) break;
            if (arr[dr][dc] == 6) break;
            if (arr[dr][dc] < 0) arr[dr][dc] += ncctv.num;
            go++;
        }
        go = 1;
        while (1) {
            int dr = ncctv.y + dy[1] * go;
            int dc = ncctv.x + dx[1] * go;
            if (dr < 0 || dr >= N || dc < 0 || dc >= M) break;
            if (arr[dr][dc] == 6) break;
            if (arr[dr][dc] < 0) arr[dr][dc] += ncctv.num;
            go++;
        }
        go = 1;
        while (1) {
            int dr = ncctv.y + dy[2] * go;
            int dc = ncctv.x + dx[2] * go;
            if (dr < 0 || dr >= N || dc < 0 || dc >= M) break;
            if (arr[dr][dc] == 6) break;
            if (arr[dr][dc] < 0) arr[dr][dc] += ncctv.num;
            go++;
        }
        go = 1;
        while (1) {
            int dr = ncctv.y + dy[3] * go;
            int dc = ncctv.x + dx[3] * go;
            if (dr < 0 || dr >= N || dc < 0 || dc >= M) break;
            if (arr[dr][dc] == 6) break;
            if(arr[dr][dc] < 0) arr[dr][dc] += ncctv.num;
            go++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j]) wall++;
            if (arr[i][j] >= 1 && arr[i][j] <= 5) {
                cctv.push_back({ arr[i][j], i, j });
                cctv_num++;
            }
        }
    }
    DFS(0, N * M - wall);
    cout << ans;
}