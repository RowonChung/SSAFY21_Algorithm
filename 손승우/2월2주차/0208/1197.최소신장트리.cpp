#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
typedef tuple<int, int, int> edge;
//최소 신장트리 -> 모든 노드를 연결할 때 사용된 에지들의 가중치의 합을 최소로 하는 트리임. (다익스트라나 벨만포드는 시작점으로 부터 최소거리) 그러면 최소 신장트리는 그중 최소를 리턴하는 트리인듯?
//1. 에지 리스트로 구현하고, 유니온 파인드 배열 초기화 하기.
//2. 에지리스트를 가중치를 기준으로 정렬함. 
//3. 그리고 작은 것부터 꺼내서 union해줌. 이때, 사이클을 형성하면 안되므로 find작업해서 대표노드가 다를때만 union해줌. 
//4. N개의 노드이면 다 연결한 에지는 N-1개임. 따라서, 이 과정을 연결된 에지가 N-1개일 떄 까지 반복해줌. 
vector<int> parent;
vector<edge> EM;

bool compare(const edge& a, const edge& b)
{
	return get<2>(a) < get<2>(b);
}

int find(int a)
{
	if (parent[a] == a)
	{
		return a;
	}
	else
	{
		return parent[a] = find(parent[a]);
	}
}
void munion(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
	{
		parent[b] = a;
	}
}


int main()
{
	int N, E;
	cin >> N >> E;
	parent.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		
		parent[i] = i;
	
	}
	for (int i = 1; i <= N; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;
		EM.push_back(make_tuple(s, e, w));
	}
	sort(EM.begin(), EM.end(), compare);
	
	int ednum = 0;
	int result = 0; 
	for (int i = 0; i < E; i++)
	{
		int s = get<0>(EM[i]);
		int e = get<1>(EM[i]);
		int w = get<2>(EM[i]);
		if (find(s) != find(e))
		{
			munion(s, e);
			result += w;
			ednum++;
		}
		if (ednum == N - 1) break;

	}
	cout << result;
}