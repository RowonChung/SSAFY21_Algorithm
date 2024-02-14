#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
int amus[10001], leftT[10001];

void input() {
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		cin >> amus[i];
		leftT[i] = amus[i];
	}
}

int Gcd(int a, int b) {
	int A = max(a, b);
	int B = min(a, b);

	while (A % B != 0) {
		int R = A % B;
		A = B;
		B = R;
	}

	return B;
}

int findCycle() { // 최소 공배수 찾기
	int result = amus[1];
	for (int i = 2; i <= m; i++) {
		int GCD = Gcd(result, amus[i]);
		int LCM = result * amus[i] / GCD;
		result = LCM;
	}
	
	return result;
}

int cntPerson(int c) {
	int cnt = 0;

	for (int i = 1; i <= m; i++) {
		cnt += c / amus[i];
	}

	return cnt;
}

void solve() {
	if (m == 1) {
		cout << "1";
		return;
	}

	int cycle = findCycle();

	int cnt = cntPerson(cycle);

	// cout << cnt;

	n %= cnt;

	// 아이들이 m개 이하일 때
	if (n <= m) {
		cout << n;
		return;
	}

	n -= m;

	// 초 단위로 돌기
	while (n != 0) {
		for (int i = 1; i <= m; i++) { // 1초 도는중
			leftT[i]--;
		}

		for (int i = 1; i <= m; i++) {

			if (leftT[i] != 0) continue;

			// 0일때
			if (n == 1) {
				cout << i;
				return;
			}

			leftT[i] = amus[i];
			n--;
		}
	}
	
}

int main() {

	input();

	solve();

}