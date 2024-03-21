#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> cards;
int cnt = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		cards.push(num);
	}
	while (cards.size() > 1) {
		int first = cards.top();
		cards.pop();
		int second = cards.top();
		cards.pop();
		int next = first + second;
		cnt += next;
		cards.push(next);
	}
	cout << cnt;

	int de = -1;
	return 0;
}