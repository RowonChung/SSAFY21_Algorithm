#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node { int no, need; };
vector<Node> info[101]; // 조립 정보
int comb[101]; // 조립 몇 번 되야 하는지 저장
int cnt[101]; // 부품 사용 횟수

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, t; cin >> n >> t;
	for (int i = 0; i < t; i++) {
		int a, b;
		int c;
		cin >> a >> b >> c;

		comb[b]++; // 조립 몇 번 되야 하는지
		info[a].push_back({ b, c });
	}

	vector<int> ans;
	queue<int> q;
	q.push(n);
	cnt[n] = 1; // 완성품은 한번 사용
	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		// 조립 정보 없으면 -> 기본 부품
		if (info[curr].empty()) ans.push_back(curr);

		// 기본 부품 아니면 조립
		for (auto nxt : info[curr]) {
			int no = nxt.no; // 조립 해야하는 부품
			int need = nxt.need; // 사용 개수
			cnt[no] += cnt[curr] * need; // 필요한 개수 누적
			if (--comb[no] == 0) q.push(no); // 전부 사용되었으면 push
		}
	}

	sort(ans.begin(), ans.end());
	for (int idx : ans) cout << idx << ' ' << cnt[idx] << '\n';
	return 0;
}