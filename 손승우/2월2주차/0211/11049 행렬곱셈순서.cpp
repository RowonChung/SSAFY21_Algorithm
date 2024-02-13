#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
int N;
int D[502][502];
vector<pair<int, int>> M;
int excute(int s, int e)
{
	int result = INT_MAX;
	if (D[s][e] != -1) //이미 계산해서 메모이제이션 된것은 바로 리턴. 
	{
		return D[s][e];
	}
	if (s == e) //행렬 크기 1
	{
		return D[s][e] = 0;
	}
	if (s + 1 == e) //행렬 크기 2
	{
		return D[s][e] = M[s].first * M[e].first * M[e].second;
	}
	for (int i = s; i < e; i++) //행렬 크기 3
	{
		result =  min(result, M[s].first * M[i].second * M[e].second + excute(s, i) + excute(i + 1,	e));
	}
	return D[s][e] = result;
}

int main()
{
	cin >> N;
	//N M M K => N M K 번 곱셈연산한다. 
	fill(&D[0][0], &D[501][502], -1);
	M.resize((N + 1));
	for (int i = 1; i <= N; i++)
	{
		int a, b;
		cin >> a >> b;
		//D[i] = D[i-1] + pair<int,int> i-1랑 새로운거의 행렬곱 과 D[i-2] + 맨뒤에 있는거랑 새로운거 중 최대 
		//pair<int int>
		//
		M[i] = make_pair(a, b);
	}

	cout << excute(1, N) << endl;

}