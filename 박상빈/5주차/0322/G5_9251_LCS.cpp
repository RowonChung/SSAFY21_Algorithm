#include <iostream>
#include <queue>

using namespace std;

string arr1, arr2;
int dp[1001][1001];

int main() {

    int answer = -21e8;
    cin >> arr1 >> arr2;

    for (int i = 1; i <= arr1.length(); i++)
    {
        for (int j = 1; j <= arr2.length(); j++)
        {
            if (i == 0 || j == 0) dp[i][j] == 0;
            else if (arr1[i - 1] == arr2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

            answer = max(dp[i][j], answer);
        }
    }

    cout << answer;

    return 0;
}