#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long arr[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, b, c; cin >> n >> b >> c;
	for (int i = 0; i < n; i++) cin >> arr[i];

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (b <= c) ans += (arr[i] * b);
		else {
			int cnt;
			if (arr[i + 1] > arr[i + 2]) {
				// 2번 공장이 3번 공장보다 물량 많은 경우
				// 1, 2번 공장에서 2개 연달아 구매 ( 3번 공장과 수량 같아질 때까지)
				// 이후 1, 2, 3 번에서 3개 연달아 구매

				// 2개 연달아 구매
				cnt = min(arr[i], arr[i + 1] - arr[i + 2]);
				ans += (b + c) * cnt;
				arr[i] -= cnt; arr[i + 1] -= cnt;

				// 3개 연달아 구매
				cnt = min({ arr[i], arr[i + 1], arr[i + 2] });
				ans += (b + 2 * c) * cnt;
				arr[i] -= cnt; arr[i + 1] -= cnt; arr[i + 2] -= cnt;
			}
			else {
				// 3개 연달아 구매
				cnt = min({ arr[i], arr[i + 1], arr[i + 2] });
				ans += (b + 2 * c) * cnt;
				arr[i] -= cnt; arr[i + 1] -= cnt; arr[i + 2] -= cnt;

				// 2개 연달아 구매
				cnt = min(arr[i], arr[i + 1]);
				ans += (b + c) * cnt;
				arr[i] -= cnt; arr[i + 1] -= cnt;
			}
			ans += b * arr[i];
		}
	}
	cout << ans;
	return 0;
}