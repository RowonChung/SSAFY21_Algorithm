#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	int n,m,k;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>k;
	map<int,int> mp;
	for(int i=0;i<m;i++)
	{
		int tmp;
		cin>>tmp;
		mp[tmp]++;
	}
	for(int i=0;i<k;i++)
	{
		int tmp ;
		cin>>tmp;
		auto it = mp.upper_bound(tmp);
		cout<<(*it).first<<endl;
		if((*it).second>1)
			(*it).second--;
		else
			mp.erase(it);
	}
}