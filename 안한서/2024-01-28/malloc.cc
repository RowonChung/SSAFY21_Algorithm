// 연결 리스트
//	원소 저장할 때 그 다음 원소의 위치를 포함하는 방식으로 저장
//	원소 탐색 / 변경 -> O(n)
//	원소 추가 / 제거 -> O(1)
//	단일 연결 리스트는 각 원소가 자신의 다음 원소의 주소를 들고 있는 연결 리스트
//	이중 연결 리스트에서는 각 원소가 자신의 이전 원소와 다음 원소의 주소를 들고 있는 연결 리스트
//	원형 연결 리스트에서는 끝이 처음과 연결
//
//const int MX = 1000005;
//int dat[MX], pre[MX], nxt[MX];
//int unused = 1;
//
//void traverse() {
//	int curr = nxt[0];
//	while (1) {
//		// cout << dat[curr] << ' ';
//		curr = nxt[curr];
//	}
//	cout << "\n\n";
//
//}
//
//void insert(int addr, int data) {
//	dat[unused] = data;
//	pre[unused] = addr;
//	nxt[unused] = nxt[addr];
//	if (nxt[addr] != -1) pre[nxt[addr]] = unused;
//	nxt[addr] = unused;
//	unused++;
//}
//
//void erase(int addr) {
//	nxt[pre[addr]] = nxt[addr];
//	if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
//}

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
using namespace std;

// var과 list에서 마지막으로 할당 된 공간 위치
map<string, list<pair<int, int>>::iterator > m_addr;
// list : (시작점, 끝점)
list<pair<int, int>> allocate;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;

	allocate.push_back({ 1,1 });
	allocate.push_back({ 100001, 100001 });

	for (int i = 0; i < n; i++) {
		string command; cin >> command;
		if (command[5] == 'm') {
			int len = stoi(command.substr(12, (command.length() - 13)));
			string var = command.substr(0, 4);
			
			// list를 새로 구성 -> Map에서 var 부분 초기화하고 재할당
			m_addr.erase(var);

			auto nxt = allocate.begin();
			auto cur = nxt++;
			while (nxt != allocate.end()) {
				// (뒤의 시작점 - 앞의 끝점) -> 남은 공간
				// 남은 공간이 충분하면 탐색 종료
				if (nxt->first - cur->second >= len) break;
				cur++; nxt++;
			}

			// 탐색 지점이 마지막이면 공간 X
			// 탐색 지점이 (MX, MX) 이면 공간 O
			// map에 마지막 할당 위치 저장
			//		list에 앞의 끝 위치, 마지막 위치 삽입
			if (nxt == allocate.end()) continue;
			else m_addr[var] = allocate.insert(nxt, { cur->second, cur->second + len });
		}
		else {
			string var = command.substr(command[0] == 'f' ? 5 : 6, 4);
			auto idx = m_addr.find(var); // var의 위치 찾음
			if (command[0] == 'f') {
				// 할당 된 곳 있으면 제거
				if (idx != m_addr.end()) {
					allocate.erase(idx->second);
					m_addr.erase(idx);
				}
			}
			else {
				if (idx == m_addr.end()) cout << 0 << '\n';
				else cout << idx->second->first << '\n'; // map의 두 번째 (list)의 첫 번째 값이 시작점
			}
		}
	}
	return 0;
}
