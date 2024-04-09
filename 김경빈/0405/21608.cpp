#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <unordered_map>
using namespace std;

struct Node {
	int y, x, good, empty;
};
int N, arr[21][21], student[401][401], num, good, ans, h[] = { 0, 1, 10, 100, 1000 };
int dy[] = { -1, 1, 0, 0 }, dx[] = { 0, 0, -1, 1 };
vector<Node> v;

bool cmp(Node &left, Node &right){
	if (left.good > right.good) return true;
	else if (left.good < right.good) return false;

	if (left.empty > right.empty) return true;
	else if (left.empty < right.empty) return false;

	if (left.y < right.y) return true;
	else if (left.y > right.y) return false;

	if (left.x < right.x) return true;
	else if (left.x > right.x) return false;

	return false;
}

void seat(int num) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j]) continue;
			int good = 0, empty = 0;
			for (int d = 0; d < 4; d++) {
				int dr = i + dy[d];
				int dc = j + dx[d];

				if (dr < 0 || dr >= N || dc < 0 || dc >= N) continue;
				if (arr[dr][dc] && student[num][arr[dr][dc]]) {
					good++;
				}
				else if (arr[dr][dc] == 0) {
					empty++;
				}
			}

			v.push_back({ i, j, good, empty });
		}
	}
	sort(v.begin(), v.end(), cmp);
	arr[v[0].y][v[0].x] = num;
	v.clear();
}

void happy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int who = arr[i][j], cnt = 0;
			for (int d = 0; d < 4; d++) {
				int dr = i + dy[d];
				int dc = j + dx[d];

				if (dr < 0 || dr >= N || dc < 0 || dc >= N) continue;

				if (student[who][arr[dr][dc]]) cnt++;
			}
			ans += h[cnt];
		}
	}
}

int main() {	
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N * N; i++) {
		cin >> num;
		for (int j = 0; j < 4; j++) {
			cin >> good;
			student[num][good] = 1;
		}

		seat(num);
	}
	happy();
	cout << ans;
}