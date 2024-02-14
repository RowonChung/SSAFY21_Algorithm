#include <iostream>
#include <vector>
using namespace std;

vector<int> A;
int main()
{
	int N, M;
	cin >> N >> M;
	
	//1. 숫자 받기.
	//2. max 구하기
	//3. 범위 => max ~ 다 더한거. 
	//4. max~다 더한거를 기준으로 이진탐색진행. 중앙값으로 들어갓는데 개수가 만약 부족하면 start를 늘림. 
												//중앙값으로 들어갔는데 만약 사이즈 넘치면 end를 줄임.
	//5. 만약 발견했음. 더작은거 보기위해 end를 줄임.
	
	A.resize(N);
	int max = 0;
	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> A[i];
		if (max < A[i])
		{
			max = A[i];
		}
		sum += A[i];
	}

	
	int start = max;
	int end = sum;
	int mid = 0;
	while (start <= end)
	{	
		mid= (start + end) / 2;
		int check = 0;
		int counter = 0;
		for (int i = 0; i < N; i++)
		{
			if (check + A[i] > mid)
			{
				counter++;
				check = 0;
			}
			check = check + A[i];

		}
		if (check != 0)
		{
			counter++;
		}
	
		if (counter < M)
		{
			end = mid - 1; 
		}
		else if (counter > M)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}

	}
	
	cout << start << endl;
}