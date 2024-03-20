#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
vector<int>list;
int path[8];

void  run(int now, int level) {
	if (level == M) {
		for (int i = 0; i < M; i++) {
			cout << path[i] << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = now; i < N; i++) {
		path[level] = list[i];
		run(i, level + 1);
		path[level] = 0;
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		list.push_back(input);
	}

	sort(list.begin(),list.end());

	run(0, 0);

	return 0;
}