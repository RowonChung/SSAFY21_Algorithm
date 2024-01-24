#include <iostream>
#define endl "\n"
using namespace std;

int C, N, cost[21], customer[21], dp[1001], temp, idx;

int main() {
	cin >> C >> N;
	for (int i = 0; i < N; i++) {
		cin >> cost[i] >> customer[i];
	}

	dp[0] = 0;
	for (int i = 0; i < N; i++) {
		idx = customer[i];
		if (idx > C) idx = C;
		if (dp[idx] == 0 || dp[idx] > cost[i]) {
			dp[idx] = cost[i];
		}
		for (int j = 0; j <= C; j++) {
			if (dp[j] == 0) continue;
			idx = j + customer[i];
			if (idx > C) idx = C;
			temp = dp[j] + cost[i];
			if (dp[idx] == 0 || dp[idx] > temp) {
				dp[idx] = temp;
			}
		}
		for (int i = 0; i <= C; i++) {
			cout << dp[i] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i <= C; i++) {
		cout << dp[i] << " ";
	}
	cout << endl;

	cout << dp[C] << endl;
}