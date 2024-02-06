#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[110][80];
bool used[110][80];

bool mount;

vector<int> dr = {-1, 1, 0, 0, 1, 1, -1, -1};
vector<int> dc = {0, 0, -1, 1, 1, -1, 1, -1};

void DFS(int row, int col) {
  for (int i = 0; i < 8; i++) {
    int nrow = row + dr[i];
    int ncol = col + dc[i];

    if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m)
      continue;

    if (arr[row][col] < arr[nrow][ncol])
      mount = false;

    if (used[nrow][ncol] || arr[row][col] != arr[nrow][ncol])
      continue;

    used[nrow][ncol] = true;
    DFS(nrow, ncol);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  int cnt = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!used[i][j]) {
        mount = true;
        used[i][j] = true;
        DFS(i, j);
        if (mount)
          cnt += 1;
      }
    }
  }

  cout << cnt;
}