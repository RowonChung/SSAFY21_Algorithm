#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	stack<int> myStack;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		myStack.push(a);
	}

	int count = 0;
	int sum = 0;
	while (sum != K)
	{
		int top = myStack.top();
		if (top > K)
		{
			myStack.pop();
			continue;
		}
		else
		{
			int temp = 0;
			temp = sum + top;
			if (temp > K)
			{
				myStack.pop();
				continue;
			}
			sum = sum + top;
			count++;
		}
	}
	cout << count << endl;
}