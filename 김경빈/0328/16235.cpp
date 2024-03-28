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

int N, M, K, A[11][11], add[11][11], die[11][11], x, y, z, ans;
int dr, dc, dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 }, dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
vector<int> v[11][11];

void spring() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (v[i][j].size() == 0) continue;
            sort(v[i][j].begin(), v[i][j].end());

            for (int k = 0; k < v[i][j].size(); k++) {
                if (v[i][j][k] > A[i][j]) {
                    int idx = v[i][j].size() - 1;
                    while (idx >= k) {
                        die[i][j] += v[i][j][idx] / 2;
                        v[i][j].pop_back();
                        ans--;
                        idx--;
                    }
                }
                else {
                    A[i][j] -= v[i][j][k];
                    v[i][j][k]++;
                }
            }
        }
    }
}

void summer() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (die[i][j] == 0) continue;
            A[i][j] += die[i][j];
            die[i][j] = 0;
        }
    }
}

void fall() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k < v[i][j].size(); k++) {
                if (v[i][j][k] % 5) continue;

                for (int d = 0; d < 8; d++) {
                    dr = i + dy[d];
                    dc = j + dx[d];
                    
                    if (dr <= 0 || dr > N || dc <= 0 || dc > N) continue;

                    v[dr][dc].push_back(1);
                    ans++;
                }
            }
        }
    }
}

void winter() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            A[i][j] += add[i][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    ans = M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> add[i][j];
            A[i][j] = 5;
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> z;
        v[x][y].push_back(z);
    }

    for (int i = 0; i < K; i++) {
        spring();
        summer();
        fall();
        winter();
    }

    cout << ans;
}