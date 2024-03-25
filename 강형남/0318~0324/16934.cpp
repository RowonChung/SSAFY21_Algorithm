#include <iostream>
#include <string>
#include <map>
using namespace std;

class node {
public:
	node* child[26] = { NULL };

	node() {}
};

struct ret {
	string s="";
	bool finished = false;;
};

map<string, int> m;

class trie {
public:
	node* root;
	trie() { this->root = new node(); };

	ret insert(string s) {
		ret r;
		node* cur = this->root;
		for (int i = 0; i < s.size(); i++) {
			if (cur->child[s.at(i) - 'a'] == NULL) {
				if (r.finished == false) {
					r.s += s.at(i);
				}
				r.finished = true;
				
				cur->child[s.at(i) - 'a'] = new node();
				cur = cur->child[s.at(i) - 'a'];

			}
			else {
				r.s += s.at(i);
				cur = cur->child[s.at(i) - 'a'];
			}
		}
		return r;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;

	trie tr;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s; 
		cin >> s;
		m[s]++;
		ret r;
		r = tr.insert(s);
		if (r.s == s) {
			if (m[s] != 1) {
				cout << s << m[s] << "\n";
			}
			else {
				cout << s << "\n";
			}
		}
		else {
			cout << r.s << "\n";
		}
		
	}
}

