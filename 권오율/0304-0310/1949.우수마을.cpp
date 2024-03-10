#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int u, v;
vector<int> line[10010];
int arr[10010], dp[10010][2];
bool visited[10010];

void findParent(int x) {
  visited[x] = true;
  dp[x][1] = arr[x];

  for (int i = 0; i < line[x].size(); i++) {
    int child = line[x][i];
    if (visited[child]) continue;
    findParent(child);

    dp[x][1] += dp[child][0];
    dp[x][0] += max(dp[child][1], dp[child][0]);
  }
}

int main() {
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    line[u].push_back(v);
    line[v].push_back(u);
  }

  findParent(1);

  cout << max(dp[1][0], dp[1][1]);
}
