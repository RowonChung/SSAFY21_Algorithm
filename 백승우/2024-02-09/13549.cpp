#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int cost[100001];
int x[2] = { -1, 1 };

struct info {
	int weight;
	int index;
	bool operator<(info right) const {
		if (weight < right.weight) return false;
		if (weight > right.weight) return true;
		return false;
	}
};

int n, k;

int main(void) {
	cin >> n >> k;

	for (int i = 0; i < 100001; i++) {
		cost[i] = -1;
	}

	priority_queue<info> pq;

	pq.push({ 0, n });
	cost[n] = 0;

	while (!pq.empty()) {
		int nowTime = pq.top().weight;
		int now = pq.top().index;
		pq.pop();

		if (nowTime > cost[now])
			continue;

		int next, nextTime;
		for (int i = 0; i < 3; i++) {
			if (i == 2) {
				next = 2 * now;
				nextTime = nowTime;
			}
			else {
				next = now + x[i];
				nextTime = nowTime + 1;
			}

			if (next < 0 or next > 100000)
				continue;

			if (cost[next] == -1) {
				cost[next] = nextTime;
				pq.push({ nextTime, next });
			}
			else if (cost[next] > nextTime) {
				cost[next] = nextTime;
				pq.push({ nextTime, next });
			}
		}
	}
	cout << cost[k];
}
