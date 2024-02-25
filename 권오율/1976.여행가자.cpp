#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> parents;

int find(int x) {
  if (x == parents[x])
    return x;
  int rx = find(parents[x]);
  parents[x] = rx;
  return rx;
}

void setUnion(int x, int y) {
  x = find(x);
  y = find(y);

  if (x < y) {
    parents[y] = x;
  } else {
    parents[x] = y;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  parents.resize(n + 1);

  for (int i = 1; i <= n; i++) {
    parents[i] = i;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int num;
      cin >> num;
      if (num == 1) {
        setUnion(i, j);
      }
    }
  }

  int root;
  cin >> root;
  root = find(root);

  for (int i = 0; i < m - 1; i++) {
    int num;
    cin >> num;
    if (root != find(num)) {
      cout << "NO";
      return 0;
    }
  }

  cout << "YES";
}
