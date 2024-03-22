#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 2134567890;

int N, K;
int dong[100];
int dp[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> dong[i];
	}
	sort(dong, dong + N);
	dp[0] = 1;
	for (int x = 1; x <= K; x++) {
		if (x % dong[0] == 0) {
			dp[x] = 1;
		}
	}
	for (int y = 1; y < N; y++) {
		for (int x = 1; x <= K; x++) {
			if (x < dong[y]) {
				continue;
			}
			else {
				dp[x] = dp[x] + dp[x - dong[y]];
			}
		}
	}
	cout << dp[K];

	int de = -1;
	return 0;
}