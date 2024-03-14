#include<iostream>
#include<queue>
#include<vector>
using namespace std;


int arr[501][501] = {};
int dist[501][501] = {};
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
struct pos {
	int y, x;
};
struct edge {
	pos to;
	int cost;
};
bool operator<(edge l, edge r)
{
	if (l.cost < r.cost) return false; 
	if (l.cost > r.cost) return true;
	if (l.to.y < r.to.y) return false;
	if (l.to.y > r.to.y) return true;
	if (l.to.x < r.to.x) return false;
	if (l.to.x > r.to.x) return true;
	return true;
}
vector<edge> edges[501][501];
void overlap(int a, int b, int c, int d, int val)
{
	int sy = min(a, c);
	int ey = max(a, c);

	int sx = min(b, d);
	int ex = max(b, d);
	for (int i = sy; i <= ey; i++)
	{
		for (int j = sx; j <= ex; j++)
			arr[i][j] = max(arr[i][j], val);
	}
}
bool used[501][501] = {};
int main()
{
	for (int i = 0; i < 501; i++)
	{
		for (int j = 0; j < 501; j++)
			dist[i][j] = 213456789;
	}
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		overlap(a, b, c, d, 1);
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		overlap(a, b, c, d, 2);
	}
	dist[0][0] = 0;
	for (int i = 0; i < 501; i++)
	{
		for (int j = 0; j < 501; j++)
		{
			if (arr[i][j] == 2)
				continue;
			for (int k = 0; k < 4; k++)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 0 || nx < 0 || ny>500 || nx>500)
					continue;
				if (arr[ny][nx] == 2)
					continue;
				edges[ny][nx].push_back({ {i,j},arr[i][j] });
			}
		}
	}
	if (arr[0][0] == 2)
	{
		if (arr[0][1] != 2)
			edges[0][0].push_back({ {0,1},arr[0][1] });
		if(arr[1][0]!=2)
			edges[0][0].push_back({ {1,0},arr[1][0] });
	}
	priority_queue<edge> pq;
	pq.push({ {0,0},0 });
	while (!pq.empty())
	{
		pos nowpos = pq.top().to;
		int nowcost = pq.top().cost;
		pq.pop();
		if (used[nowpos.y][nowpos.x])
			continue;
		used[nowpos.y][nowpos.x] = true;
		for (int i = 0; i < edges[nowpos.y][nowpos.x].size(); i++)
		{
			pos nextpos = edges[nowpos.y][nowpos.x][i].to;
			int nextcost = edges[nowpos.y][nowpos.x][i].cost+nowcost;
			if (dist[nextpos.y][nextpos.x] <= nextcost)
				continue;
			dist[nextpos.y][nextpos.x] = nextcost;
			pq.push({ nextpos,nextcost });
		}
	}
	if (dist[500][500] == 213456789)
		cout << -1;
	else
		cout << dist[500][500];
}