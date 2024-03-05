#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
	int y, x, n;
};

int n, m;
int map[11][11];
int visited[11][11];
vector<Node> seomNode;
vector<Node> dari;

bool compare(Node t, Node v)
{
	return t.n < v.n;
}

int arr[7];

// »óÁÂÇÏ¿ì
int dir[4][2] = { -1, 0, 0, -1, 1, 0, 0, 1 };

void init()
{
	for (int i = 0; i < 7; i++) arr[i] = i;
} 

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
}

void divSeom(int sy, int sx, int num)
{
	queue<Node> q;
	q.push({ sy, sx });
	visited[sy][sx] = 1;

	while (!q.empty())
	{
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (map[ny][nx] == 0 || visited[ny][nx] != 0) continue;

			visited[ny][nx] = visited[now.y][now.x] + 1;
			map[ny][nx] = num;
			q.push({ ny, nx });
		}
	}
}

void makeDari(int i)
{
	Node now = seomNode[i];

	for (int i = 0; i < 2; i++)
	{
		int sy = now.y;
		int sx = now.x;

		int dariLen = 0;
		while (1)
		{
			int ny = sy + dir[i][0];
			int nx = sx + dir[i][1];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) break;
			if (map[ny][nx] == now.n) break;

			if (map[ny][nx] != 0 && map[ny][nx] != now.n)
			{
				dari.push_back({ now.n, map[ny][nx], dariLen});
				break;
			}

			dariLen++;

			sy = ny;
			sx = nx;
		}
	}
}

int find(int tar)
{
	if (arr[tar] == tar) return tar;

	int ret = find(arr[tar]);
	arr[tar] = ret;
	return ret;
}

void setUnion(int a, int b)
{
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2) return;

	arr[t2] = t1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	input();
	
	// ¼¶ ³ª´©±â
	int num = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0 || visited[i][j] != 0) continue;

			map[i][j] = num;
			divSeom(i, j, num);

			num++;
		}
	}

	// ¼¶ ÁÂÇ¥ ³Ö±â
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0) continue;
			seomNode.push_back({ i, j, map[i][j] });
		}
	}

	// »óÇÏÁÂ¿ì µ¹¸®±â
	for (int i = 0; i < seomNode.size(); i++)
	{
		makeDari(i);
	}

	// Å©·ç½ºÄ®
	sort(dari.begin(), dari.end(), compare);

	int until = num - 2;
	int result = 0;
	int selectCount = 0;

	for (Node sel : dari)
	{
		if (find(sel.y) == find(sel.x)) continue;
		if (sel.n < 2) continue;

		setUnion(sel.y, sel.x);

		result += sel.n;
		selectCount++;
		if (selectCount == until) break;
	}

	if (selectCount != until) cout << -1;
	else cout << result;

}