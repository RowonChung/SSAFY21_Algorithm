#include <iostream>
using namespace std;

int arr[20000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int card;
		cin >> card;

		arr[card + 10000000]++;
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int card;
		cin >> card;
	
		cout << arr[card + 10000000] << " ";
	}

}