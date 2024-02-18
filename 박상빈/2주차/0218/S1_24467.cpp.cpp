#include <iostream>

using namespace std;

int main()
{
	int limit = 10;

	bool five = false;
	bool eight = false;
	bool ten = false;

	int sum = 0;

	for(int i=0;i<limit;i++)
	{
		string input;
		cin >> input;

		int cnt = 0;
		for(int j=0;j<input.length();j++)
		{
			if (input[j] == '0') cnt++;
		}

		switch(cnt)
		{
			case 0:
				limit++;
				sum += 5;
				break;
			case 1:
				sum += 1;
				break;
			case 2:
				sum += 2;
				break;
			case 3:
				sum += 3;
				break;
			case 4:
				limit++;
				sum += 4;
				break;
			default:
				break;
		}

		if (sum == 5) five = true;
		else if (sum == 8) eight = true;
		else if (sum == 10) ten = true;

	}

	if (sum >= 21) cout << "WIN";
	else if (sum >= 17 && (five || ten)) cout << "WIN";
	else if (sum >= 12 && five && eight) cout << "WIN";
	else cout << "LOSE";


	return 0;
}