#include <iostream>
#include <queue>

using namespace std;

struct Edge
{
	int from;
	int to;
	int cost;
	bool operator<(Edge right) const
	{
		return cost > right.cost;
	}
};

int V, E;
int unf[10001];

priority_queue<Edge> pq;

void init()
{
	for (int i = 0; i <= V; i++) unf[i] = i;
}

int find(int tar)
{
	if (tar == unf[tar]) return tar;
	return unf[tar] = find(unf[tar]);
}

bool Union(int a, int b)
{
	int ta = find(a);
	int tb = find(b);

	if (ta == tb) return false;

	unf[tb] = ta;
	return true;
}

int main()
{

	cin >> V >> E;

	init();

	for(int i=0;i<E;i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;

		pq.push({ from, to, cost });
	}

	int n = V - 1;
	int answer = 0;
	while(n)
	{
		while(!pq.empty())
		{
			Edge now = pq.top();
			pq.pop();

			if (!Union(now.from, now.to)) continue;

			answer += now.cost;
			n--;
		}
	}

	cout << answer;


    return 0;
}