#include <iostream>
#include <queue>
using namespace std;

struct NODE {
	int row;
	int col;
	int wall;
	bool operator <(const NODE& n) const {
		return wall > n.wall;
	}
};

int n, m;
int arr[200][200];
bool visit[200][200][200];

int mv[4][2] = {
	{0,1}, {1,0}, {0,-1}, {-1,0}
};

bool isRange(int row, int col) {
	if (1 <= row && row <= n && 1 <= col && col <= m) {
		return true;
	}
	return false;
}

int main() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++) {
			arr[i][j] = s[j - 1] - '0';
		}
	}
	priority_queue<NODE> pq;
	pq.push({ 1,1,0 });
	visit[0][1][1] = true;
	while (!pq.empty()) {
		NODE current = pq.top();
		/*cout << "row = " << current.row << " col = " << current.col << endl;
		cout << "cost = " << current.wall << endl;*/
		if (current.row == n && current.col == m) {
			cout << current.wall;
			return 0;
		}
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int nextRow = current.row + mv[i][0];
			int nextCol = current.col + mv[i][1];
			if (isRange(nextRow, nextCol)) {
				int nextWall;
				if (arr[nextRow][nextCol] == 0) {
					nextWall = current.wall;
					if (!visit[nextWall][nextRow][nextCol]) {
						pq.push({ nextRow,nextCol,nextWall });
						visit[nextWall][nextRow][nextCol] = true;
					}
				}
				else {
					nextWall = current.wall + 1;
					if (!visit[nextWall][nextRow][nextCol]) {
						pq.push({ nextRow,nextCol,nextWall });
						visit[nextWall][nextRow][nextCol] = true;
					}
				}
			}
		}
	}

}
