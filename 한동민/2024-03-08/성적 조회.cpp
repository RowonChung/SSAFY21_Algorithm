#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

#define INF (1<<31)-1

struct INFO {
	int grade;
	int gender;
	int score;
};

struct STUDENT {
	int id;
	int score;
	bool operator<(const STUDENT& s) const {
		if (score == s.score) {
			return id < s.id;
		}
		else {
			return score < s.score;
		}
	}
};

bool compare(STUDENT s1, STUDENT s2) {
	if (s1.score == s2.score) {
		return s1.id < s2.id;
	}
	return s1.score < s2.score;
}

//struct compare {
//	bool operator()(const STUDENT& s1, const STUDENT& s2) {
//		if (s1.score == s2.score) {
//			return s1.id < s2.id;
//		}
//		else {
//			return s1.score < s2.score;
//		}
//	}
//};

set<STUDENT> s[4][2]; // 0 -> male, 1 -> female
unordered_map<int, INFO> um;

void init() {
	for (int i = 1; i <= 3; i++) {
		for (int j = 0; j < 2; j++) {
			s[i][j].clear();
		}
	}
	return;
}

int add(int mId, int mGrade, char mGender[7], int mScore) {
	int g = mGender[0] == 'm' ? 0 : 1;
	s[mGrade][g].insert({ mId,mScore });
	um[mId] = { mGrade,g,mScore };
	auto iter = s[mGrade][g].end();
	iter--;
	return iter->id;
}

int remove(int mId) {
	int mini = INF;
	if (um.find(mId) == um.end()) {
		/*cout << "res = " << 0 << endl;*/
		return 0;
	}
	int grade = um[mId].grade;
	int gender = um[mId].gender;
	int score = um[mId].score;
	um.erase(mId);
	s[grade][gender].erase({ mId,score });
	if (s[grade][gender].size() == 0) {
		/*cout << "res = " << 0 << endl;*/
		return 0;
	}
	else {
		auto iter = s[grade][gender].begin();
		/*cout << "res = " << iter->id << endl;*/
		return iter->id;
	}
}

int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore) {
	vector<STUDENT> v;
	for (int i = 0; i < mGradeCnt; i++) {
		int grade = mGrade[i];
		if (mGenderCnt == 2) {
			for (int j = 0; j < 2; j++) {
				if (s[grade][j].size() == 0) {
					continue;
				}
				STUDENT temp = { 0,mScore };
				auto iter = s[grade][j].lower_bound(temp);
				if (iter == s[grade][j].end()) {
					continue;
				}
				v.push_back({ iter->id,iter->score });
			}
		}
		else {
			if (mGender[0][0] == 'm') {
				if (s[grade][0].size() == 0) {
					continue;
				}
				STUDENT temp = { 0,mScore };
				auto iter = s[grade][0].lower_bound(temp);
				if (iter == s[grade][0].end()) {
					continue;
				}
				v.push_back({ iter->id,iter->score });
			}
			else {
				if (s[grade][1].size() == 0) {
					continue;
				}
				STUDENT temp = { 0,mScore };
				auto iter = s[grade][1].lower_bound(temp);
				if (iter == s[grade][1].end()) {
					continue;
				}
				v.push_back({ iter->id,iter->score });
			}
		}
	}
	if (v.size() == 0) {
		return 0;
	}
	else {
		sort(v.begin(), v.end(), compare);
		return v[0].id;
	}
}
