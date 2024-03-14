#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int T;
int n, m;
int a[20001];
int b[20001];

void init()
{
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
}

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
}

int twoPointer()
{
	int ans = 0;

	sort(a, a + n, greater<>());
	sort(b, b + m, greater<>());

	int p1 = 0, p2 = 0;

	while (p2 != m)
	{
		if (a[p1] > b[p2])
		{
			ans += m - p2;
			p1++;
		}
		else
		{
			p2++;
		}
	}

	return ans;
}


int main()
{
	cin >> T;

	while (T--) 
	{
		init();
		input();

		cout << twoPointer() << "\n";

	}

}