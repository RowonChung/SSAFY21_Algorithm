#include <iostream>
using namespace std;

int tc, T;
int nowP, destP;
int cnt;
int flag;

void init() {
	cin >> nowP >> destP;
	cnt = 1;
	flag = 0;
}

void solve() {
	while (nowP < destP) {
		nowP += cnt;
		if (nowP >= destP) {
			flag = 1;
			break;
		}
		destP -= cnt;
		cnt++;
	}
}

void print() {
	if (flag) {
		cout << (cnt * 2) - 1 << "\n";
	}
	else {
		cout << (cnt - 1) * 2 << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		init();
		solve();
		print();
	}

	int de = -1;
	return 0;
}