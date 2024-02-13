#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

int days[200001];

int main(int argc, char** argv)
{
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int n, p; cin >> n >> p;
		vector<int> gap(n, 0);
		for (int i = 0; i < n; i++) cin >> days[i];

		// 0번에서 n번 까지 치트 서야하는 횟수 저장
		for (int i = 1; i < n; i++) gap[i] = gap[i - 1] + (days[i] - days[i - 1] - 1);

		int ans = 0;
		// i 번에서 idx 까지 가능한지 판별
		// 가능하면 갱신, idx는 이분 탐색으로
		for (int i = 0; i < n; i++) {
			int start = i, end = n - 1;
			while (start <= end) {
				int mid = (start + end) / 2;
				int cnt = gap[mid] - gap[i];
				if (cnt <= p) {
					ans = max(ans, days[mid] - days[i] + 1 + p - cnt);
					start = mid + 1;
				}
				else end = mid - 1;
			}
		}
		cout << "#" << tc << ' ' << ans << '\n';
	}
	return 0;
}