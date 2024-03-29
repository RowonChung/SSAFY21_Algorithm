#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000000000

long long n, q, u, v, h;
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
		else seg[i] = { -INF, -INF, -INF, -INF };
	}
	for (long long i = h - 1; i > 0; i--) seg[i] = merge(seg[i * 2], seg[i * 2 + 1]);
}

void update(int idx, int val) {
	idx += h;
	seg[idx] = { val, val, val, val };
	idx /= 2;
	while (idx > 0) {
		seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
		idx /= 2;
	}
}

Node query(long long l, long long r) {
	// left와 right로 각 방향으로 merge
	Node left = { -INF, -INF, -INF, -INF };
	Node right = { -INF, -INF, -INF, -INF };
	for (l += h, r += h; l < r; l /= 2, r /= 2) {
		if (l & 1) left = merge(left, seg[l++]);
		if (r & 1) right = merge(seg[--r], right);
	}
	// 마지막에 둘이 합쳐서 return
	return merge(left, right);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q >> u >> v;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i] *= u;
		arr[i] += v;
	}
	init();

	for (int i = 0; i < q; i++) {
		long long c, a, b; cin >> c >> a >> b;
		// MAX 값은 V가 i~j 만큼 더해짐 ... V * (j-i+1) -> -V
		if(c == 0) cout << query(a-1, b).MAX - v << '\n';
		else update(a-1, b * u + v);
	}

	return 0;
}
