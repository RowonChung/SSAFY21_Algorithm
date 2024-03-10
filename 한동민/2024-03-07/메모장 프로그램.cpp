#include <iostream>
#include <memory.h>
#include <deque>
#include <algorithm>
using namespace std;

int h, w;


pair<int, int> curser;
pair<int, int> last_curser;

deque<char> dq[310];

int alphabet[310][26];


void init(int H, int W, char mStr[])
{
	h = H;
	w = W;
	for (int i = 0; i < 310; i++) {
		dq[i].clear();
	}
	memset(alphabet, 0, sizeof(alphabet));
	curser.first = 0;
	curser.second = 0;
	last_curser.first = 0;
	last_curser.second = 0;
	int index = 0;
	while (1) {
		dq[curser.first].push_back(mStr[index]);
		alphabet[curser.first][mStr[index] - 'a']++;
		curser.second++;
		if (w <= curser.second) {
			curser.first++;
			curser.second = 0;
		}
		last_curser.second++;
		if (w <= last_curser.second) {
			last_curser.first++;
			last_curser.second = 0;
		}
		if (mStr[index + 1] == '\0') {
			break;
		}
		index++;
	}
	curser.first = 0;
	curser.second = 0;
	//cout << "curser = " << curser.first << " " << curser.second << endl;
	//cout << "last_curser = " << last_curser.first << " " << last_curser.second << endl;
}

void insert(char mChar)
{
	//cout << "curser = " << curser.first << " " << curser.second << " -> ";
	if (dq[curser.first].size() == curser.second) {
		dq[curser.first].push_back(mChar);
		alphabet[curser.first][mChar - 'a']++;
	}
	else {
		dq[curser.first].insert(dq[curser.first].begin() + curser.second, mChar);
		alphabet[curser.first][mChar - 'a']++;
		int index = curser.first;
		while (w < dq[index].size()) {
			dq[index + 1].push_front(dq[index].back());
			alphabet[index][dq[index].back() - 'a']--;	
			dq[index].pop_back();
			alphabet[index + 1][dq[index + 1].front() - 'a']++;
			index++;
		}
	}
	curser.second++;
	if (w <= curser.second) {
		curser.first++;
		curser.second = 0;
	}
	last_curser.second++;
	if (w <= last_curser.second) {
		last_curser.first++;
		last_curser.second = 0;
	}	
	//cout << "curser = " << curser.first << " " << curser.second << endl;
	//cout << "last_curser = " << last_curser.first << " " << last_curser.second << endl;

}

char moveCursor(int mRow, int mCol)
{
	if (mCol -1 < dq[mRow-1].size()) {
		curser.first = mRow - 1;
		curser.second = mCol - 1;
		//cout << "curser = " << curser.first << " " << curser.second << endl;
		return dq[curser.first][curser.second];
	}
	else {
		curser = last_curser;
		//cout << "curser = " << curser.first << " " << curser.second << endl;
		return '$';
	}
}

int countCharacter(char mChar)
{
	int res = 0;
	for (int i = curser.second; i < min(w, (int)dq[curser.first].size()); i++) {
		if (dq[curser.first][i] == mChar) {
			res++;
		}
	}
	int index = curser.first + 1;
	while (dq[index].size() != 0) {
		res += alphabet[index][mChar - 'a'];
		index++;
	}
	/*cout << "res = " << res << endl;*/
	return res;
}
