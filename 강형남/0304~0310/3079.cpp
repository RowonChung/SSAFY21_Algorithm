#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;

vector<long long > v;

int main() {
	cin >> N >> M; //N개 심사대 M명

	for (int i = 0; i < N; i++) {
		long long number;
		cin >> number;
		v.push_back(number);
	}

	sort(v.begin(), v.end());

	long long low = 1;
	long long high = M * v[0];

	long long answer = 0;

	while (low <= high) {
		long long mid = (low + high) / 2;
		long long sum = 0;
		for (int i = 0; i < N; i++) {
			sum += mid / v[i];
		}
		if (sum >= M) {
			if (answer > mid || answer == 0) { 
				answer =mid;
			}
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	cout << answer;
	

 }