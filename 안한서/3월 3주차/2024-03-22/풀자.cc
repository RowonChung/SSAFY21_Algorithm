#include <iostream>
#include <algorithm>
using namespace std;

int n, v;
int inter[51];

int cal(int s, int e) {
	int ans = 1;
	int start = 0;
	while ((start + 2) <= s) {
		ans++;
		start += 2;
	}

	if (start < s) {
		ans += (s - start);
		start = s;
	}

	while ((start + 2) <= e) {
		ans++;
		start += 2;
	}

	if (start < e) {
		ans += (e - start);
		start = e;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> v;
	for (int i = 0; i < n; i++) cin >> inter[i];

	int ans = n;
	int s = -1, e = -1;
	for (int i = 0; i < (n-1); i++) {
		for (int j = (i + 1); j < n; j++) {
			if (abs(inter[i] - inter[j]) >= v) {
				s = i; e = j;
				ans = min(ans, cal(s, e));
			}
		}
	}

	cout << ans;
	return 0;
}