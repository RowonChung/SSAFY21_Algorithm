#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<int>v[500];
int index = 1;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < index; j++) {
			int input;
			cin >> input;
			v[i].push_back(input);
		}
		index++;
	}

	for (int i = index-2; i > 0; i--) {
		for (int j = 0; j <= i-1; j++) {
			int tmp = max(v[i][j], v[i][j + 1]);
			v[i - 1][j] += tmp;
		}
	}

	cout << v[0][0];

	return 0;
}