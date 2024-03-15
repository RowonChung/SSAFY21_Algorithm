#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	int ans = 1; // 처음엔 1 까지만 측정 가능
	for (int i = 0; i < n; i++) {
		if (arr[i] > ans) break; // 현재 보다 다음 저울이 크면 측정 X
		ans += arr[i]; // 측정 가능하면 ans + arr[i] 까지 측정 O
	}
	cout << ans;
	return 0;
}