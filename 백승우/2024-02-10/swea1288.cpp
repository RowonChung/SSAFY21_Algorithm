#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int finished = (1 << 10) - 1;

		int n;
		cin >> n;

		int used = 0;
		int k = 0;
		while (true) {
			string str_num = to_string(n * (++k));
			for (char c : str_num) {
				int num = c - '0';
				used |= (1 << num);
			}
			if (used == finished) break;
		}
		cout << "#" << test_case << " " << n * k << '\n';
	}
	return 0;
}
