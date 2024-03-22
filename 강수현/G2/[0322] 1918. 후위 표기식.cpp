#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

stack<char>s;

int main() {
	string str;
	cin >> str;

	while (!str.empty()) {
		// 피연산자 출력
		if (str[0] >= 'A' && str[0] <= 'Z') {
			cout << str[0];
			str.erase(0, 1);
			continue;
		}

		// 연산자
		if (s.empty()) {
			s.push(str[0]);
			str.erase(0, 1);
			continue;
		}

		// 괄호 )
		if (str[0] == ')') {
			while (s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.pop();
			str.erase(0, 1);
			continue;
		}

		if (str[0] == '+' || str[0] == '-') {
			while (!s.empty() && s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.push(str[0]);
			str.erase(0, 1);
			continue;
		}

		if (str[0] == '*' || str[0] == '/') {
			while (!s.empty()) {
				if (s.top() != '*' && s.top() != '/') break;
				cout << s.top();
				s.pop();
			}
			s.push(str[0]);
			str.erase(0, 1);
			continue;
		}

		s.push(str[0]);
		str.erase(0, 1);
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}

	return 0;
}