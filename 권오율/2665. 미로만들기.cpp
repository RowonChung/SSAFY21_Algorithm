#include <iostream>
#include <queue>
using namespace std;

struct Node {
  int row, col, val;
  bool operator<(const Node &right) const {
    if (val < right.val)
      return false;
    if (val > right.val)
      return true;
    return false;
  }
};

priority_queue<Node> q;

int n, arr[53][53], wall[53][53];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

void bfs() {
  wall[0][0] = 0;
  q.push({0, 0, 0});
  while (!q.empty()) {
    Node now = q.top();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nextR = now.row + dr[i];
      int nextC = now.col + dc[i];
      if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= n)
        continue;
      int is_wall = 1 - arr[nextR][nextC];
      if (wall[nextR][nextC] <= wall[now.row][now.col] + is_wall)
        continue;
      wall[nextR][nextC] = wall[now.row][now.col] + is_wall;
      q.push({nextR, nextC, wall[nextR][nextC]});
    }
  }
}

int main() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    string input;
    cin >> input;
    for (int j = 0; j < n; j++) {
      arr[i][j] = input[j] - '0';
      wall[i][j] = 1e9;
    }
  }
  bfs();

  cout << wall[n - 1][n - 1];
}
