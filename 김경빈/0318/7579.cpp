#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <climits>
#include <unordered_map>
using namespace std;

int N, c[101], dp[10001], sum, M, m[101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> m[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> c[i];
        sum += c[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int s = sum; s >= 0; s--) {
            if (s >= c[i]) dp[s] = max(dp[s], dp[s - c[i]] + m[i]);
            else break;
        }
    }

    for (int s = 0; s <= sum; s++) {
        if (dp[s] < M) continue;
        cout << s;
        break;
    }
}