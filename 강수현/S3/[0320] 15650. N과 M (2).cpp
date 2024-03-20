#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
int path[8];

void  run(int now, int level) {
	if (level == M) {
		for (int i = 0; i < M; i++) {
			cout << path[i] << " ";
		}
		cout << "\n";
	}

	for (int i = now; i <= N; i++) {
		path[level] = i;
		run(i + 1, level + 1);
		path[level] = 0;
	}
}

int main() {
	cin >> N >> M;

	run(1, 0);

	return 0;
}