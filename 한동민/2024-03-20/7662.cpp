#include <iostream>
#include <set>
using namespace std;

multiset<int> ms;

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		ms.clear();
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			char tmp;
			cin >> tmp;
			if (tmp == 'I') {
				int num;
				cin >> num;
				ms.insert(num);
			}
			else {
				int num;
				cin >> num;
				if (ms.empty()) {
					continue;
				}
				if (num == -1) {
					ms.erase(ms.begin());
				}
				else {
					ms.erase(--ms.end());
				}
			}
		}
		if (ms.empty()) {
			cout << "EMPTY\n";
		}
		else {
			cout << *(--ms.end()) << " " << *ms.begin() << "\n";
		}
	}
}
