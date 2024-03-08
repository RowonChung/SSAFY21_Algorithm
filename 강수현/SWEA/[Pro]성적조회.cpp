#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

struct Node {
	int id;
	int score;
	bool operator< (Node t) const {
		if (score < t.score) return true;
		else if (score > t.score) return false;

		if (id < t.id) return true;
		else return false;
	}
};

struct yx {
	int y;
	int x;
	int score;
};

set<Node>st[3][2];
unordered_map<int, yx> mi; // id 기준 저장

int checkGender(char mGender[7]) {
	if (mGender[0] == 'm') return 0;
	else return 1;
}

void init() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			st[i][j].clear();
		}
	}

	return;
}

int add(int mId, int mGrade, char mGender[7], int mScore) {
	int g = checkGender(mGender);
	mGrade--;

	st[mGrade][g].insert({ mId, mScore });
	mi[mId] = { mGrade, g, mScore };

	auto iter = st[mGrade][g].end();
	iter--;

	return (*iter).id;
}

int remove(int mId) {
	if (mi.count(mId) == 0) return 0;

	int i = mi[mId].y;
	int j = mi[mId].x;
	int s = mi[mId].score;

	int ans = -1;

	st[i][j].erase({ mId, s });

	if (st[i][j].size() == 0) return 0;
	else {
		auto iter = st[i][j].begin();
		return (*iter).id;
	}
}

int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore) {
	// 초기세팅
	int arr[3][2] = { 0 };
	int flag = 0;
	int g = 0;

	if (mGenderCnt == 1)
		g = checkGender(mGender[0]);
	else
		flag = 1;

	for (int i = 0; i < mGradeCnt; i++) {
		int tmp = mGrade[i] - 1;

		if (flag == 1) {
			arr[tmp][0] = 1;
			arr[tmp][1] = 1;
		}
		else {
			arr[tmp][g] = 1;
		}
	}

	int minId = 0;
	int minScore = 300001;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			if (arr[i][j] == 0) continue;

			auto iter = st[i][j].lower_bound({ 0, mScore });

			if (iter == st[i][j].end()) continue;

			if ((*iter).score < minScore) {
				minScore = (*iter).score;
				minId = (*iter).id;
			}

			if ((*iter).score == minScore && (*iter).id < minId) {
				minScore = (*iter).score;
				minId = (*iter).id;
			}
		}
	}

	if (minId != 0)
		return minId;

	return 0;
}