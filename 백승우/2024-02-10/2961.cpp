#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;

struct food {
	int sin;
	int ssen;
};

struct info {
	int index;
	int nowSin;
	int nowSsen;
};

food foods[11];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> foods[i].sin >> foods[i].ssen;
	}
	queue <info> q;
	q.push({ 0,1,0 });

	int ans = 1e9;
	while (!q.empty()) {
		info now = q.front();
		q.pop();
		if (now.index == n) {
			if (now.nowSin == 1 and now.nowSsen == 0) continue;
			ans = min(abs(now.nowSin - now.nowSsen), ans);
			continue;
		}
		int next = now.index + 1;
		for (int flag = 0; flag <= 1; flag++) {
			if (flag) q.push({ next, now.nowSin * foods[next].sin, now.nowSsen + foods[next].ssen });
			else q.push({ next, now.nowSin, now.nowSsen});
		}
	}
	cout << ans;

	return 0;
}
