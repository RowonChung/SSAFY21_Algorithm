#include <iostream>
using namespace std;

long long n, m, MX=0;
long long t[10001];

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> t[i];
		// 최대 시간 찾기 위해 이용 시간 중 최대 저장
		MX = max(MX, t[i]);
	}

	// 놀이 기구 수보다 아이 적으면 마지막 아이 번호 출력
	if (n <= m) cout << n;
	else {
		// 0분 ~ 최대 시간 중 전원 이용 가능한 탑승 시간 탐색
		long long minutes = n * MX;
		long long st = 0, en = n * MX;
		while (en > st) {
			long long mid = (st + en) / 2;

			// 탑승 가능한 놀이기구 수 : 0분에 M개 + (이용 시간 / 운행 시간) 합
			long long num = m;
			for (int i = 0; i < m; i++) num += (mid / t[i]);

			if (num < n) st = mid + 1;
			else {
				// 모든 인원이 이용 가능하면 minutes 갱신
				minutes = min(minutes, mid);
				en = mid;
			}
		}

		long long cnt = m;
		// minutes - 1 분 까지 이용 개수 +
		for (int i = 0; i < m; i++) cnt += (minutes - 1) / t[i];

		// 마지막 1분 check
		for (int i = 0; i < m; i++) {
			if (minutes % t[i] == 0) cnt++;
			if (cnt == n) { cout << i + 1; break; }
		}
	}
	return 0;
}