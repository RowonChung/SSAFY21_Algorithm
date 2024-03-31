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

int N, M, arr[50][50], di, si, bomb[4];
int d[] = { 0, 7, 3, 1, 5 }, dy[] = { 0, 1, 0, -1 }, dx[] = { -1, 0, 1, 0 };
queue<int> q, temp;

void change_q() {
    int y = N / 2, x = N / 2, dist = 0;
    for (int i = 0; i < 2 * N - 1; i++) {
        if (i % 4 % 2 == 0 && i != 2 * N - 2) dist++;

        for (int j = 1; j <= dist; j++) {
            y = y + dy[i % 4];
            x = x + dx[i % 4];
            if (arr[y][x] == 0) return;
            q.push(arr[y][x]);
            arr[y][x] = 0;
        }
    }
}

void fall_ice() {
    int q_size = q.size();
    int ice = d[di], next = d[di] + 8;
    int cnt = 0;

    for (int qs = 1; qs <= q_size; qs++) {
        int qp = q.front();
        q.pop();
        if (qs == ice && cnt < si) {
            ice += next;
            next += 8;
            cnt++;
            continue;
        }

        q.push(qp);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    change_q();

    for (int i = 0; i < M; i++) {
        cin >> di >> si;

        fall_ice();

        bool isbomb = true;

        while (isbomb) {
            isbomb = false;
            int q_size = q.size();
            int now = 0, cnt = 0;

            for (int qs = 1; qs <= q_size; qs++) {
                int qp = q.front();
                q.pop();

                if (now != qp) {
                    if (cnt < 4) {
                        for (int c = 0; c < cnt; c++) {
                            q.push(now);
                        }
                    }
                    else {
                        bomb[now] += cnt;
                        isbomb = true;
                    }
                    now = qp;
                    cnt = 1;
                }
                else if (now == qp) {
                    cnt++;
                }
            }
            if (cnt < 4) {
                for (int c = 0; c < cnt; c++) {
                    q.push(now);
                }
            }
            else {
                bomb[now] += cnt;
                isbomb = true;
            }
        }

        int qs = q.size();
        if (qs == 0) break;

        int idx = 1;
        int now = 0, cnt = 0;
       
        while (!q.empty()) {
            int qp = q.front();
            q.pop();

            if (now != qp) {
                temp.push(cnt);
                temp.push(now);
                now = qp;
                cnt = 1;
            }
            else if (now == qp) {
                cnt++;
            }
        }
        temp.push(cnt);
        temp.push(now);
        temp.pop();
        temp.pop();

        while (!temp.empty() && idx < N * N) {
            q.push(temp.front());
            temp.pop();
            idx++;
        }
        while (!temp.empty()) temp.pop();
    }

    cout << bomb[1] + 2 * bomb[2] + 3 * bomb[3];
}