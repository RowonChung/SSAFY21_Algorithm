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

struct CHESS {
    int y, x, d, loc;
};
int N, K, arr[13][13], y, x, d;
int dy[] = { 0, 0, -1, 1 }, dx[] = { 1, -1, 0, 0 };
CHESS chess[11];
vector<int> v[13][13];

void white(int num, int r, int c, int dr, int dc) {
    int temp = chess[num].loc;
    for (int i = temp; i < v[r][c].size(); i++) {
        chess[v[r][c][i]].y = dr;
        chess[v[r][c][i]].x = dc;
        chess[v[r][c][i]].loc = v[dr][dc].size();
        v[dr][dc].push_back(v[r][c][i]);
    }
    while (v[r][c].size() > temp) v[r][c].pop_back();
}

void red(int num, int r, int c, int dr, int dc) {
    int temp = chess[num].loc;
    while (v[r][c].size() > temp) {
        int temp_chess = v[r][c].back();
        v[dr][dc].push_back(temp_chess);
        chess[temp_chess].y = dr;
        chess[temp_chess].x = dc;
        chess[temp_chess].loc = v[dr][dc].size() - 1;
        v[r][c].pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= K; i++) {
        cin >> y >> x >> d;
        chess[i] = { y, x, d - 1, 0 };
        v[y][x].push_back(i);
    }

    int cnt = 1;
    while (cnt <= 1000) {
        for (int i = 1; i <= K; i++) {
            int dr = chess[i].y + dy[chess[i].d];
            int dc = chess[i].x + dx[chess[i].d];

            if (dr <= 0 || dr > N || dc <= 0 || dc > N) {
                chess[i].d ^= 1;
                dr = chess[i].y + dy[chess[i].d];
                dc = chess[i].x + dx[chess[i].d];
            }
            else if (arr[dr][dc] == 2) {
                chess[i].d ^= 1;
                dr = chess[i].y + dy[chess[i].d];
                dc = chess[i].x + dx[chess[i].d];
            }

            if (dr <= 0 || dr > N || dc <= 0 || dc > N) continue;
            if (arr[dr][dc] == 0) {
                white(i, chess[i].y, chess[i].x, dr, dc);
            }
            else if (arr[dr][dc] == 1) {
                red(i, chess[i].y, chess[i].x, dr, dc);
            }

            if (v[dr][dc].size() >= 4) {
                cout << cnt << '\n';
                exit(0);
            }
        }

        cnt++;
    }

    cout << "-1\n";
}