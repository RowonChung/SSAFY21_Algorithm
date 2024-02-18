#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

int T, N;
string p;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for(int idx = 0; idx < T; idx++)
    {
        cin >> p;
        cin >> N;

        deque<int> AC;

        string input;

        cin >> input;

        string tmp = "";
        for(int i=0;i<input.length();i++)
        {
            if (input[i] >= '0' && input[i] <= '9')
            {
                tmp += input[i];
            }
            else if (tmp != "")
            {
                AC.push_back(stoi(tmp));
                tmp = "";
            }
        }

        bool clear = true;
        bool front = true;
        int thesize = (int)p.length();
        for(int i=0;i<thesize;i++)
        {
	        if (p[i] == 'R')
	        {
                if (front) front = false;
                else front = true;
	        }
            else if(p[i] == 'D')
            {
                if (AC.size() != 0)
                {
                    if (front) AC.pop_front();
                    else AC.pop_back();
                }
                else clear = false;
            }
        }

        if (clear)
        {
            cout << "[";
            int thesize = AC.size();
            for (int i = 0; i < thesize; i++)
            {
                if (front)
                {
                    cout << AC.front();
                    AC.pop_front();
                }
                else
                {
                    cout << AC.back();
                    AC.pop_back();
                }
                if (i != thesize - 1) cout << ",";
            }
            cout << "]\n";
        }
        else cout << "error\n";

        AC.clear();
    }


    return 0;
}