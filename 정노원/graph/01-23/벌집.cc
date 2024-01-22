#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define N 1000010
#define M 600
#define pb push_back
#define rot(a,j) a.begin(),a.begin()+j,a.end()

struct pt {
    int i,j,k;
} h[N];

typedef vector<int> vii;
bool vis[N];
vii sur[N];
int pos[M][6][M];

void set() {
    int s=1;
    pos[0][0][0]=1;
    h[1]={0,0,0};
    for (int i=1;i<M;i++) {
        for (int j=0;j<6;j++)
            for (int k=0;k<i;k++)
                if (++s<N) {
                    pos[i][j][k]=s;
                    h[s] = {i,j,k};
                } else return;
    }
}

int get(int i,int j,int k) {
    if (i==0) return 1;
    if (k<0) j--;
    if (k>=i) j++;
    k=(k+i)%i;
    j=(j+6)%6;
    return pos[i][j][k];
}

void bfs() {
    int s,e,n,d;
    cin>>s>>e;
    queue<vii> que;
    vii p = {-1,s};
    que.push(p);
    while(!que.empty()) {
        p=que.front();
        s=p.back();
        n=p.size();
        que.pop();

        if (s==e) {
            for (int i=1;i<n;i++)
                cout<<p[i]<<" ";
            return;
        }
        if (vis[s]) continue;
        vis[s]=1;

        int v=p[0];
        p.resize(n+1);
        for (int i=0;i<6;i++) {
            int x = sur[s][i];
            if (!x||x>=N) continue;
            d = (v-i+6)%6;
            if (d<=1||v==-1)
                p[0]=i,p[n]=x,que.push(p);
        }
    }
}

int main() {
    set();
    sur[1]={6,7,2,3,4,5};
    for (int s=2;s<N;s++) {
        int i,j,k;
        i=h[s].i,j=h[s].j,k=h[s].k;
        sur[s].pb(get(i,j,k-1));
        sur[s].pb(get(i+1,j,k));
        sur[s].pb(get(i+1,j,k+1));
        if (k==i-1) {
            sur[s].pb(get(i+1,j+1,0));
            sur[s].pb(get(i,j,k+1));
        } else {
            sur[s].pb(get(i,j,k+1));
            sur[s].pb(get(i-1,j,k));
        }
        sur[s].pb(get(i-1,j,k-1));
        if (j) rotate(rot(sur[s],6-j));
    }
    bfs();
}