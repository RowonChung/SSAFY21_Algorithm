#include<iostream>
#define MOD 1000000007
using namespace std;
int arr[1000001] = {};
long long int tree[4000004 ] = {};
int n, m, k;
int last=1;
long long int init(int begin, int end, int node)
{
	if (begin == end)
		return tree[node] = arr[begin];
	int mid = (begin + end) / 2;
	return tree[node] = ((init(begin, mid, node * 2)) * (init(mid + 1, end, node * 2 + 1))) % MOD;
}

long long int find(int begin, int end, int node, int left, int right)
{
	if (left > end || right < begin)
		return 1;
	if (left <= begin && right >= end)
		return tree[node];
	int mid = (begin + end) / 2;
	return (find(begin, mid, node * 2, left, right) * find(mid + 1, end, node * 2 + 1, left, right)) % MOD;
}

long long int update(int begin, int end, int node, int idx, int val)
{
	if (idx<begin || idx>end)
		return tree[node];
	if (begin == end)
		return tree[node] = val;
	int mid = (begin + end) / 2;
	return tree[node] = (update(begin, mid, node * 2, idx, val) * update(mid + 1, end, node * 2 + 1, idx, val)) % MOD;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	init(0, n - 1, 1);
	for (int i = 0; i < m+k; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			update(0, n - 1, 1, b - 1, c);
		}
		else
		{
			cout << find(0, n - 1, 1, b - 1, c - 1) << '\n';
		}
	}
}