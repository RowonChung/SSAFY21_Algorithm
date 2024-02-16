#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int tc;
	cin>>tc;
	for(int t=1;t<=tc;t++)
	{
		int n,m,l;
		cin>>n>>m>>l;
		vector<int> v;
		v.resize(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		while(m--)
		{
			char cmd;
			cin>>cmd;
			if(cmd=='I')
			{
				int idx,num;
				cin>>idx>>num;
				v.insert(v.begin()+idx,num);
			}
			else if(cmd=='D')
			{
				int idx;
				cin>>idx;
				v.erase(v.begin()+idx);
			}
			else
			{
				int idx,num;
				cin>>idx>>num;
				v[idx] = num;
			}
		}
		cout<<"#"<<t<<' ';
		if(v.size()>l)
			cout<<v[l]<<'\n';
		else
			cout<<-1<<'\n';
	}
}