#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

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
		priority_queue<int> left;
		priority_queue<int, vector<int>, greater<int>> right;
		int n, middle;
		cin >> n >> middle;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2; j++) {
				int tmp;
				cin >> tmp;
				if (tmp < middle) {
					left.push(tmp);
				}
				else {
					right.push(tmp);
				}
			}
			if (left.size() < right.size()) {
				left.push(middle);
				middle = right.top();
				right.pop();
			}
			else if(left.size() > right.size()) {
				right.push(middle);
				middle = left.top();
				left.pop();
			}
			sum += middle;
			sum %= 20171109;
		}
		cout << "#" << test_case << " " << sum << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
