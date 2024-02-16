#include <iostream>
#include <queue>

using namespace std;

int limitA, limitB, limitC;
bool check[220][220];
priority_queue<int, vector<int>, greater<int>> answer;

void dfs(int a, int b, int c) {
  if (check[a][b])
    return;

  if (a == 0) {
    answer.push(c);
  }
  check[a][b] = true;

  if (a + b > limitB) {
    dfs((a + b) - limitB, limitB, c);
  } else {
    dfs(0, a + b, c);
  }

  if (a + b > limitA) {
    dfs(limitA, a + b - limitA, c);
  } else {
    dfs(a + b, 0, c);
  }

  if (a + c > limitA) {
    dfs(limitA, b, a + c - limitA);
  } else {
    dfs(a + c, b, 0);
  }

  if (b + c > limitB) {
    dfs(a, limitB, b + c - limitB);
  } else {
    dfs(a, b + c, 0);
  }

  dfs(a, 0, b + c);
  dfs(0, b, a + c);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> limitA >> limitB >> limitC;

  dfs(0, 0, limitC);

  while (!answer.empty()) {
    cout << answer.top() << " ";
    answer.pop();
  }

  return 0;
}
