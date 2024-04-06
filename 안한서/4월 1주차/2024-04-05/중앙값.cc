#include <iostream>
#include <algorithm>
using namespace std;

int h;
int n, k;
int seg[65536 * 4 + 1];
int arr[250001];

void init() {
	h = 1;
	while (h < 65536) h <<= 1;
}

void update(int idx, int diff) {
	idx += h;
	while (idx > 0) {
		seg[idx] += diff;
		idx >>= 1;
	}
}

int search(int idx) {
	int pos = 1;
	while (pos < h) {
		// 중앙값 위치인 (k+1)/2 
		// 작으면 후보가 위치한 구간 -> 왼쪽 구간에서 탐색
		// 아니면 없는 구간 -> 왼쪽 구간까지 개수 빼주고, 오른쪽 구간 탐색 
		if (idx <= seg[pos * 2]) pos *= 2;
		else {
			idx -= seg[pos * 2];
			pos = pos * 2 + 1;
		}
	}
	return pos - h;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	init();
	for(int i=0; i<n; i++) cin >> arr[i];

	long long ans = 0;
	for (int i = 0; i < k; i++) update(arr[i], 1);
	for(int i=k; i<n; i++){
		// k개 숫자 들어가면 중앙값 측정
		// 이후 다음 값 추가, k번 이전 값 삭제
		ans += search((k + 1) / 2);
		update(arr[i], 1);
		update(arr[i - k], -1);
	}
	// 마지막 중앙값 까지 더해서 출력
	cout << ans + search((k + 1) / 2);
	return 0;
}