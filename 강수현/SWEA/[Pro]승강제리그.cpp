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
	int ability;

	bool operator<(Node r) const {
		if (ability > r.ability) return true;
		else if (ability < r.ability) return false;

		// ability가 같을 때
		if (id < r.id) return true;
		else return false;
	}
};

set<Node>s[10];
Node mid[10];

int player, league, team;

void init(int N, int L, int mAbility[]) {
	// init
	for (int i = 0; i < 10; i++) {
		s[i].clear();
	}

	player = N;
	league = L;
	team = N / L;

	// input
	int tmp = 0;
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < team; j++) {
			s[i].insert({ i * team + j, mAbility[tmp++] });
		}
	}

	// mid check
	for (int i = 0; i < L; i++) {
		auto itr = s[i].begin();
		for (int j = 0; j < team; j++) {
			itr++;
		}
		mid[i] = { (*itr).id, (*itr).ability };
	}
}

int move() {
	int res = 0;

	Node temp[10][2];

	auto last = s[0].end();
	last--;
	temp[1][0] = *last;
	res += (*last).id;
	s[0].erase({ temp[1][0].id, temp[1][0].ability });

	for (int i = 1; i < league - 1; i++) {
		auto first = s[i].begin();
		temp[i - 1][1] = *first;
		res += (*first).id;
		s[i].erase({ temp[i - 1][1].id, temp[i - 1][1].ability });

		auto last = s[i].end();
		last--;
		temp[i + 1][0] = *last;
		res += (*last).id;
		s[i].erase({ temp[i + 1][0].id, temp[i + 1][0].ability });
	}

	auto first = s[league - 1].begin();
	temp[league - 2][1] = *first;
	res += (*first).id;
	s[league - 1].erase({ temp[league - 2][1].id, temp[league - 2][1].ability });

	s[0].insert(temp[0][1]);

	for (int i = 1; i < league - 1; i++) {
		s[i].insert(temp[i][0]);
		s[i].insert(temp[i][1]);
	}

	s[league - 1].insert(temp[league - 1][0]);

	return res;
}

int trade() {
	int res = 0;
	int index = team / 2;
	Node temp[10][2];

	auto first = s[0].begin();
	
	int n = (*first).id;
	auto tar = (first + last) / 2;
	
	advance(ele, index);

	temp[1][0] = { (*ele).id,(*ele).ability };
	res += temp[1][0].id;
	s[0].erase({ temp[1][0].id, temp[1][0].ability });


	for (int i = 1; i < league - 1; i++) {
		auto first = s[i].begin();
		temp[i - 1][1] = *first;
		res += (*first).id;
		s[i].erase({ temp[i - 1][1].id, temp[i - 1][1].ability });

		auto ele = s[i].begin();
		advance(ele, index - 1);
		temp[i + 1][0] = { (*ele).id,(*ele).ability };
		res += temp[i + 1][0].id;
		s[i].erase({ temp[i + 1][0].id, temp[i + 1][0].ability });
	}

	auto first = s[league - 1].begin();
	temp[league - 2][1] = *first;
	res += (*first).id;
	s[league - 1].erase({ temp[league - 2][1].id, temp[league - 2][1].ability });

	s[0].insert(temp[0][1]);
	for (int i = 1; i < league - 1; i++) {
		s[i].insert(temp[i][0]);
		s[i].insert(temp[i][1]);
	}
	s[league - 1].insert(temp[league - 1][0]);

	return res;
}