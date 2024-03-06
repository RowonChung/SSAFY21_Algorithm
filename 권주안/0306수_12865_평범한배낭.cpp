#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int W[101], V[101];
int dp[101][100001];

int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> W[i] >> V[i];
    }
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= K; x++) {
            if (x - W[y] < 0) {
                dp[y][x] = dp[y - 1][x];
            }
            else {
                dp[y][x] = max(dp[y - 1][x], dp[y - 1][x - W[y]] + V[y]);
            }
        }
    }
    cout << dp[N][K];

    return 0;
}