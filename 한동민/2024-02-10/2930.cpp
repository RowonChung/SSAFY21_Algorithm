#include <iostream>
#include <queue>
using namespace std;

int n;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		priority_queue<int> pq;
		int n;
		cin >> n;
		cout << "#" << test_case << " ";
		for (int i = 0; i < n; i++) {
			int command;
			cin >> command;
			if (command == 1) {
				int tmp;
				cin >> tmp;
				pq.push(tmp);
			}
			else {
				if (pq.empty()) {
					cout << -1 << " ";
				}
				else {
					cout << pq.top() << " ";
					pq.pop();
				}
			}
		}
		cout << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
