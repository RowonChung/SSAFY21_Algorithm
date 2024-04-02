#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
vector<int>v;
int dif = 21e8;
int resa, resb;

void bs(int start, int end) {

	while (start < end) {
		int sum = v[start] + v[end];
		int plus = abs(sum);

		if (sum == 0) {
			cout << v[start] << " " << v[end];
			return;
		}

		if (plus < dif) {
			resa = start;
			resb = end;
			dif = plus;
		}

		if (sum > 0) end--;
		else start++;

	}

	cout << v[resa] << " " << v[resb];

	return;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	bs(0, N-1);
}