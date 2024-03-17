#include <iostream>
#include <queue>

using namespace std;

struct Node
{
	int y;
	int x;
	int cost;
	bool operator<(Node right) const
	{
		return cost > right.cost;
	}
};

int n;
int Map[101][101];
int dist[101][101];

int diry[4] = {0, 0, 1, -1};
int dirx[4] = {1, -1, 0, 0};

void dijkstra()
{
	// 00 -> n-1n-1
	priority_queue<Node> pq;

	dist[0][0] = 0;
	pq.push({ 0, 0, 0 });

	while(!pq.empty())
	{
		Node now = pq.top();
		pq.pop();

		for(int i=0;i<4;i++)
		{
			int ny = now.y + diry[i];
			int nx = now.x + dirx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

			int ncost = now.cost + Map[ny][nx];

			if (dist[ny][nx] <= ncost) continue;

			dist[ny][nx] = ncost;
			pq.push({ ny, nx, ncost });
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				char input;
				cin >> input;

				Map[i][j] = (input - '0');

				dist[i][j] = 21e8;
			}
		}

		dijkstra();

		cout << "#" << test_case << " " << dist[n - 1][n - 1] << "\n";

	}
	return 0;
}