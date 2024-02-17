#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int Map[9][9];
int wcnt = 0, bcnt = 0;

int diry[8] = {0, 0, 1, -1, -1, 1, -1, 1};
int dirx[8] = {1, -1, 0, 0, 1, 1, -1, -1};

void osello(int y, int x, int type)
{
	// 진행방향으로 type과 다른색이면 진행
	// 빈공간이 나오면 뒤집지 않음
	// type과 같은색이 나오면 지금까지의 경로에 있는 돌 뒤집기

	for (int i = 0; i < 8; i++)
	{
		bool isgo = false;
		for (int j = 1;; j++)
		{
			int ny = y + (diry[i] * j);
			int nx = x + (dirx[i] * j);

			if (ny < 0 || nx < 0 || ny >= n || nx >= n)
			{
				isgo = false;
				break;
			}

			if (j == 1)
			{
				if (type != Map[ny][nx]) isgo = true;
			}
			else
			{
				if (type == Map[ny][nx]) break;
				else if (Map[ny][nx] == 0) {
					isgo = false;
					break;
				}
			}
		}

		if (isgo)
		{
			for (int j = 1;; j++)
			{
				int ny = y + (diry[i] * j);
				int nx = x + (dirx[i] * j);

				if (ny < 0 || nx < 0 || ny >= n || nx >= n) break;

				if (type == Map[ny][nx] || Map[ny][nx] == 0) break;

				Map[ny][nx] = type;
			}
		}
	}
}

int main(int argc, char** argv)
{
	int t;

	cin >> t;

	for (int idx = 1; idx <= t; idx++)
	{

		cin >> n >> m;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				Map[i][j] = 0;
			}
		}

		int tmp = n / 2;

		Map[tmp - 1][tmp - 1] = 2;
		Map[tmp - 1][tmp] = 1;
		Map[tmp][tmp - 1] = 1;
		Map[tmp][tmp] = 2;

		for (int i = 0; i < m; i++)
		{
			int y, x, type;
			cin >> y >> x >> type;

			Map[y - 1][x - 1] = type;
			osello(y - 1, x - 1, type);
		}

		wcnt = 0;
		bcnt = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (Map[i][j] == 1) bcnt++;
				else if (Map[i][j] == 2) wcnt++;
			}
		}

		cout << "#" << idx << " " << bcnt << " " << wcnt << "\n";

	}



	return 0;
}