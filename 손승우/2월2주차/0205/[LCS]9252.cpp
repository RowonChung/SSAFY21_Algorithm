#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<char> Path;
string s1, s2;
int map[1001][1001] = { 0, };
void getText(int r, int c)
{
	if (r == 0 || c == 0) {
		return;
	}
	if (s1[r-1] == s2[c-1]) {
		Path.push_back(s1[r-1]);
		getText(r - 1, c - 1);
	}
	else {
		if (map[r - 1][c] > map[r][c - 1]) {
			getText(r - 1, c);
		}
		else {
			getText(r, c - 1);
		}
	}
		

}

int main()
{
	Path.clear();
	fill(&map[0][0], &map[1000][1001], 0);

	cin >> s1 >> s2;
	int N = s1.size();
 	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				map[i][j] = map[i - 1][j - 1] + 1;
			}
			else
			{
				map[i][j] = max(map[i - 1][j], map[i][j - 1]);
			}
		}
	}
	cout << map[N][N] << endl; //최장 공통 수열 길이.

	getText(N, N);
	for (int i = N - 1; i >= 0; i++) {
		cout << Path[i] << " ";
	}

}
