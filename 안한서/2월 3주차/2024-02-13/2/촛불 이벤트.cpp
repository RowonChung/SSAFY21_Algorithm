#include<iostream>
#include<string>
#include<algorithm>
#include <cmath>
using namespace std;

long long n;

long long bs() {
	// k*k + k < 2*n ... k < root(2*n)
	long long start = 1, end = sqrt(2 * n);
	while (start <= end) {
		long long mid = (start + end) / 2;
		long long sum = (mid * mid + mid) / 2;
		if (sum == n) return mid;

		if (sum > n) end = mid - 1;
		else start = mid + 1;
	}
	return -1;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n;
		cout << "#" << tc << ' ' << bs() << '\n';
	}
	return 0;
}
