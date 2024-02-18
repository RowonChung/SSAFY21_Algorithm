#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	/*
	1. 문자 주어지면 포인터 옮겨가며 의심 범위에 있는지 check
	2. 의심 문자라면 포인터하나 더 가지고 검사.
	3. 검사 통과되면 그대로 가고
	4. 검사에 걸리면 cnt ++ 하고 포인터 그 다음거로 옮겨줌. 
	*/
	string s;
	cin >> s;
	int p1= 0;
	int cnt = 0;
	while (p1 != s.size())
	{
		if (s[p1] == 'c')
		{
			int p2 = p1+1;
			if (p1 != s.size() - 1 && (s[p2] == '=' || s[p2] == '-'))
			{
				cnt++;
				p1 = p2 + 1;
			}
			else
			{
				cnt++;
				p1++;
			}
		}
		else if (s[p1] == 'd')
		{
			int p2 = p1 + 1;
			if (p1 != s.size() - 1 && s[p2] == '-')
			{
				cnt++;
				p1 = p2 + 1;
			}
			else if (p1 != s.size() - 2 && s[p2] == 'z' && s[p2+1] == '=')
			{
				cnt++;
				p1 = p2 + 2;
			}
			else
			{
				cnt++;
				p1++;
			}
		}
		else if (s[p1] == 'l')
		{
			int p2 = p1 + 1;
			if (p1 != s.size() - 1 && s[p2] == 'j')
			{
				cnt++;
				p1 = p2 + 1;
			}
			else
			{
				cnt++;
				p1++;
			}
		}
		else if (s[p1] == 'n')
		{
			int p2 = p1 + 1;
			if (p1 != s.size() - 1 && s[p2] == 'j')
			{
				cnt++;
				p1 = p2 + 1;
			}
			else
			{
				cnt++;
				p1++;
			}
		}
		else if (s[p1] == 's')
		{
			int p2 = p1 + 1;
			if (p1 != s.size() - 1 && s[p2] == '=')
			{
				cnt++;
				p1 = p2 + 1;
			}
			else
			{
				cnt++;
				p1++;
			}
		}
		else if (s[p1] == 'z')
		{
			int p2 = p1 + 1;
			if (p1 != s.size() - 1 && s[p2] == '=')
			{
				cnt++;
				p1 = p2 + 1;
			}
			else
			{
				cnt++;
				p1++;
			}
		}
		else
		{
			cnt++;
			p1++;
		}
	}
	cout << cnt;
}