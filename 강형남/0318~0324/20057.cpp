#include <iostream>
#include <string>

using namespace std;

int dy[4] = {0,1,0,-1 };
int dx[4] = { -1,0,1,0};

int dy_sand[4][9] = {
	{-1,-1,-2,-1,0,1,1,2,1},
	{-1,0,0,1,2,1,0,0,-1},
	{1,1,2,1,0,-1,-1,-2,-1},
	{1,0,0,-1,-2,-1,0,0,1}

};
int dx_sand[4][9] = {
	{1,0,0,-1,-2,-1,0,0,1},
	{-1,-1,-2,-1,0,1,1,2,1},
	{-1,0,0,1,2,1,0,0,-1 },
	{1,1,2,1,0,-1,-1,-2,-1 }
};

double sand_val[9] = { 0.01,0.07,0.02,0.1,0.05,0.1,0.07,0.02,0.01 };

int map[505][505];

int N;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	int y = N / 2;
	int x = N / 2;

	int level = 1;
	int direction = 0;
	int cnt = 0;

	double answer = 0.0;

	while (true) {
		//방향전환
		if (cnt == level) {
			direction++;
			if (direction ==2) {
				level++;
			}
			if (direction == 4) {
				direction = 0;
				level++;
			}
			cnt = 0;
			continue;
		}

		if (y == 0 && x == 0) {
			break;
		}

		y = y + dy[direction];
		x = x + dx[direction];

		//현재 위치의 모래
		double now_sand = (double)map[y][x];
		map[y][x] = 0;
		//지금 나가떨어진 모래
		double now_sand_out = 0.0;

		//총합 
		double out_sand_sum = 0.0;

		//모래 계산
		for (int i = 0; i < 9; i++) {
			//현재 날아갈 모래
			double now_sand_to = now_sand * sand_val[i];
			out_sand_sum += (int)now_sand_to;

			int ny = y + dy_sand[direction][i];
			int nx = x + dx_sand[direction][i];
			//모래가 밖일경우
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) {
				answer += (int)now_sand_to;
				continue;
			}
			map[ny][nx] += (int)now_sand_to;
		}



		int ny = y + dy[direction];
		int nx = x + dx[direction];
		if(ny<N&&ny>=0&&nx<N&&nx>=0)
		{
			map[ny][nx] += (int)now_sand - (int)out_sand_sum;
		}
		else {
			answer+= (int)now_sand - (int)out_sand_sum;
		}

		cnt++; 
	}

	cout << (int)answer+map[0][0];
}

