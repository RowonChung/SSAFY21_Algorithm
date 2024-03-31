#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

stack<char> answer;
string str, rm;

int main()
{
    cin >> str;
    cin >> rm;

    int rlen = (int)rm.length();

    // 뒤집기 싫으니까 뒤에서부터 검사
    for(int i=(int)str.length() - 1;i>=0;i--)
    {
        answer.push(str[i]);

        // 제거해야할 문장의 첫글자가 나오면 스택에서 비교
        if (str[i] == rm[0] && (int)answer.size() >= rlen)
        {
            string tmp = "";
            for(int j=0;j<rlen;j++)
            {
                tmp += answer.top();
                answer.pop();
            }

            // 제거할 문자와 일치하면 제거
            // 일치하지 않으면 도로 넣기
            if (tmp.compare(rm) != 0)
            {
                for (int i = rlen - 1; i >= 0; i--) answer.push(tmp[i]);
            }
        }
    }

    if (answer.empty()) cout << "FRULA";
    else
    {
        while (!answer.empty())
        {
            cout << answer.top();
            answer.pop();
        }
    }

    return 0;
}