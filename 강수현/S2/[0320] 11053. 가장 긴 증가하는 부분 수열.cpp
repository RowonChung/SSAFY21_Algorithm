#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int N;
int arr[1000];
int dp[1000];

int checkBack(int index) {
	int m = index;

	for (int i = index; i >= 0; i--) {
		if (arr[i] < arr[index]) {
			if (dp[i] > dp[m]) {
				m = i;
			}
		}
	}

	return m;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		int k = checkBack(i);
		dp[i] = dp[k] + 1;
	}

	int res = 0;

	for (int i = 0; i < N; i++) {
		if (dp[i] > res)
			res = dp[i];
	}

	cout << res;

	return 0;
}