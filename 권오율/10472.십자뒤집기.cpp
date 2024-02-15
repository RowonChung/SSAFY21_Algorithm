#include <climits>
#include <iostream>
#include <vector>

using namespace std;

const int gridSize = 3;
const char black = '*';
const char white = '.';
const int dr[] = {0, 1, -1, 0, 0};
const int dc[] = {0, 0, 0, 1, -1};

const int INF = 1e9;

int cal(int row, int col, vector<vector<char>> &map) {
  int ans = INF;

  if (row == gridSize) {
    for (int i = 0; i < gridSize; ++i) {
      for (int j = 0; j < gridSize; ++j) {
        if (map[i][j] == black) {
          return INF;
        }
      }
    }
    return 0;
  }

  int next_row = row;
  int next_col = col + 1;
  if (next_col >= gridSize) {
    next_row = row + 1;
    next_col = 0;
  }

  ans = min(ans, cal(next_row, next_col, map));

  for (int k = 0; k < 5; ++k) {
    int nrow = row + dr[k];
    int ncol = col + dc[k];
    if (nrow >= 0 && nrow < gridSize && ncol >= 0 && ncol < gridSize) {
      if (map[nrow][ncol] == black) {
        map[nrow][ncol] = white;
      } else {
        map[nrow][ncol] = black;
      }
    }
  }

  ans = min(ans, cal(next_row, next_col, map) + 1);

  for (int k = 0; k < 5; ++k) {
    int nrow = row + dr[k];
    int ncol = col + dc[k];
    if (nrow >= 0 && nrow < gridSize && ncol >= 0 && ncol < gridSize) {
      if (map[nrow][ncol] == black) {
        map[nrow][ncol] = white;
      } else {
        map[nrow][ncol] = black;
      }
    }
  }

  return ans;
}

int main() {
  int test_cnt;
  cin >> test_cnt;

  for (int t = 0; t < test_cnt; ++t) {
    vector<vector<char>> map(gridSize, vector<char>(gridSize));
    for (int i = 0; i < gridSize; ++i) {
      for (int j = 0; j < gridSize; ++j) {
        cin >> map[i][j];
      }
    }

    int ans = cal(0, 0, map);

    cout << ans << "\n";
  }

  return 0;
}
