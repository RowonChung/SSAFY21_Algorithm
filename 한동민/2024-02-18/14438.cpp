#include <iostream>
using namespace std;

#define INF (1<<31)-1
#define ARR_SIZE 100001

int N, Q;
int leaf;
long long arr[ARR_SIZE];
long long tree[4 * ARR_SIZE];

void init() {
    leaf = 1 << 1;
    while (leaf < N) {
        leaf <<= 1;
    }
    int tmp = leaf;

    // leaf 노드에 arr 값 입력
    for (int i = leaf; i < leaf + N; i++) {
        tree[i] = arr[i - leaf];
    }
    while (tmp != 0) {
        tmp >>= 1;
        for (int i = tmp; i < tmp << 1; i++) {
            tree[i] = min(tree[i << 1], tree[(i << 1) | 1]);
        }
    }
}

void update(int index, long long dif) {
    index += leaf;
    tree[index] = dif;
    while (index != 0) {
        index >>= 1;
        tree[index] = min(tree[index << 1], tree[(index << 1) | 1]);
    }
}

long long query(int left, int right) {

    long long minimum = INF;

    left += leaf;
    right += leaf;

    while (left != right) {
        if (left % 2 == 1) {
            minimum = min(minimum, tree[left]);
            left++;
        }
        if (right % 2 == 1) {
            --right;
            minimum = min(minimum, tree[right]);
        }
        left >>= 1;
        right >>= 1;
    }

    return minimum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    init();
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int tmp;
        cin >> tmp;
        if (tmp == 1) {
            int index, dif;
            cin >> index >> dif;
            update(index - 1, dif);
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << query(a - 1, b) << "\n";
        }
    }
}
