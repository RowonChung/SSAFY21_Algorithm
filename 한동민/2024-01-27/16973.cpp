#include <iostream>
#include <queue>
using namespace std;

int R, C;
int rSize, cSize;

int arr[1001][1001];
int cnt[1001][1001];
bool visit[1001][1001];

int Move[4][2] = {
	{0,1},{1,0},{-1,0}, {0,-1}
};

bool check(int next_row, int next_col, int moving) {
	if (moving == 0) {
		for (int i = next_row; i <= next_row + rSize - 1; i++) {
			/*cout << "when moving index = " << moving << " row = " << i << " col = " << next_col + cSize - 1 << " ";
			cout << endl;*/
			if (arr[i][next_col + cSize-1] == 1) {
				return false;
			}
		}
		return true;
	}
	else if (moving == 1) {
		for (int i = next_col; i <= next_col + cSize-1; i++) {
			/*cout << "when moving index = " << moving << " row = " << next_row + rSize - 1 << " col = " << i << " ";
			cout << endl;*/
			if (arr[next_row+rSize-1][i] == 1) {
				return false;
			}
		}
		return true;
	}
	else if (moving == 2) {
		for (int i = next_col; i <= next_col + cSize-1; i++) {
		/*	cout << "when moving index = " << moving << " row = " << next_row << " col = " << i << " ";
			cout << endl;*/
			if (arr[next_row][i] == 1) {
				return false;
			}
		}  
		return true;
	}
	else{
		for (int i = next_row; i <= next_row + rSize-1; i++) {
			/*cout << "when moving index = " << moving << " row = " << i << " col = " << next_col << " ";
			cout << endl;*/
			if (arr[i][next_col] == 1) {
				return false;
			}
		}
		return true;
	}
}

void bfs(pair<int, int> start, pair<int, int> end) {
	queue<pair<int,int>> q;
	visit[start.first][start.second] = true;
	q.push(start);
	while (!q.empty()) {
		pair<int, int> current = q.front();
		q.pop();
		/*cout << "current = " << current.first << " " << current.second << endl;*/
		for (int i = 0; i < 4; i++) {
			int next_row = current.first + Move[i][0];
			int next_col = current.second + Move[i][1];
			if (0 < next_row && next_row <= R -rSize+1 && 0 < next_col && next_col <= C-cSize +1) {
				if (check(next_row, next_col , i) && !visit[next_row][next_col]) {
					cnt[next_row][next_col] = cnt[current.first][current.second] + 1;
					visit[next_row][next_col] = true;
					q.push(make_pair(next_row, next_col));
				}

			}
		}
	}
	if (cnt[end.first][end.second] == 0) {
		cout << -1;
	}
	else {
		cout << cnt[end.first][end.second];
	}
}


int main() {
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> rSize >> cSize;
	pair<int, int> start, end;
	cin >> start.first >> start.second;
	cin >> end.first >> end.second;
	if (start.first == end.first && start.second == end.second) {
		cout << -1;
		return 0;
	}
	bfs(start, end);
}
