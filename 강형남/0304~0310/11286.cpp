#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

struct compare
{
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b))
			return a > b;
		else
			return abs(a) > abs(b);
	}
};

int main()
{
	int n; 
	cin >> n;

	priority_queue< int, vector<int>, compare > pq;

	for(int i=0;i<n;i++)
	{
		int number; 
		cin >> number;

		if (number == 0)
		{
			if (pq.empty())
			{
				cout << '0' << '\n';
			}
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
		{
			pq.push(number);
		}
	}
	return 0;
}