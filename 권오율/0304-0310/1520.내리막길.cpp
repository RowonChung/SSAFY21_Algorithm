#include <iostream>
using namespace std;

int n, m;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int arr[505][505];
int dp[505][505];

int dfs(int row, int col) {
  if (row == n - 1 && col == m - 1) {
    return 1;
  }
  int &ret = dp[row][col];
  if (ret != -1) {
    return ret;
  }

  ret = 0;
  for (int i = 0; i < 4; i++) {
    int nextR = row + dr[i];
    int nextC = col + dc[i];

    if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= m) {
      continue;
    }
    if (arr[nextR][nextC] >= arr[row][col]) {
      continue;
    }

    ret += dfs(nextR, nextC);
  }

  return ret;
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      dp[i][j] = -1;
    }
  }

  cout << dfs(0, 0);
}
