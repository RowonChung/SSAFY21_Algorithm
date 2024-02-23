#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n, m;
vector<int> arr, countries, ans;
set<int> s;

int find(int tar) {
  if (arr[tar] != tar)
    arr[tar] = find(arr[tar]);
  return arr[tar];
}

void setUnion(int a, int b, vector<int> &countries) {
  a = find(a);
  b = find(b);
  if (a < b) {
    arr[b] = a;
    countries[a] += countries[b];
  } else {
    arr[a] = b;
    countries[b] += countries[a];
  }
}

void war(int a, int b, vector<int> &countries) {
  a = find(a);
  b = find(b);

  if (countries[a] > countries[b]) {
    countries[a] -= countries[b];
    arr[b] = a;
  } else if (countries[a] < countries[b]) {
    countries[b] -= countries[a];
    arr[a] = b;
  } else {
    arr[a] = 0;
    arr[b] = 0;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  arr.resize(n + 1);
  countries.resize(n + 1);

  for (int i = 1; i <= n; i++)
    cin >> countries[i];

  for (int i = 1; i <= n; i++)
    arr[i] = i;

  for (int i = 0; i < m; i++) {
    int op, p, q;
    cin >> op >> p >> q;

    if (op == 1)
      setUnion(p, q, countries);
    else
      war(p, q, countries);
  }

  for (int i = 1; i <= n; i++) {
    int parent = find(i);
    if (parent != 0)
      s.insert(parent);
  }

  for (int parent : s)
    ans.push_back(countries[parent]);

  sort(ans.begin(), ans.end());
  cout << s.size() << '\n';
  for (int val : ans)
    cout << val << " ";
  cout << '\n';
}
