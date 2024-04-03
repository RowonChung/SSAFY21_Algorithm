#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
long long E;

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
		E += c;
		v.push_back({ a,b,c });
	}

	sort(v.begin(), v.end(), compare);

	int target = N - 1;
	int selectCount = 0;
	long long res = 0;

	for (Node sel : v) {
		int a = sel.a;
		int b = sel.b;
		int cost = sel.cost;

		if (find(a) == find(b)) continue;

		setUnion(a, b);

		selectCount++;
		res += cost;

		if (target == selectCount) break;
	}

	if (target != selectCount) cout << "-1";
	else cout << E-res;

	return 0;
}