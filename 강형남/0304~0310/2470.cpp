#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	int N;
	vector<int> v;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}

	sort(v.begin(), v.end());

	int start = 0;
	int end = N - 1;
	int minn = 2134567890;

	int answerS = start;
	int answerE = end;

	while (start < end) {
		int diff = v[start] +v[end];
		
		int adiff = abs(diff);
		if (adiff < minn) {
			minn = adiff;
			answerS = start;
			answerE = end;
		}


		if (diff < 0) {
			start++;
		}
		else {
			end--;
		}

	}
	cout << v[answerS] << " " << v[answerE];
}