#include <iostream>
#include <vector>
using namespace std;

// 0: x 증가, 1: y 감소, 2: x 감소, 3: y 증가
// 우, 상, 좌, 하
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int map[101][101] = { 0 };
	vector<int> curves;

	int minY = 1e9, maxY = 0;
	int minX = 1e9, maxX = 0;

	while (n--) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;

		for (int i = 0; i <= g; i++) {
			// 0세대
			if (i == 0) {
				curves.push_back(d);
				continue;
			}

			// 1세대 - 처음 방향이 0 <-> 1, 2 <-> 3
			else if (i == 1) {
				curves.push_back((curves[0] + 1) % 4);
				continue;
			}

			// 2세대 이상
			// 2세대 - 2개, 3세대 - 4개, 4세대 - 8개 추가 ...
			int add = 1;
			for (int j = 0; j < i - 1; j++) {
				add *= 2;
			}

			int curveSize = curves.size();
			for (int j = 0; j < curveSize / 2; j++) {
				// curve 사이즈의 절반까지는 0 <-> 2, 1 <-> 3 추가
				curves.push_back(curves[j] ^ 2);
			}
			for (int j = curveSize / 2; j < curveSize; j++) {
				// 나머지 절반은 그대로 추가
				curves.push_back(curves[j]);
			}
		}

		if (map[y][x] == 0) map[y][x] = 1;

		for (int i = 0; i < curves.size(); i++) {
			int nowCurve = curves[i];

			if (minY > y) minY = y;
			else if (maxY < y) maxY = y;

			if (minX > x) minX = x;
			else if (maxX < x) maxX = x;

			y += dy[nowCurve];
			x += dx[nowCurve];

			if (map[y][x] == 1) continue;
			map[y][x] = 1;
		}

		curves.clear();

	}

	int de = -1;

	int visited[101][101] = { 0 };
	int cntSquare = 0;

	// 정사각형 찾기
	for (int row = minY; row <= maxY; row++) {
		for (int col = minX; col <= maxX; col++) {
			if (map[row][col] == 0) continue;
			if (visited[row][col] == 1) continue;

			visited[row][col] = 1;
			if (row + 1 > 100 || col + 1 > 100) continue;
			if (map[row][col + 1] == 1 && map[row + 1][col] == 1 && map[row + 1][col + 1] == 1) cntSquare++;
		}
	}

	cout << cntSquare;
}