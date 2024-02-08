#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int n, m;
int dp[100][10][1024] = {};
// 10 bit -> 0 ~ 1023
// 각 자리에 k 들어가면 이전 값에 | (1<<k) 연산
// 마지막에 1023인 곳만 다 더하기
void init()
{
	cin >> n;
	for (int i = 0; i < 10; i++)
		dp[0][i][1 << i] = 1;
}

int main() {
	init();
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j != 0 && j != 9)
			{
				for (int k = 0; k < 1024; k++)
				{
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % 1000000000;
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % 1000000000;
				}
			}
			else if (j == 0)
			{
				for (int k = 0; k < 1024; k++)
				{
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % 1000000000;
				}
			}
			else
			{
				for (int k = 0; k < 1024; k++)
				{
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % 1000000000;
				}
			}
		}
	}
	int result = 0;
	for (int i = 1; i < 10; i++)
		result = (result + dp[n-1][i][1023]) % 1000000000;

	cout << result;
}