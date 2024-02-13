#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct Swap {
  int n, cnt;
};

queue<Swap> q;

const int MAX_N = 1000100;
const int MAX_M = 100;

vector<vector<bool>> used(MAX_M,
                          vector<bool>(MAX_N, false)); // Changed to vector

int n, m, cnt, maxi = -1;

void bfs(int start, int m) {
  q.push({start, 0});

  while (!q.empty()) {
    Swap now = q.front();
    q.pop();

    int nowNum = now.n;
    int nowCnt = now.cnt;

    if (nowCnt == cnt) {
      maxi = max(maxi, nowNum);
      continue;
    }

    string now_str = to_string(nowNum);

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
        if (i == j)
          continue;

        string swapped = now_str;
        swap(swapped[i], swapped[j]);

        if (swapped[0] != '0') {
          int next = stoi(swapped);
          if (!used[nowCnt + 1][next]) {
            used[nowCnt + 1][next] = true;
            q.push({next, nowCnt + 1});
          }
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> cnt;
  m = to_string(n).length();
  used[0][n] = true;
  bfs(n, m);

  cout << maxi;
}
