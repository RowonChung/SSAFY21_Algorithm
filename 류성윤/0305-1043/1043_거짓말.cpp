#include <iostream>
#include <vector>
using namespace std;

int arr[64];
vector<vector<int>> vv;
int N, M;
int truthNum;

void initTop() {
	for (int i = 0; i <= N; i++)
		arr[i] = i;
}

int findTop(int n) {
	if (arr[n] == n) return n;
	int ret = findTop(arr[n]);
	arr[n] = ret;
	return ret;
}

void setUnion(int a, int b) {
	int t1 = findTop(a);
	int t2 = findTop(b);
	if (t1 == t2) return;
	arr[t2] = t1;
}

int main() {
	cin >> N >> M;
	cin >> truthNum;
	int topNum = 0;
	initTop();
	int answer = 0;
	for (int i = 0; i < truthNum; i++) {
		int a; cin >> a;
		if (i == 0) topNum = a;
		setUnion(topNum, a);
	}

	for (int i = 0; i < M; i++) {
		int inputNum; cin >> inputNum;
		bool flag = false;
		vector<int> tmpV;
		for (int j = 0; j < inputNum; j++) {
			int a; cin >> a;
			if (truthNum && !flag && findTop(a) == topNum)
				flag = true;
			tmpV.push_back(a);
		}

		if (flag) {
			for (auto x : tmpV) {
				setUnion(topNum, x);
			}
		}
		else {
			vv.push_back(tmpV);
		}
	}
	for (auto iter = vv.begin(); iter != vv.end();) {
		bool reflag = false;
		for (auto x : *iter) {
			if (findTop(x) == topNum) {
				reflag = true;
				break;
			}
		}
		if (reflag) {
			for (auto x : *iter)
				setUnion(topNum, x);
			vv.erase(iter);
			iter = vv.begin();
		}
		else {
			++iter;
		}
	}

	cout << vv.size() << endl;
}