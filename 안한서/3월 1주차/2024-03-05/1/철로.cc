#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define pii pair<int, int> 

bool compare(const pii& a, const pii& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;

	vector<pii> v;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		if (a > b) swap(a, b);
		v.push_back({ a, b });
	}
	int d; cin >> d;

	sort(v.begin(), v.end(), compare);

	int ans = 0;
	int start = 0, cnt = 0;

	priority_queue<int> pq;
	for (auto idx : v) {
		// 시작점 : 끝점 - d
		start = idx.second - d;
		
		// 시작에 포함안되면 뺌
		while (!pq.empty() && -pq.top() < start) {
			cnt--;
			pq.pop();
		}

		// 포함되면 pq에 push후 ans 갱신
		if (idx.first >= start) {
			cnt++;
			pq.push(-idx.first);
			ans = max(ans, cnt);
		}
	}

	cout << ans;
	return 0;
}