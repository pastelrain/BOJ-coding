#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>


int n,m;
int indegree[1001],result[1001];
vector<int> v[1001];

void topsort()
{
	queue<int> q;
	for(int cur=1;cur<=n;cur++)
	{
		if(indegree[cur]==0) q.push(cur);
	}

	for(int t=0;t<n;t++)
	{
		if(q.empty())
		{
			cout<<0; //cycle
			return;
		}

		int cur=q.front();
		q.pop();

		result[t]=cur;

		for(int i=0;i<v[cur].size();i++)
		{
			int next=v[cur][i];

			if(--indegree[next]==0) q.push(next);
		}
	}

	for(int i=0;i<n;i++) cout<<result[i]<<"\n";
}

int main()
{
	//input
	cin>>n>>m;

	for(int i=0;i<m;i++)
	{
		int t;
		cin>>t;

		int x,prev;
		for(int j=0;j<t;j++)
		{
			prev=x;
			cin>>x;

			if(j)
			{
				v[prev].push_back(x);
				indegree[x]++;
			}
		}
	}

	topsort();
}
