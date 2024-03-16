#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Coms {
	int from, to, lens;

	bool operator<(Coms right) const {
		return lens > right.lens;
	}
};

priority_queue<Coms> pq;
string s[51];
int n;
int totalLens = 0;

int coms[51];

void init() {
	for (int i = 0; i < n; i++) coms[i] = i;
}

int find(int tar) {
	if (coms[tar] == tar) return tar;

	int ret = find(coms[tar]);
	coms[tar] = ret;
	return ret;
}

void setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2) return;

	coms[t2] = t1;
}

int main() {
	cin >> n;

	init();

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int nowLen = s[i][j] - '0';
			if (nowLen == 0) continue;
			else if (nowLen < 49) nowLen += 10;
			else nowLen -= 48;

			totalLens += nowLen;

			if (i == j) continue;

			pq.push({ i, j, nowLen });
		}
	}

	int target = n - 1;
	int result = 0;
	int selectCount = 0;
	
	int pqSize = pq.size();
	for (int i = 0; i < pqSize; i++) {
		Coms now = pq.top();
		pq.pop();

		int a = now.from;
		int b = now.to;
		int lens = now.lens;

		if (find(a) == find(b)) continue;

		setUnion(a, b);

		totalLens -= lens;
		selectCount++;
		if (selectCount == target) break;
	}

	if (selectCount != target) {
		cout << -1;
		return 0;
	}

	cout << totalLens;
}