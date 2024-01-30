#include <iostream>
#include <stack>

using namespace std;

struct top {
	int index;
	int value;
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	int t;
	stack<top> s;
	for (int i = 0; i < N; i++) {
		cin >> t;
		while (!s.empty()) {
			if (s.top().value > t) {
				cout << s.top().index<<" ";
				break;
			}
			s.pop();
		}
		if (s.empty()) {
			cout << "0" << " ";
		}
		s.push(top{ i + 1,t });
	}
}