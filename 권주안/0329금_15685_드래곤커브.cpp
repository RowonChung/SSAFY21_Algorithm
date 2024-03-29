#include <iostream>
using namespace std;

int N;
int dr[] = { 0,-1,0,1 };
int dc[] = { 1,0,-1,0 };
int totalBoard[101][101];
int tempBoard[101][101];
int temptempBoard[101][101];

void dfs(int axisY, int axisX, int readyY, int readyX, int generation) {
	if (generation == 0) {
		return;
	}
	int nextAxisY, nextAxisX;
	// 회전축에 대해 다음 기준점이 될 끝점이 1사분면에 존재한다면
	if (axisY > readyY && axisX <= readyX) {
		nextAxisY = axisY + (readyX - axisX);
		nextAxisX = axisX + (axisY - readyY);
	}
	// 회전축에 대해 다음 기준점이 될 끝점이 4사분면에 존재한다면
	else if (axisY <= readyY && axisX <= readyX) {
		nextAxisY = axisY + (readyX - axisX);
		nextAxisX = axisX - (readyY - axisY);
	}
	// 회전축에 대해 다음 기준점이 될 끝점이 3사분면에 존재한다면
	else if (axisY <= readyY && axisX > readyX) {
		nextAxisY = axisY - (axisX - readyX);
		nextAxisX = axisX - (readyY - axisY);
	}
	// 회전축에 대해 다음 기준점이 될 끝점이 2사분면에 존재한다면
	else if (axisY > readyY && axisX > readyX) {
		nextAxisY = axisY - (axisX - readyX);
		nextAxisX = axisX + (axisY - readyY);
	}
	for (int y = 0; y < 101; y++) {
		for (int x = 0; x < 101; x++) {
			if (tempBoard[y][x] == 1) {
				int rotateY, rotateX;
				// 회전축에 대해 다음 기준점이 될 끝점이 1사분면에 존재한다면
				if (axisY > y && axisX <= x) {
					rotateY = axisY + (x - axisX);
					rotateX = axisX + (axisY - y);
				}
				// 회전축에 대해 다음 기준점이 될 끝점이 4사분면에 존재한다면
				else if (axisY <= y && axisX <= x) {
					rotateY = axisY + (x - axisX);
					rotateX = axisX - (y - axisY);
				}
				// 회전축에 대해 다음 기준점이 될 끝점이 3사분면에 존재한다면
				else if (axisY <= y && axisX > x) {
					rotateY = axisY - (axisX - x);
					rotateX = axisX - (y - axisY);
				}
				// 회전축에 대해 다음 기준점이 될 끝점이 2사분면에 존재한다면
				else if (axisY > y && axisX > x) {
					rotateY = axisY - (axisX - x);
					rotateX = axisX + (axisY - y);
				}
				temptempBoard[rotateY][rotateX] = 1;
			}
		}
	}
	for (int y = 0; y < 101; y++) {
		for (int x = 0; x < 101; x++) {
			if (temptempBoard[y][x] == 1) {
				tempBoard[y][x] = 1;
			}
		}
	}
	dfs(nextAxisY, nextAxisX, readyY, readyX, generation - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int curve = 0; curve < N; curve++) {
		// tempBoard 초기화
		for (int y = 0; y < 101; y++) {
			for (int x = 0; x < 101; x++) {
				tempBoard[y][x] = 0;
				temptempBoard[y][x] = 0;
			}
		}
		int y, x, d, g;
		cin >> x >> y >> d >> g;
		int ny = y + dr[d];
		int nx = x + dc[d];
		tempBoard[y][x] = 1;
		tempBoard[ny][nx] = 1;
		// 다음 기준 점, 기준 아닌 끝점
		dfs(ny, nx, y, x, g);
		// tempBoard에 찍힌 점들을 totalBoard로 옮긴다.
		for (int y = 0; y < 101; y++) {
			for (int x = 0; x < 101; x++) {
				if (tempBoard[y][x] == 1) {
					totalBoard[y][x] = 1;
				}
			}
		}
	}
	int ans = 0;
	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			int cvCnt = 0;
			if (totalBoard[y][x] == 1) cvCnt++;
			if (totalBoard[y][x+1] == 1) cvCnt++;
			if (totalBoard[y+1][x] == 1) cvCnt++;
			if (totalBoard[y+1][x+1] == 1) cvCnt++;
			if (cvCnt == 4) {
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}