#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
vector<int>list;
int flag[8];
int path[8];

void  run(int level) {
	if (level == M) {
		for (int i = 0; i < M; i++) {
			cout << path[i] << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = 0; i < N; i++) {
		if (flag[i] == 1) continue;

		flag[i] = 1;
		path[level] = list[i];

		run(level + 1);
		flag[i] = 0;
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

	run(0);

	return 0;
}