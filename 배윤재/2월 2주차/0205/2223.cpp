#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int d, s;
};

int t, x, m;
vector<Node> monsters;
vector<int> monsInit;

int cnt = 0;
int flag = 0;

void input()
{
	cin >> t >> x >> m;

	for (int i = 0; i < m; i++)
	{
		int far, move;
		cin >> far >> move;
		monsters.push_back({ far, move });
		monsInit.push_back(far);
	}
}

void solve(int level)
{
	if (level == t)
	{
		cout << cnt;
		return;
	}

	for (int i = 0; i < m; i++)
	{
		Node mons = monsters[i];

		// 지민을 넘어서는 경우
		if (mons.d - mons.s <= 0) {
			flag = 1;
			break;
		}

		monsters[i] = { mons.d - mons.s, mons.s };
	}

	if (flag == 0) cnt += x;

	else
	{
		// 멈춰있을 때 멀어지기
		for (int i = 0; i < m; i++)
		{
			if (monsters[i].d == monsInit[i]) break;
			monsters[i].d += monsters[i].s;
		}

		flag = 0;
	}

	solve(level + 1);

}


int main()
{
	input();

	if (m == 0)
	{
		cout << t * x;
		return 0;
	}

	solve(0);

	return 0;
}