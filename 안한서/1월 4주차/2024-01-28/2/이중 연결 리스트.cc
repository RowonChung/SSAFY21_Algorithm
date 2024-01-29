#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int MX = 500000;

struct Node {
	int prev;
	int next;
};

Node dll[MX + 2];
int n, m;
int small[MX + 1]; // 뒤에 작은 수 개수 저장
int cache[MX + 1]; // lis 갱신 과정에서 덮어지는 경우 위해 따로 저장

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		dll[i].next = i + 1;
		dll[i].prev = i - 1;
	}

	for (int i = 0; i < m; i++) {
		char cmd; cin >> cmd;
		int x, y; cin >> x >> y;

		// 삭제 처리
		dll[dll[x].next].prev = dll[x].prev;
		dll[dll[x].prev].next = dll[x].next;
		// 이동
		if (cmd == 'A') {
			dll[x].prev = dll[y].prev;
			dll[x].next = y;
		}
		else {
			dll[x].prev = y;
			dll[x].next = dll[y].next;
		}
		// 연결
		dll[dll[x].prev].next = x;
		dll[dll[x].next].prev = x;
	}
	
	small[0] = 0;
	for (int i = 1; i <= n; i++) small[i] = MX + 1;

	int len = 0;
	for (int i = dll[0].next; i != (n + 1); i = dll[i].next) {
		// lower_bound 활용해 뒤에 작은 수가 몇개인지 저장 
		int idx = lower_bound(small, small + n, i) - small;
		small[idx] = i;
		cache[i] = small[idx-1]; // idx가 같은 경우 덮어 써지기 때문에 따로 직전 위치 저장

		len = max(len, idx); // 최대 길이 저장
	}

	// Lis 제외한 값을 다시 돌려야함
	cout << n - len << '\n';
	// list 구성
	vector<int> lis;
	for (int i = small[len]; i; i = cache[i]) lis.push_back(i);

	// lis들보다 작은 값 A로 뒤로 보냄
	int curr = 1;
	for (int i = (len-1); i >= 0; curr++) {
		if (lis[i] == curr) { i--; continue; }
		cout << "A " << curr << ' ' << lis[i] << '\n';
	}
	// lis 보다 큰 값 B로 앞으로 보낸다.
	for (int i = curr; i <= n; i++) {
		cout << "B " << i << ' ' << i - 1 << '\n';
	}
	return 0;
}