#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int n, fullStat, answer = 1e9;
vector<int> people;
vector<vector<int>> aList;
set<int> used;

int calculateCost(int bitmask) {
  vector<int> cities;

  for (int i = 1; i <= n; i++) {
    if ((bitmask & (1 << i)) == (1 << i)) {
      cities.push_back(i);
    }
  }

  vector<bool> usedCity(n + 1, false);
  int startCity = cities[0];
  usedCity[startCity] = true;
  queue<int> q;
  q.push(startCity);
  int totalCost = 0;

  while (!q.empty()) {
    int currentCity = q.front();
    q.pop();
    totalCost += people[currentCity];

    for (int nextCity : aList[currentCity]) {
      if (!usedCity[nextCity] &&
          find(cities.begin(), cities.end(), nextCity) != cities.end()) {
        usedCity[nextCity] = true;
        q.push(nextCity);
      }
    }
  }

  for (int city : cities) {
    if (!usedCity[city]) {
      return -1;
    }
  }

  return totalCost;
}

void calculateAndCompare(int bitmask) {
  int groupA = bitmask;
  int groupB = fullStat ^ groupA;

  int costA, costB;
  if ((costA = calculateCost(groupA)) != -1 &&
      (costB = calculateCost(groupB)) != -1) {
    answer = min(answer, abs(costA - costB));
  }
}

void dfs(int idx, int cost, int remaining, int bitmask) {
  if (remaining == 0) {
    if (used.insert(bitmask).second) {
      calculateAndCompare(bitmask);
    }
    return;
  }

  for (int i = idx; i < n; i++) {
    bitmask |= 1 << (i + 1);
    dfs(i + 1, cost + people[i + 1], remaining - 1, bitmask);
    bitmask ^= 1 << (i + 1);
  }
}

int main() {
  cin >> n;
  people.resize(n + 1);
  aList.resize(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> people[i];
  }

  for (int i = 1; i <= n; i++) {
    int neighborCount;
    cin >> neighborCount;
    aList[i].resize(neighborCount);
    for (int j = 0; j < neighborCount; j++) {
      cin >> aList[i][j];
    }
  }

  fullStat = (1 << (n + 1)) - 1;

  for (int i = 0; i < n - 1; i++) {
    int bitmask = 1 << 1;
    dfs(1, people[1], i, bitmask);
  }

  cout << (answer == 1e9 ? -1 : answer);
}
