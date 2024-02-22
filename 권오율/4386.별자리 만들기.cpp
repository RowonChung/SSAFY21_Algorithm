#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct Edge {
  int a, b;
  float val;
};

bool compare(Edge &left, Edge &right) { return left.val < right.val; }

vector<Edge> lines;

struct Node {
  float row, col;
};

vector<Node> stars;
int arr[110];
int n;
int cnt;
float val;

int find(int tar) {
  if (tar == arr[tar])
    return tar;
  int ret = find(arr[tar]);
  arr[tar] = ret;
  return ret;
}

void setUnion(int a, int b) {
  int t1 = find(a);
  int t2 = find(b);
  if (t1 == t2)
    return;
  if (t1 < t2)
    arr[t2] = t1;
  else
    arr[t1] = t2;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    arr[i] = i;
    float row, col;
    cin >> row >> col;
    stars.push_back({row, col});
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (i == j)
        continue;
      float dr = stars[i].row - stars[j].row;
      float dc = stars[i].col - stars[j].col;
      float distance = sqrt((dr * dr) + (dc * dc));
      lines.push_back({i, j, distance});
    }
  }
  sort(lines.begin(), lines.end(), compare);

  for (Edge line : lines) {
    if (find(line.a) == find(line.b))
      continue;
    setUnion(line.a, line.b);
    val += line.val;
    cnt++;

    if (cnt == n - 1)
      break;
  }
  cout << fixed;
  cout.precision(2);
  cout << val;
}
