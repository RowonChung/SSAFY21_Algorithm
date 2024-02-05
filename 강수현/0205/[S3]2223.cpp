#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int d;
	int now;
	int s;
};

int t, x, m;
int cnt = 0;
vector<Node>mon;


void input() {
	cin >> t >> x >> m;

	for (int i = 0; i < m; i++) {
		int dist, sec;
		cin >> dist >> sec;

		mon.push_back({ dist, dist, sec });
	}
}

void solve() {
	if (t == 0) return;

	t--;

	int flag = 0;

	for (int i = 0; i < mon.size(); i++) { // 움직여도 되는가
		if (mon[i].now - mon[i].s <= 0) {
			flag = 1;
			break;
		}
	}

	if (flag == 1) { // 움직이면 안돼
		for (int i = 0; i < mon.size(); i++) {
			// 몬스터는 멀어진다
			if (mon[i].d == mon[i].now)
				break;
			mon[i].now += mon[i].s;
		}
	}
	else { // 움직여도 돼
		// 몬스터 다가옴
		for (int i = 0; i < mon.size(); i++) {
			mon[i].now -= mon[i].s;
		}
		// 금화 줍기
		cnt += x;
	}

	solve();
}

int main() {

	input();

	solve();

	cout << cnt;
}