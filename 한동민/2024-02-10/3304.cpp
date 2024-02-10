#include <iostream>
using namespace std;

int dp[1001][1001];

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		string s1, s2;
		cin >> s1 >> s2;
		for (int i = 1; i <= s1.size(); i++) {
			for (int j = 1; j <= s2.size(); j++) {
				if (s1[i - 1] == s2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		cout << "#" << test_case << " " << dp[s1.size()][s2.size()] << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
