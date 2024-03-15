#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <climits>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
long long input, val = LLONG_MAX;
vector<long long> v, ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < N-2; i++) {
		for (int j = i + 1; j < N-1; j++) {
			long long x = v[i], y = v[j], want = v[i] + v[j], ret = LLONG_MAX;
			int left = j + 1, right = N - 1;

			while (left <= right) {
				int mid = (left + right) / 2;
				long long temp_val = v[mid];

				if (want + temp_val == 0) {
					ret = temp_val;
					break;
				}

				if (want + temp_val > 0) {
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}

				if (abs(want + temp_val) < abs(want + ret)) {
					ret = temp_val;
				}
			}

			if (ret == LLONG_MAX) continue;
			if (abs(ret + v[i] + v[j]) < abs(val)) {
				val = ret + v[i] + v[j];
				ans = { v[i], v[j], ret };
				if (val == 0) break;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		cout << ans[i] << " ";
	}
}