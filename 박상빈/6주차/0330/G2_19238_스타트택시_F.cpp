#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
	int y;
	int x;
	int fuel;
};

struct Position {
	int guesty;
	int guestx;
	int goaly;
	int goalx;
};

int diry[4] = { -1, 0, 0, 1 };
int dirx[4] = { 0, -1, 1, 0 };

int n, m, fuel;
int Map[21][21];
bool isclear[1000];
Position guests[1000];
int y, x;
int tar;
Node last;

bool compare(const Position& left, const Position& right)
{
	if (left.guesty == right.guesty) return left.guestx < right.guestx;
	return left.guesty < right.guesty;
}

int find()
{
	bool visited[21][21] = { false, };
	queue<pair<int, int>> que;
	visited[y][x] = true;
	que.push({ y, x });

	while (!que.empty())
	{
		pair<int, int> now = que.front();
		que.pop();

		for (int i = 0; i < m; i++)
		{
			if (isclear[i]) continue;
			// target find
			if (now.first == guests[i].guesty && now.second == guests[i].guestx)
			{
				return i;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = now.first + diry[i];
			int nx = now.second + dirx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

			if (Map[ny][nx] == 1) continue;

			if (!visited[ny][nx])
			{
				visited[ny][nx] = true;
				que.push({ ny, nx });
			}
		}
	}

	return -1;
}

bool bfs(int gy, int gx, bool count)
{
	bool visited[21][21] = { false, };
	queue<Node> que;
	visited[y][x] = true;
	que.push({ y, x, 0 });

	while (!que.empty())
	{
		Node now = que.front();
		que.pop();

		if (now.y == gy && now.x == gx)
		{
			if (count)
			{
				if (now.fuel > fuel) return false;
			}
			else
			{
				if (now.fuel >= fuel) return false;
			}
			// 도착
			y = now.y;
			x = now.x;
			if (count)
			{
				fuel = (fuel - now.fuel) + (now.fuel * 2);
			}
			else fuel -= now.fuel;

			//cout << y << " " << now.y << " " << x << " " << now.x << " " << fuel << " " << now.fuel << endl;
			return true;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + diry[i];
			int nx = now.x + dirx[i];
			int nfuel = now.fuel + 1;

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

			if (Map[ny][nx] == 1) continue;

			if (!visited[ny][nx])
			{
				visited[ny][nx] = true;
				que.push({ ny, nx, nfuel });
			}
		}
	}

	return false;
}

int main()
{

	cin >> n >> m >> fuel;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> Map[i][j];
		}
	}

	cin >> y >> x;

	for (int i = 0; i < m; i++)
	{
		cin >> guests[i].guesty >> guests[i].guestx >> guests[i].goaly >> guests[i].goalx;
		guests[i].guesty--;
		guests[i].guestx--;
		guests[i].goalx--;
		guests[i].goaly--;
	}

	y--;
	x--;

	sort(guests, guests + m, compare);

	for (int i = 0; i < m; i++)
	{
		// 목표 설정
		int tar = find();
		if (tar == -1) {
			cout << -1;
			return 0;
		}
		isclear[tar] = true;
		bool clear;
		// 손님 태우기
		clear = bfs(guests[tar].guesty, guests[tar].guestx, false);
		if (!clear)
		{
			cout << -1;
			return 0;
		}
		//cout << i << " " << y << " " << x << " " << fuel << endl;
		// 손님 목적지로
		clear = bfs(guests[tar].goaly, guests[tar].goalx, true);
		if (!clear)
		{
			cout << -1;
			return 0;
		}
		// 모두 성공했다면
		// 택시의 위치와 연료 설정

		//cout << i << " " << y << " " << x << " " << fuel << endl;
	}

	cout << fuel;

	return 0;
}