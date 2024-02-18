#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
double x, y;

struct Info {
	double x;
	double y;
};

Info node[10001];

int main()
{
	double ans = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		node[i].x = x;
		node[i].y = y;
	}
	node[n].x = node[0].x;
	node[n].y = node[0].y;

	for (int i = 0; i < n; i++) {
		ans += (node[i].x * node[i + 1].y);
		ans -= (node[i + 1].x * node[i].y);
	}

	ans = abs(ans / 2.0);

	cout << fixed;
	cout.precision(1);
	cout << ans;

	return 0;
}
