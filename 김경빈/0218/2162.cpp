#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <climits>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

struct line {
	int x1, y1, x2, y2;
};
int N, xi1, yi1, xi2, yi2, cnt, max_cnt, group[3000];
vector<line> v;
map<int, int> m;

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	int op = (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
	if (op == 0) return op;
	return op / abs(op);
}

bool isintersect(int idx1, int idx2) {
	line l1 = v[idx1], l2 = v[idx2];
	pair<int, int> a = make_pair(l1.x1, l1.y1);
	pair<int, int> b = make_pair(l1.x2, l1.y2);
	pair<int, int> c = make_pair(l2.x1, l2.y1);
	pair<int, int> d = make_pair(l2.x2, l2.y2);
	
	int ab = ccw(a, b, c) * ccw(a, b, d);
	int cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return (c <= b && a <= d) || (b <= c && d <= a);
	}
	return ab <= 0 && cd <= 0;
}

int get_parent(int idx) {
	if (group[idx] == idx) return idx;
	int g_idx = get_parent(group[idx]);
	m[g_idx] += m[idx];
	m[idx] = 0;
	return group[idx] = g_idx;
}

void union_parent(int a, int b) {
	a = get_parent(a);
	b = get_parent(b);
	if (a == b) return;
	if (a < b) {
		m[a] += m[b];
		m[b] = 0;
		group[b] = a;
	}
	else {
		m[b] += m[a];
		m[a] = 0;
		group[a] = b;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> xi1 >> yi1 >> xi2 >> yi2;
		v.push_back({ xi1, yi1, xi2, yi2 });
		group[i] = i;
		m[i] = 1;
	}

	for (int i = 0; i < N-1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (group[i] == group[j]) continue;
			if (not isintersect(i, j)) continue;
			union_parent(i, j);
		}
	}

	for (auto iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second > 0) {
			cnt++;
			max_cnt = max(max_cnt, iter->second);
		}
	}
	cout << cnt << '\n' << max_cnt << '\n';
}
