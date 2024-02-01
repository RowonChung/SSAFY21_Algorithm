#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int bowl[301][301];
int isSpace[301][301];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// 높이, 좌표 (높이는 낮은 순 정렬)
priority_queue < pair<int, pair<int, int>>> pq;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int c, r; cin >> c >> r;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> bowl[i][j];
			
			// 물을 담을 수 없는 위치 isSpace -> 1
			// 높이가 낮은 순서로 위치 저장 -> pq
			if (i == 0 || j == 0 || i == (r - 1) || j == (c - 1)) {
				isSpace[i][j] = 1;
				// 높이 오름차순 정렬 위해 -1 곱해서 저장
				pq.push({ -bowl[i][j], {i, j} }); 
			}
		}
	}

	int ans = 0;
	while (!pq.empty()) {
		int x = pq.top().second.first, y = pq.top().second.second;
		pq.pop();

		// 다음 위치 탐색
		// 주변 위치가 더 높다면 -> 물 담을 수 없음 : 바로 PQ에 추가
		// 낮다면 -> 현재 높이까지 담으면 더 이상 물 담을 수 없음
		//			 높이를 현재 높이로 바꿔준 후 PQ에 추가

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c || isSpace[nx][ny]) continue;

			// 물 담을 수 있는지 여부 검사
			if (bowl[nx][ny] >= bowl[x][y]) {
				isSpace[nx][ny] = 1;
				pq.push({ -bowl[nx][ny], {nx, ny} });
			}
			else {
				ans += (bowl[x][y] - bowl[nx][ny]);
				isSpace[nx][ny] = 1;

				bowl[nx][ny] = bowl[x][y];
				pq.push({ -bowl[nx][ny], {nx, ny} });
			}
		}
	}

	cout << ans;
	return 0;
}