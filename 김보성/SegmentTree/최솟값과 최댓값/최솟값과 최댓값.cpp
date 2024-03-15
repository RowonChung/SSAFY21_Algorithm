#include<iostream>
#include<algorithm>

using namespace std;

int arr[100000] = {};
int treemx[400001] = {};
int treemn[400001] = {};
int n, m;
int initmx(int begin, int end, int node)
{
	if (begin == end)
		return treemx[node] = arr[begin];
	int mid = (begin + end) / 2;
	int l = initmx(begin, mid, node * 2);
	int r = initmx(mid + 1, end, node * 2 + 1);
	if (l > r) return treemx[node] = l;
	else return treemx[node] = r;
}

int initmn(int begin, int end, int node)
{
	if (begin == end)
		return treemn[node] = arr[begin];
	int mid = (begin + end) / 2;
	int l = initmn(begin, mid, node * 2);
	int r = initmn(mid + 1, end, node * 2 + 1);
	if (l<r) return treemn[node] = l;
	else return treemn[node] = r;
}

int findmx(int begin, int end, int node, int left, int right)
{
	if (left > end || right < begin)
		return 0;
	if (left <= begin && right >= end)
		return treemx[node];
	int mid = (begin + end) / 2;
	return max(findmx(begin, mid, node * 2, left, right), findmx(mid + 1, end, node * 2 + 1, left, right));
}
int findmn(int begin, int end, int node, int left, int right)
{
	if (left > end || right < begin)
		return 1000000001;
	if (left <= begin && right >= end)
		return treemn[node];
	int mid = (begin + end) / 2;
	return min(findmn(begin, mid, node * 2, left, right), findmn(mid + 1, end, node * 2 + 1, left, right));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	initmx(0, n - 1, 1);
	initmn(0, n - 1, 1);
	
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << findmn(0, n - 1, 1, a - 1, b - 1)<<' '<<findmx(0, n - 1, 1, a - 1, b - 1)<<'\n';
	}
}