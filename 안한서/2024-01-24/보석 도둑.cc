#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k; cin >> n >> k;

	vector<pair<int, int>> bosuk;
	vector<int> bag;

	for (int i = 0; i < n; i++) {
		int m, v; cin >> m >> v;
		bosuk.push_back(make_pair(m, v));
	}

	for (int i = 0; i < k; i++) {
		int c; cin >> c;
		bag.push_back(c);
	}
	
	// 무게, 가격 순으로 정렬
	sort(bosuk.begin(), bosuk.end());
	// 가방 무게 낮은 순서로 정렬
	sort(bag.begin(), bag.end());

	priority_queue<int> pq;
	int idx = 0;
	long long ans = 0;

	for (int t = 0; t < k; t++) {
		// 무게 높고, 가격 높은 순으로 정렬 위해 maxHeap (pq)
		while (idx < n && bosuk[idx].first <= bag[t]) { pq.push(bosuk[idx++].second); }

		// 가능한 경우 모두 집어 넣은 후 가장 비싼 것만 담음.
		if (!pq.empty()) { ans += pq.top(); pq.pop(); }
	}

	cout << ans;
	return 0;
}