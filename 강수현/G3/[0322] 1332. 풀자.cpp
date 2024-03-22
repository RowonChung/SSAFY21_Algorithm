#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int N, V;
vector<int>v;
int s = -1, e = -1;
int res = 500;

void calTest() {
	int index = e;
	int cnt = 1;

	while (index > 0) {
		if (index - 1 == s) {
			index--;
			cnt++;
		}
		else if (index - 1 == 0) {
			index--;
			cnt++;
		}
		else {
			index -= 2;
			cnt++;
		}
	}

	res = min(res, cnt);
}

void findWant() {
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (abs(v[i] - v[j]) >= V) {
				s = i;
				e = j;
				
				calTest();
			}
		}
	}
}

int main() {
	cin >> N >> V;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;

		v.push_back(input);
	}

	findWant();

	if (res == 500)
		cout << N;
	else
		cout << res;
	
	return 0;
}