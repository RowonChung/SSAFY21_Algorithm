#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

long long n, k;

void bs(long long start, long long end) {
	long long mid;
	long long cnt;
	long long m = 21e8;

	while (start <= end) {
		cnt = 0;
		mid = (start + end) / 2;

		for (long long i = 1; i <= n; i++) {
			cnt += min(mid / i, n);
		}

		if (cnt >= k) {
			end = mid - 1;
			m = min(m, mid);
		}
		else
			start = mid + 1;
	}

	cout << m;
}

int main() {
	cin >> n >> k;

	bs(1, n * n);

	return 0;
}