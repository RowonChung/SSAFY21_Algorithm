#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;

int N, M;

struct Node {
	int a, b;
	int cost;
};

bool compare(Node l, Node r) {
	return l.cost < r.cost;
}

vector<Node>v;
int arr[100001];

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
	
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		arr[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}

	sort(v.begin(), v.end(), compare);

	int taget = N - 2;
	int selectCount = 0;
	int res = 0;

	for (Node sel : v) {
		if (taget == selectCount) break;

		int a = sel.a;
		int b = sel.b;
		int cost = sel.cost;

		if (find(a) == find(b)) continue;

		setUnion(a, b);

		selectCount++;
		res += cost;
	}

	cout << res;

	return 0;
}