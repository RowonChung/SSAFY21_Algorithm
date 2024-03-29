#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 10000000010

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
		else seg[i] = { -INF, -INF, -INF, -INF };
	}

	for (long long i = h - 1; i > 0; i--) {
		if (seg[i * 2 + 1].lMAX == -INF) seg[i] = seg[i * 2];
		else seg[i] = merge(seg[i * 2], seg[i * 2 + 1]);
	}
}

Node query(long long l, long long r) {
	// left와 right로 각 방향으로 merge
	Node left = { -INF, -INF, -INF, -INF };
	Node right = { -INF, -INF, -INF, -INF };
	for (l += h, r += h; l < r; l /= 2, r /= 2) {
		if (l & 1) {
			if (left.lMAX == -INF) left = seg[l++];
			else left = merge(left, seg[l++]);
		}
		if (r & 1) {
			if (right.lMAX == -INF) right = seg[--r];
			else right = merge(seg[--r], right);
		}
	}
	// 마지막에 둘이 합쳐서 return
	if (left.lMAX == -INF && right.lMAX == -INF) return { 0, 0, 0, 0 };
	else if (left.lMAX == -INF) return right;
	else if (right.lMAX == -INF) return left;
	else return merge(left, right);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	init();

	cin >> m;
	for (int i = 0; i < m; i++) {
		long long x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		// x1, y1, x2, y2 안겹침 -> y1 < x2
		// x1 ~ y1 중 오른쪽 포함 최대 / (y1+1) ~ (x2-1) 총 합 / x2 ~ y2 중 왼쪽 포함 최대 -> 모두 더한 값이 최대
		if (y1 < x2) cout << query(x1 - 1, y1).rMAX + query(y1, x2 - 1).sum + query(x2 - 1, y2).lMAX << '\n';
		else {
			// 겹침
			// 왼쪽 ~ 가운데가 최대 : x1~(x2-1) 중 오른 포함 최대 + x2 ~ y1 중 왼쪽 포함 최대
			// 가운데가 최대 -> x2 ~ y1 중 MAX
			// 가운데 ~ 오른쪽이 최대 : x2 ~ y1 중 오른 포함 최대 + (y1+1) ~ y2 중 왼쪽 포함 최대
			// x1 ~ (x2-1) 중 오른쪽 포함 최대 + x2 ~ y1 총 합 + (y1+1) ~ y2 중 왼쪽 포함 최대
			Node left = query(x1 - 1, x2 - 1), mid = query(x2 - 1, y1), right = query(y1, y2);
			cout << max({ left.rMAX + mid.lMAX, mid.MAX, mid.rMAX + right.lMAX, left.rMAX + mid.sum + right.lMAX }) << "\n";
		}
	}

	return 0;
}
