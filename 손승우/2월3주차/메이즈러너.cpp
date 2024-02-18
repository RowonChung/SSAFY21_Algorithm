#include <iostream>
#include <algorithm>
#include <math.h>
#define NM 15
using namespace std;
int maze[NM][NM] = { 0, };
//maze[i][j]
//0-> 빈칸
//-1~--9 -> 벽을 의미하고, 내구도는 양수 버전
//-10-> 출구
// 1 이상의 자연수 -> 해당 칸에 존재하는 참가자 수

int N, M, K; //미로의 크기, 참가자의 수, 게임 시간
int moveCnt; // 모든 참가자들의 이동거리 합

void input() //입력
{
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int x;
			cin >> x;
			maze[i][j] = -x;
		}
	}
	for (int i = 1; i <= M; i++)
	{
		int x, y;
		cin >> x >> y;
		maze[x][y]++;
	}
	int x, y;
	cin >> x >> y;
	maze[x][y] = -10;
}


pair<int, int> findExit()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (maze[i][j] == -10)
			{
				pair<int, int> exit;
				exit.first = i;
				exit.second = j;
				return exit;
			}

		}
	}
}

void moveall() //이동
{
	int newMaze[15][15] = { 0, }; //이동결과를 저장할 배열
	auto ex = findExit();
	int dist[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} }; //상하좌우로 인접한 네방향

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (maze[i][j] < 0) //해당격자에 사람이 없다면
			{
				newMaze[i][j] = maze[i][j];
				continue;
			}
			if (maze[i][j] == 0)
			{
				continue;
			}

			int curDist = abs(i - ex.first) + abs(j - ex.second);
			int minDist = curDist, minI, minJ; //움직인후 최소 거리, 움직인후 최소의 y,x 좌표

			for (int k = 0; k < 4; k++) //4방향 탐색 상하좌우
			{
				int ni = i + dist[k][0];
				int nj = j + dist[k][1];
				// (i , j) => (ni, nj)
				if (ni < 1 || nj < 1 || ni > N || nj > N) continue; //격자를 넘으면 안되고
				if (-9 <= maze[ni][nj] && maze[ni][nj] <= -1) continue; //벽이 있으면 안되고
				int dist = abs(ni - ex.first) + abs(nj - ex.second);//출구와 (ni, nj) 사이의 거리
				if (minDist > dist)
				{
					minDist = dist;
					minI = ni;
					minJ = nj;
				}
				

			}
			//만약 아무것도 갈 수가 없는경우. 
			if (minDist == curDist)
			{
				newMaze[i][j] += maze[i][j]; 
				continue;
			}

			//움직인 경우 
			moveCnt += maze[i][j];

			//탈출에 성공할 경우 
			if (maze[minI][minJ] == -10)
			{
				continue;
			}

			newMaze[minI][minJ] += maze[i][j];
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			maze[i][j] = newMaze[i][j];
		}
	}
}

void subrotate(int x, int y, int d)
{
	int a[NM][NM] = { 0, }; //더미 배열생성 
	int b[NM][NM] = { 0, };
	//회전해야하는 부분을 a[1][1]부터 시작하도록 옮기기
	for (int i = x; i <= x + d; i++)
	{
		for (int j = y; j <= y + d; j++)
		{
			a[i - x + 1][j - y + 1] = maze[i][j];
		}
	}

	int n = d + 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (-9 <= a[i][j] && a[i][j] <= -1)
			{
				a[i][j]++;
			}
			b[j][n + 1 - i] = a[i][j];
		}
	}

	//미로 복원
	for (int i = x; i <= x + d; i++)
	{
		for (int j = y; j <= y + d; j++)
		{
			maze[i][j] = b[i - x + 1][j - y + 1];
		}
	}


}


void rotate() //회전
{
	//1. 가장 작은 정사각형 찾기 
	int minDist = 100000;
	auto ex = findExit();
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (maze[i][j] <= 0) continue; //벽이나 사람 없으면 건너 뜀. 
			int dist = max(abs(i - ex.first) , abs(j - ex.second));
			if (minDist > dist)
			{
				minDist = dist;
			}
		}
	}
	
	//2. 정사각형 위치를 그다음으로 결정하자. 
	int bestRow = 0, bestCol = 0;
	for (int i = 1; i <= N-minDist; i++)
	{
		for (int j = 1; j <= N-minDist; j++)
		{
			bool flagExit = false, flagPerson = false;
			for (int r = i; r <= i + minDist; r++)
			{
				for (int c = j; c <= j + minDist; c++)
				{
					if (maze[r][c] == -10)
					{
						flagExit = true;
					}
					else if (maze[r][c] > 0)
					{
						flagPerson = true;
					}
				}
			}
			if (flagExit == true && flagPerson == true)
			{
				bestRow = i;
				bestCol = j;
				break;
			}
		}
		if (bestRow != 0) break;
	}
	//3. 회전하고 내구도 1깎음. 
	subrotate(bestRow, bestCol, minDist);

}




void output() //정답 출력
{
	cout << moveCnt << "\n";
	auto exit = findExit();
	cout << exit.first << " " <<  exit.second;
}

bool finish()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (maze[i][j] > 0) return false;
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	fill(&maze[0][0], &maze[NM - 1][NM], 0);
	//입력 받기
	input();
	while (K--) //입력받은 정보로 시뮬레이션 진행 
	{
		//1. 모든 참가자들을 한칸씩 이동시키기.
		moveall(); 
		//2. 출구와 참가자들을 포함한 회전.
		if (finish())break;

		rotate();
	}
	output();


	return 0;
}