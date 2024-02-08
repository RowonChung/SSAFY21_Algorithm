#include <iostream>
#include <queue>
#include <map>
#include <climits>
using namespace std;

string input, output = "";
vector<char> v;
map<char, int> calc = { {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'(', 3},  {')', 3} };


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> input;
	for (char c : input) {
		if (c >= 'A' && c <= 'Z') {
			output += c;
		}
		else if (c == ')') {
			while (!v.empty() && v.back() != '(') {
				output += v.back();
				v.pop_back();
			}
			v.pop_back();
		}
		else if ((!v.empty() && v.back() == '(') || c == '(') {
			v.push_back(c);
		}
		
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			if (v.empty()) {
				v.push_back(c);
			}
			else {
				if (calc[v.back()] < calc[c]) {
					v.push_back(c);
				}
				else {
					while (!v.empty() && calc[v.back()] >= calc[c] && v.back() != '(') {
						output += v.back();
						v.pop_back();
						
					}
					v.push_back(c);
				}
			}
		}
	}
	while (!v.empty() && calc[v.back()] != 3) {
		output += v.back();
		v.pop_back();
	}
	cout << output;
}
