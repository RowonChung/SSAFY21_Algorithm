#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

struct Edge {
  int a, b;
  ll val;
};

bool compare(const Edge &left, const Edge &right) {
  return left.val < right.val;
}

vector<Edge> v;
ll n, arr[1010][1010], parents[1010];
ll cnt, val;

ll find(ll tar) {
  if (tar == parents[tar])
    return tar;
  ll ret = find(parents[tar]);
  parents[tar] = ret;
  return ret;
}

void setUnion(ll a, ll b) {
  ll t1 = find(a);
  ll t2 = find(b);
  if (t1 == t2)
    return;
  if (t1 < t2)
    parents[t2] = t1;
  else
    parents[t1] = t2;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
      v.push_back({i, j, arr[i][j]});
    }
  }
  for (int i = 0; i <= n; i++) {
    parents[i] = i;
  }

  sort(v.begin(), v.end(), compare);

  for (auto line : v) {
    if (find(line.a) == find(line.b))
      continue;
    setUnion(line.a, line.b);
    val += line.val;
    cnt++;
    if (cnt == n - 1)
      break;
  }
  cout << val;
}
