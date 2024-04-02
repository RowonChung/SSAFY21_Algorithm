#include <iostream>
#include <vector>
using namespace std;

// 0: x ����, 1: y ����, 2: x ����, 3: y ����
// ��, ��, ��, ��
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
			// 0����
			if (i == 0) {
				curves.push_back(d);
				continue;
			}

			// 1���� - ó�� ������ 0 <-> 1, 2 <-> 3
			else if (i == 1) {
				curves.push_back((curves[0] + 1) % 4);
				continue;
			}

			// 2���� �̻�
			// 2���� - 2��, 3���� - 4��, 4���� - 8�� �߰� ...
			int add = 1;
			for (int j = 0; j < i - 1; j++) {
				add *= 2;
			}

			int curveSize = curves.size();
			for (int j = 0; j < curveSize / 2; j++) {
				// curve �������� ���ݱ����� 0 <-> 2, 1 <-> 3 �߰�
				curves.push_back(curves[j] ^ 2);
			}
			for (int j = curveSize / 2; j < curveSize; j++) {
				// ������ ������ �״�� �߰�
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

	// ���簢�� ã��
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