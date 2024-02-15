#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Bottle {
	int arr[3];
};

int st[3]; // standard
int num = 1;
int visited[1000][4] = { 0 }; // a,b,c,flag

int checkFlag(Bottle ox) {
	for (int i = 0; i < 1000; i++) {
		if (visited[i][3] == 0)
			return 0;

		if (ox.arr[0] == visited[i][0] && ox.arr[1] == visited[i][1] && ox.arr[2] == visited[i][2])
			return 1;
	}

	return 0;
}

void run() {
	queue<Bottle> q;

	q.push({ visited[0][0],visited[0][1],visited[0][2] });

	while (!q.empty()) {
		Bottle now = q.front();

		q.pop();

		for (int i = 0; i < 3; i++) {
			int tmp = now.arr[i];

			if (tmp == 0) continue;

			for (int j = 1; j < 3; j++) {
				Bottle ox = now;


				int target = (i + j) % 3;

				int dif = st[target] - ox.arr[target];

				if (dif <= 0) continue;

				if (dif > ox.arr[i]) {
					ox.arr[target] += ox.arr[i];
					ox.arr[i] = 0;
				}
				else {
					ox.arr[target] = st[target];
					ox.arr[i] -= dif;
				}
				
				int flag = checkFlag(ox);

				if (flag == 1) continue;

				for (int k = 0; k < 3; k++) {
					visited[num][k] = ox.arr[k];
				}
				visited[num++][3] = 1;
				q.push(ox);
			}
		}
	}

	return;
}

int main() {

	for (int i = 0; i < 3; i++) {
		cin >> st[i];
	}

	visited[0][2] = st[2];
	visited[0][3] = 1;

	run();

	vector<int> C;

	// A 0 인거 골라내서 C값 배열 저장
	for (int i = 0; i < 1000; i++) {
		if (visited[i][3] == 0)
			break;

		if (visited[i][0] == 0)
			C.push_back(visited[i][2]);
	}

	// C 배열 오름차순 정렬
	sort(C.begin(), C.end());

	// C 배열 출력
	for (int i = 0; i < C.size(); i++)
		cout << C[i] << " ";

	return 0;
}