#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> COL[200001], ROW[200001];

int n, m, col, row, nextR, nextC;
int currC = 100000, currR = 100000;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> col >> row;
    ROW[row + 100000].push_back(col + 100000);
    COL[col + 100000].push_back(row + 100000);
  }

  for (int i = 0; i < 200001; i++) {
    if (!ROW[i].empty()) sort(ROW[i].begin(), ROW[i].end());
    if (!COL[i].empty()) sort(COL[i].begin(), COL[i].end());
  }

  char dir;
  for (int i = 0; i < m; i++) {
    cin >> dir;

    if (dir == 'U') {
      nextR = 200001;
      nextC = currC;
      for (int j = 0; j < COL[currC].size(); j++) {
        int newRow = COL[currC][j];
        if (newRow > currR) {
          nextR = newRow;
          break;
        }
      }

    } else if (dir == 'D') {
      nextR = 0;
      nextC = currC;
      for (int j = COL[currC].size() - 1; j >= 0; j--) {
        int newRow = COL[currC][j];
        if (newRow < currR) {
          nextR = newRow;
          break;
        }
      }

    } else if (dir == 'L') {
      nextR = currR;
      nextC = 0;
      for (int j = ROW[currR].size() - 1; j >= 0; j--) {
        int newCol = ROW[currR][j];
        if (newCol < currC) {
          nextC = newCol;
          break;
        }
      }

    } else if (dir == 'R') {
      nextR = currR;
      nextC = 200001;
      for (int j = 0; j < ROW[currR].size(); j++) {
        int newCol = ROW[currR][j];
        if (newCol > currC) {
          nextC = newCol;
          break;
        }
      }
    }
    currC = nextC;
    currR = nextR;
  }

  cout << currC - 100000 << " " << currR - 100000;
}
