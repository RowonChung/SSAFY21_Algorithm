#include <iostream>
#include <algorithm>
using namespace std;

struct Point { double x, y; };
int N;
Point poly[10010];
double sum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	double firstX, firstY;
	cin >> firstX >> firstY;
	poly[0] = { firstX,firstY };
	for (int i = 1; i < N; i++) {
		cin >> poly[i].x >> poly[i].y;
	}
	poly[N] = { firstX,firstY };
	for (int i = 0; i < N; i++) {
		double ret = (poly[i].x + poly[i + 1].x) * (poly[i].y - poly[i + 1].y);
		sum += ret;
	}

	sum = abs(sum) / 2;
	cout << fixed;
	cout.precision(1);
	cout << sum;

	return 0;
}