#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int N, K;

int main() {
	cin >> N >> K;

	multiset<int> ms;
	vector<int> v;
	int start = 0;



	int maxx = -1;

	if (N == 1 || N==2) {
		for (int i = 0; i < N; i++) {
			int number;
			cin >> number;
			v.push_back(number);
		}

		sort(v.begin(), v.end());

		if (N == 1) {
			cout << v[0];
			return 0;
		}
		else {
			cout << v[1];
			return 0;
		}

	}

	for (int i = 0; i < N; i++) {
		if (i < K) {
			int num;
			cin >> num;
			ms.insert(num);
			v.push_back(num);
		}
		else {
			int first = v[start];
			int second; 
			cin >> second;
			maxx= max(maxx,*ms.begin());
			auto iter = ms.find(first);
			ms.erase(iter);
			ms.insert(second);
			start++;
			v.push_back(second);
		}
	}
	cout << maxx;

}