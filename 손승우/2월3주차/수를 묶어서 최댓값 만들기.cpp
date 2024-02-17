#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;

	priority_queue<int> pq_up;
	priority_queue<int, vector<int>, greater<int>> pq_down;
	int one = 0;
	for (int i = 0; i < N; i++)
	{
		int a = 0;
		cin >> a;
		if (a <= 0)
		{
			pq_down.push(a);
		}
		else if(a > 1)
		{
			pq_up.push(a);
		}
		else if (a == 1)
		{
			one++;
		}
	}

	int mul_data = 0;
	int sum = 0;
	while (pq_up.size() > 2)
	{
		mul_data = pq_up.top();
		pq_up.pop();
		mul_data = mul_data * pq_up.top();
		pq_up.pop();
		sum = sum + mul_data;
	}
	if (pq_up.size() == 1)
	{
		sum = sum + pq_up.top();
	}
	else if (pq_up.size() == 2)
	{
		mul_data = pq_up.top();
		pq_up.pop();
		mul_data = mul_data * pq_up.top();
		pq_up.pop();
		sum = sum + mul_data;
	}

	while (pq_down.size() > 2)
	{
		mul_data = pq_down.top();
		pq_down.pop();
		mul_data = mul_data * pq_down.top();
		pq_down.pop();
		sum = sum + mul_data;
	}
	if (pq_down.size() == 1)
	{
		sum = sum + pq_down.top();
	}
	else if (pq_down.size() == 2)
	{
		mul_data = pq_down.top();
		pq_down.pop();
		mul_data = mul_data * pq_down.top();
		pq_down.pop();
		sum = sum + mul_data;
	}

	cout << sum+one << endl;


}