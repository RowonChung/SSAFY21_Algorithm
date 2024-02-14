#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int a = 0, b = 1, c = 2;

int cnt[3], len;
char ans[100], s[100];
bool dp[51][51][51][3][3];

bool dfs(int a_count, int b_count, int c_count, int prev[2]) {
  if (a_count == cnt[a] && b_count == cnt[b] && c_count == cnt[c]) {
    cout << ans << "\n";
    exit(0);
  }

  if (dp[a_count][b_count][c_count][prev[0]][prev[1]]) {
    return false;
  }

  dp[a_count][b_count][c_count][prev[0]][prev[1]] = true;

  if (a_count + 1 <= cnt[a]) {
    ans[a_count + b_count + c_count] = 'A';
    if (dfs(a_count + 1, b_count, c_count, new int[]{prev[1], a})) {
      return true;
    }
  }
  if (b_count + 1 <= cnt[b]) {
    ans[a_count + b_count + c_count] = 'B';
    if (prev[1] != b) {
      if (dfs(a_count, b_count + 1, c_count, new int[]{prev[1], b})) {
        return true;
      }
    }
  }
  if (c_count + 1 <= cnt[c]) {
    ans[a_count + b_count + c_count] = 'C';
    if (prev[0] != c && prev[1] != c) {
      if (dfs(a_count, b_count, c_count + 1, new int[]{prev[1], c})) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  cin >> s;
  len = strlen(s);
  for (int i = 0; i < 3; ++i) {
    cnt[i] = count(s, s + len, 'A' + i);
  }
  dfs(0, 0, 0, new int[]{0, 0});
  cout << -1 << "\n";
  return 0;
}
