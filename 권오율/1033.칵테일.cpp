#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define pp pair<int, int>

using namespace std;

int n;
long long dp[15];
vector<pair<int, pp>> graph[15];

void dfs(int x, int parent) {
  for (auto neighbor : graph[x]) {
    if (neighbor.first == parent) {
      continue;
    }
    dp[neighbor.first] = (dp[x] * (long long)neighbor.second.second) /
                         (long long)neighbor.second.first;
    dfs(neighbor.first, x);
  }
}

long long gcd(long long a, long long b) {
  while (b != 0) {
    long long temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  long long lcm = 1;
  for (int i = 0; i < n - 1; i++) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    graph[a].push_back({b, {c, d}});
    graph[b].push_back({a, {d, c}});

    lcm *= (c * d / gcd(c, d));
  }

  dp[0] = lcm;

  dfs(0, -1);

  long long global = dp[0];
  for (int i = 1; i < n; i++) {
    if (dp[i] == 0)
      continue;
    global = gcd(global, dp[i]);
  }

  for (int i = 0; i < n; i++)
    cout << dp[i] / global << " ";
}
