#include <algorithm>
#include <iostream>
using namespace std;

int c, n;

int knapsack(int arr[][2], int c, int n) {
  int dp[1100];
  fill(dp, dp + 1100, 100100);
  dp[0] = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < 1100; ++j) {
      if (j - arr[i][1] >= 0) {
        dp[j] = min(dp[j], dp[j - arr[i][1]] + arr[i][0]);
      }
    }
  }

  int ans = dp[c];

  for (int i = c + 1; i < 1100; ++i) {
    ans = min(ans, dp[i]);
  }

  return ans;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> c >> n;

  int arr[n][2];

  for (int i = 0; i < n; ++i) {
    int cost, val;
    cin >> cost >> val;
    arr[i][0] = cost;
    arr[i][1] = val;
  }

  cout << knapsack(arr, c, n);
}
