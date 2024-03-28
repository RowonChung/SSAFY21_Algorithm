#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

struct Fish {
	int row, col, growth, cnt, time;
};

Fish Shark, tar;
vector <Fish> candi;
deque <Fish> dq;
int n, arr[22][22], visited[22][22];
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

void findTar();
bool compare(const Fish& l, const Fish& r);

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				Shark = { i, j, 2, 0, 0 };
			}
		}
	}
	while (true) {
		//먹이 초기화
		tar.row = -1, tar.col = -1;
		//먹이 확인
		findTar();

		//없으면 종료
		if (tar.row == -1 && tar.col == -1) break;
		//상어 이동
		arr[Shark.row][Shark.col] = 0;
		Shark.row = tar.row;
		Shark.col = tar.col;
		Shark.time = tar.time;
		//섭취
		arr[Shark.row][Shark.col] = 9;
		Shark.cnt++;
		//자신의 크기만큼 먹었으면 성장
		if (Shark.cnt == Shark.growth) {
			Shark.growth++;
			Shark.cnt = 0;
		}
	}
	cout << Shark.time;
}

void findTar() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
		}
	}

	int shortest = 1e9;
	
	visited[Shark.row][Shark.col] = 1;
	dq.push_back(Shark);
	while (!dq.empty()) {
		Fish curr = dq.front();
		dq.pop_front();

		if (shortest < curr.time) {
			dq.clear();
			break;
		}

		if (arr[curr.row][curr.col] != 0 && arr[curr.row][curr.col] != 9 && arr[curr.row][curr.col] < curr.growth) {
			candi.push_back({ curr.row, curr.col, arr[curr.row][curr.col], 0, curr.time });
			shortest = min(shortest, curr.time);
			continue;
		}


		for (int i = 0; i < 4; i++) {
			int nextR = curr.row + dr[i];
			int nextC = curr.col + dc[i];
			//범위 확인
			if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= n) continue;
			//자기보다 크면, 패스
			if (arr[nextR][nextC] > curr.growth) continue;
			//방문한 곳은 패스
			if (visited[nextR][nextC] == 1) continue;
			visited[nextR][nextC] = 1;
			dq.push_back({ nextR ,nextC, curr.growth, curr.cnt, curr.time + 1 });
		}
	}

	if (!candi.empty()) {
		sort(candi.begin(), candi.end(), compare);

		//for (auto el : candi) {
		//	cout << el.time << " " << el.row << " " << el.col << "\n";
		//}
		//cout << "\n";

		tar = { candi[0].row, candi[0].col, arr[candi[0].row][candi[0].col], 0, candi[0].time};
		candi.clear();
	}
}

bool compare(const Fish& l, const Fish& r) {
	if (l.time < r.time) return true;
	else if (l.time > r.time) return false;

	if (l.row < r.row) return true;
	else if (l.row > r.row) return false;

	if (l.col < r.col) return true;
	else return false;
}
