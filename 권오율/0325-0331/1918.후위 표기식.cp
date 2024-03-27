#include <iostream>
#include <deque>
#include <string>
#include <cctype> // for isalnum
using namespace std;

deque<char> dq;
string input, ans;

int prev(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int main() {
    cin >> input;

    for (int i = 0; i < input.length(); i++) {
        if (isalnum(input[i])) {
            ans.push_back(input[i]);
        }
        else if (input[i] == '(') {
            dq.push_back(input[i]);
        }
        else if (input[i] == ')') {
            while (!dq.empty() && dq.back() != '(') {
                ans.push_back(dq.back());
                dq.pop_back();
            }
            if (!dq.empty()) dq.pop_back(); 
        }
        else {
            while (!dq.empty() && prev(dq.back()) >= prev(input[i])) {
                ans.push_back(dq.back());
                dq.pop_back();
            }
            dq.push_back(input[i]);
        }
    }
    while (!dq.empty()) {
        ans.push_back(dq.back());
        dq.pop_back();
    }
    cout << ans << endl;
    return 0;
}
