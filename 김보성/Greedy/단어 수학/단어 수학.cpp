#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<cmath>
using namespace std;
int n;
int dat[11] = {};
int main()
{
	cin >> n;
	unordered_map<char, int> ump;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int i = 0; i < str.length(); i++)
		{
			if (ump[str[i]] == 0)
			{
				cnt++;
				ump[str[i]] = cnt;
			}
			dat[ump[str[i]]] += pow(10, str.length() - 1 - i);
		}
	}
	sort(dat, dat + 11);
	long long int ret = 0;
	for (int i = 0; i < 11; i++)
	{
		ret = ret + dat[i] * (i - 1);
	}
	cout << ret;
}