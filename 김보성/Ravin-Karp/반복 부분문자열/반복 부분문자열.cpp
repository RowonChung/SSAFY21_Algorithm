#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
char str[200005];
const int p = 29;
const int MOD = 10007;
int Len; 
int pexp[200005];
vector<int> hashTable[10007];		//시작 index를 갖는다.
void pre();
void solve();
bool ok(int L);
void init();
bool real_match(int s1, int s2,int L);
int main() {
    pre();
    cin >> Len;
    solve();
}

void pre() {
    pexp[0] = 1;
    for (int i = 1; i <= 200000; i++) {
	    pexp[i] = pexp[i - 1] * p % MOD;
    }
}

void solve() {
    scanf("%s", str);
    int l = 0, r = Len;
    while (l < r) {
	    int m = (l + r + 1) / 2;
	    if (ok(m)) l = m;
	    else r = m - 1;
    }
    cout << l << endl;
}

bool ok(int L){
	init();		//길이 L의 중복 부분문자열이 존재하는지를 리턴
    int hash = 0;
    for (int i = 0; i < L; i++) {
	    hash *= p;
	    hash += str[i] - 'a';
	    hash %= MOD;
    }
    hashTable[hash].push_back(0);
    for (int i = L; i < Len; i++) {
		hash -= (str[i - L] - 'a') * pexp[L - 1] % MOD;
		hash = (hash + MOD) % MOD;
		hash *= p; hash += str[i] - 'a';
    	hash %= MOD;
    	if (hashTable[hash].size()) {
    		for (int idx : hashTable[hash]) {
    			if (real_match(idx, i - L + 1, L)) return true;
    		}
    	}
    	hashTable[hash].push_back(i-L+1);
    }
    return false;
}
    
void init() {
    for (int i = 0; i < MOD; i++) {
	    hashTable[i].clear();
    }
}

bool real_match(int s1, int s2, int L) {
	for (int i = 0; i < L; i++) {
		if (str[s1 + i] != str[s2 + i]) { 
        	return false; 
        } 
    } return true; 
}