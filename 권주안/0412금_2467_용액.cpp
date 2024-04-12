#include <iostream>
#include <algorithm>
using namespace std;

struct Sol {
	int val;
	int prop;
};
int N;
Sol arr[100000];
bool cmp(Sol left, Sol right) {
	if (left.val < right.val) return true;
	if (left.val > right.val) return false;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// init
	cin >> N;
	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		if (val >= 0) {
			arr[i] = { val,0 };
		}
		else {
			arr[i] = { val * (-1),1 };
		}
	}
	
	// solve
	sort(arr, arr + N, cmp);
	int ans = 2134567890;
	int idx = 0;
	for (int i = 0; i < N - 1; i++) {
		int mix;
		if (arr[i].prop == arr[i + 1].prop) {
			mix = arr[i + 1].val + arr[i].val;
		}
		else {
			mix = arr[i + 1].val - arr[i].val;
		}
		if (ans > mix) {
			ans = mix;
			idx = i;
		}
	}

	// print
	int ans1, ans2;
	if (arr[idx].prop == 0) {
		ans1 = arr[idx].val;
	}
	else {
		ans1 =  arr[idx].val * (-1);
	}
	if (arr[idx + 1].prop == 0) {
		ans2 =  arr[idx + 1].val;
	}
	else {
		ans2 = arr[idx + 1].val * (-1);
	}
	if (ans1 < ans2) {
		cout << ans1 << " " << ans2;
	}
	else {
		cout << ans2 << " " << ans1;
	}

	return 0;
}