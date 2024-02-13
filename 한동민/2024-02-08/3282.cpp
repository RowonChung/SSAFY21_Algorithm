#include <iostream>
using namespace std;

int n, k;

struct jewel {
	int weight;
	int value;
};

int dp[101][1001];
jewel item[101];


int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			int weight, value;
			cin >> weight >> value;
			item[i] = { weight, value };
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++) {
				dp[i][j] = dp[i-1][j];
				if (item[i].weight <= j) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j - item[i].weight] + item[i].value);
				}
			}
		}
		cout << "#" << test_case << " ";
		cout << dp[n][k] << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
