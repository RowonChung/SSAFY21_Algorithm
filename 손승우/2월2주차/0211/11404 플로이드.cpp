#include <iostream>
#include <vector>
using namespace std;
//플로이드 워셜은 시작점을 안정하고 모든 노드간의 최소 거리를 구할 수 있는 방법임. 하지만 N3이 걸림.
// 경유지를 기준으로 업데이트 함. 매우 직관적. 
int dist[101][101] = { INT_MAX, };

int main()
{
	int N, E;
	cin >>N >> E;
	

	for (int i = 0; i <= N; i++)
	{
		
		dist[i][i] = 0;
		
	}

	for (int i = 0; i < E; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;
		dist[s][e] = w;
	}

	for (int k = 1; k <= N; k++)
	{
		for (int s = 1; s <= N; s++)
		{
			for (int e = 1; e <= N; e++)
			{
				if (dist[s][e] > dist[s][k] + dist[k][e])
				{
					dist[s][e] = dist[s][k] + dist[k][e];
				}

			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (dist[i][j] == INT_MAX)
			{
				cout << 0 << " ";
			}
			else cout << dist[i][j] << " ";
		}
	}
}