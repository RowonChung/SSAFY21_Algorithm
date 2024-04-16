#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

struct PROB {
	long long dead, cup;

	bool operator<(PROB right) const {
		if (dead < right.dead) return true;
		if (dead > right.dead) return false;

		if (cup > right.cup) return true;
		if (cup < right.cup) return false;

		return false;
	}
};
int N;
long long sum, d, c;
deque<PROB> v;
priority_queue<int, vector<int>, greater<>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> d >> c;
		v.push_back({ d, c });
	}
	sort(v.begin(), v.end());

	while (!v.empty()) {
		if (pq.empty()) {
			pq.push(v.front().cup);
			v.pop_front();
		}
		else if (pq.size() < v.front().dead) {
			pq.push(v.front().cup);
			v.pop_front();
		}
		else if (pq.size() == v.front().dead && pq.top() < v.front().cup) {
			pq.pop();
			pq.push(v.front().cup);
			v.pop_front();
		}
		else {
			v.pop_front();
		}
	}
	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}
	cout << sum;
}