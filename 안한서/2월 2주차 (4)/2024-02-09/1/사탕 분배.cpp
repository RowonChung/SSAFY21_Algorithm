#include <iostream>
#include <algorithm>
using namespace std;

long long calPow(long long cnt, long long MOD) {
	if (cnt == 0) return 1;
	// (A*A) % C = ((A % C) * (A % C)) % C
	long long res = calPow(cnt / 2, MOD);
	res = (res*res) % MOD;
	// 홀수면 A 곱해서 A^(2N + 1)
	if (cnt & 1) res = (res * 2) % MOD;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		// A + B = C ... C는 항상 유지
		// 2A + C-2A or A - B + 2B (B = C-A)
		// ... 2A - C + 2C - 2A
		// (2A-C) % C = 2A % C ... 두 경우가 같은 방식으로 계산 된다.
		// K 번째 = (2^K * A) % C
		// ANS : min( (2^K * A) % C, C - (2^K * A) % C )
		long long a, b, k; cin >> a >> b >> k;
		long long MOD = (a + b);
		long long x = (calPow(k, MOD) * a) % MOD;
		cout << "#" << tc << ' ' << min(x, MOD - x)  << '\n';
	}
	return 0;
}