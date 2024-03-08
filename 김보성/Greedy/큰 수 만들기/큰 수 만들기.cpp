#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

bool comp(string a, string b)
{
	string tmp1 = a + b;
	string tmp2 = b + a;
	for (int i = 0; i < a.length() + b.length(); i++)
	{
		if (tmp1[i] > tmp2[i])
			return true;
		else if (tmp1[i] < tmp2[i])
			return false;
	}
	return a.length() < b.length();
}


int main()
{
	int n;
	cin >> n;
	vector<string> v;
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end(), comp);
	if (v[0] == "0")
		cout << 0;
	else
		for (int i = 0; i < n; i++)
			cout << v[i];
}