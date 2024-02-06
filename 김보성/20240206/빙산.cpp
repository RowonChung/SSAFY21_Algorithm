#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int y, x;

int field[300][300] = {};
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
int cnt = 0;
int year = 0;


int maxh = 0;
int my, mx;
void update()
{
	int cp[300][300] = {};
	for (int cy = 0; cy < y; cy++)
	{
		for (int cx = 0; cx < x; cx++)
		{
			int melt = 0;
			if (field[cy][cx] == 0)
				continue;
			for (int cycle = 0; cycle < 4; cycle++)
			{
				int ny = cy + dy[cycle];
				int nx = cx + dx[cycle];
				if (ny < 0 || nx < 0 || ny >= y || nx >= x)
					continue;
				if (field[ny][nx] == 0)
					melt++;
			}
			cp[cy][cx] = field[cy][cx] - melt;
			if (cp[cy][cx] <= 0)
			{
				cp[cy][cx] = 0;
				cnt--;
			}
		}
	}
	int nmaxh = 0;
	int nmy, nmx;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			field[i][j] = cp[i][j];
			if (nmaxh <= field[i][j])
			{
				nmaxh = field[i][j];
				nmy = i;
				nmx = j;
			}
		}
	}
	maxh = nmaxh;
	my = nmy;
	mx = nmx;
}

void bfs(int result)
{
	bool used[300][300] = {};
	int now = 0;
	queue<pair<int, int>> q;
	q.push({ my,mx });
	used[my][mx] = true;
	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		now++;
		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (!used[ny][nx] && field[ny][nx])
			{
				used[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
	}
	if (now != cnt)
	{
		year = result;
	}
}

int main()
{
	cin >> y >> x;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			cin >> field[i][j];
			if (field[i][j])
				cnt++;
			if (field[i][j] > maxh)
			{
				maxh = field[i][j];
				my = i;
				mx = j;
			}
		}
	}
	int result = 0;
	while (maxh&&!year)
	{
		bfs(result);
		result++;
		update();
	}
	cout << year;
}