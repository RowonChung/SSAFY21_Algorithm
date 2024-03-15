#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <climits>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

struct LINE {
	double x1, y1, x2, y2;
};
LINE line[2];

double ccw(pair<double, double> a, pair<double, double> b, pair<double, double> c) {
	double op = (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
	if (op == 0) return op;
	return op / abs(op);
}

bool isintersect() {
	pair<double, double> a = make_pair(line[0].x1, line[0].y1);
	pair<double, double> b = make_pair(line[0].x2, line[0].y2);
	pair<double, double> c = make_pair(line[1].x1, line[1].y1);
	pair<double, double> d = make_pair(line[1].x2, line[1].y2);

	double ab = ccw(a, b, c) * ccw(a, b, d);
	double cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return c <= b && a <= d;
	}
	return ab <= 0 && cd <= 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 2; i++) {
		cin >> line[i].x1 >> line[i].y1 >> line[i].x2 >> line[i].y2;
	}

	cout << isintersect();
}