#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

string s1, s2;
int dp[1001][1001];

string LCS(int i, int j) {
	if (i == 0 || j == 0) return "";
	else if (s1[i-1] == s2[j-1]) return LCS(i - 1, j - 1) + s1[i-1];

	if (dp[i][j - 1] > dp[i - 1][j]) return LCS(i, j - 1);
	else return LCS(i - 1, j);
}

int main() {
	ios::sync_with_stdio;
	cin.tie(0);

	cin >> s1 >> s2;
	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}

	cout << dp[s1.size()][s2.size()] << '\n';
	cout << LCS(s1.size(), s2.size());
}