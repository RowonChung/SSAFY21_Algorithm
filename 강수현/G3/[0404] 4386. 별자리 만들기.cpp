#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#include <iomanip>
using namespace std;

struct Node {
	double x;
	double y;
};

struct Star {
	int a, b;
	double dist;
};

bool compare(Star l, Star r) {
	return l.dist < r.dist;
}

int N;
vector<Node>v;
vector<Star>s;
int arr[100];

void init() {
	for (int i = 0; i < N; i++) {
		arr[i] = i;
	}
}

void calDist(int a, int b) {
	double d = sqrt(pow(v[a].x - v[b].x, 2) + pow(v[a].y - v[b].y, 2));

	s.push_back({ a,b,d });
}

int find(int tar) {
	if (tar == arr[tar]) return tar;

	int ret = find(arr[tar]);

	arr[tar] = ret;

	return ret;
}

void setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);

	if (t1 == t2) return;

	arr[t2] = t1;

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;

	init();

	for (int i = 0; i < N; i++) {
		double a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			calDist(i, j);
		}
	}

	sort(s.begin(), s.end(), compare);

	int target = N - 1;
	double result = 0;
	int selectCount = 0;
	
	for (Star sel : s) {
		int a = sel.a;
		int b = sel.b;
		double dist = sel.dist;

		if (find(a) == find(b)) continue;

		setUnion(a, b);

		result += dist;
		selectCount++;

		if (selectCount == target) break;
	}
	
	cout << setprecision(3) << result;

	return 0;
}