#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int n, k;
int cnt = 0, flag = 0;
int path[11] = { 0 };

void printPath() {
	for (int i = 0; i <= 10; i++) {
		if (path[i] == 0)
			return;

		if (i != 0)
			cout << "+";

		cout << path[i];
	}

	return;
}

void dfs(int level, int left) {
	if (left == 0) {
		cnt++;

		if (cnt == k) {
			printPath();
			flag = 1;
		}

		return;
	}

	for (int i = 1; i <= 3; i++) {
		if (i > left) break;

		path[level] = i;
		dfs(level + 1, left - i);
		path[level] = 0;
	}

}

int main() {

	cin >> n >> k;

	dfs(0, n);

	if (flag == 0)
		cout << -1; 

	return 0;
}