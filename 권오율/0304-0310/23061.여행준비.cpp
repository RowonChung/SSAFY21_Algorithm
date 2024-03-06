#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int n, m, ans, maxi = 0;
int weight[110];
int val[110];
int bag[110];
int dp[1000100];
pair<ll, ll> temp1;
pair<ll, ll> temp2;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> weight[i] >> val[i];
  for (int i = 1; i <= m; i++) {
    cin >> bag[i];
    maxi = max(bag[i], maxi);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = maxi; j >= 0; j--) {
      if (j < weight[i]) break;
      dp[j] = max(dp[j], dp[j - weight[i]] + val[i]);
    }
  }
  ans = 1;
  for (int i = 2; i <= m; i++) {
    temp1 = {bag[ans], dp[bag[ans]]};
    temp2 = {bag[i], dp[bag[i]]};
    if (temp1.second * temp2.first < temp1.first * temp2.second) {
      ans = i;
    }
  }
  cout << ans;
}
