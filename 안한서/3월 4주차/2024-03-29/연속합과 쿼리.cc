#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000000000

long long n, m, h;
long long arr[100000];

struct Node {
	long long lMAX, rMAX, MAX, sum;
};
Node seg[400000];

Node merge(Node left, Node right) {
	Node ans;
	// lMAX : 왼쪽의 구간합 + 오른쪽 lMAX, 왼쪽의 lMAX 비교
	ans.lMAX = max(left.lMAX, left.sum + right.lMAX);
	// rMAX : 오른쪽의 구간합 + 왼쪽 rMAX, 오른쪽의 rMAX 비교
	ans.rMAX = max(left.rMAX + right.sum, right.rMAX);
	// MAX : 양쪽 MAX, 연결되는 경우도 있으니 lMAX, rMAX 합 
	ans.MAX = max({ left.MAX, right.MAX, left.rMAX + right.lMAX });
	// sum : 구간 합 더함
	ans.sum = left.sum + right.sum;
	return ans;
}

void init() {
	h = 1;
	while (h < n) h *= 2;

	for (long long i = h; i < 2 * h; i++) {
		if ((i - h) < n) seg[i] = { arr[i - h], arr[i - h], arr[i - h], arr[i - h] };
		else seg[i] = {-INF, -INF, -INF, -INF};
	}
	for (long long i = h - 1; i > 0; i--) seg[i] = merge(seg[i * 2], seg[i * 2 + 1]);
}

Node query(long long l, long long r) {
	// left와 right로 각 방향으로 merge
	Node left = { -INF, -INF, -INF, -INF };
	Node right = { -INF, -INF, -INF, -INF };
	for (l += h, r += h; l < r; l/= 2, r /= 2) {
		if (l & 1) left = merge(left, seg[l++]);
		if (r & 1) right = merge(seg[--r], right);
	}
	// 마지막에 둘이 합쳐서 return
	return merge(left, right);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	init();

	cin >> m;
	for (int i = 0; i < m; i++) {
		long long a1, a2; cin >> a1 >> a2;
		cout << query(a1 - 1, a2).MAX << '\n';
	}
	return 0;
}
