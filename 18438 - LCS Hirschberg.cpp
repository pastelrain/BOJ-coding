#include<bits/stdc++.h>
using namespace std;

string s1,s2;
vector<char> v;

void lcs(int l1,int r1,int l2,int r2)
{
	if(l1>r1) return;

	if(l1==r1)
	{
		for(int i=l2;i<=r2;i++)
		if(s1[l1]==s2[i])
		{
			v.push_back(s2[i]);
			break;
		}
		return;
	}

	vector<int> lcs1(r2-l2+3),lcs2(r2-l2+3),prev(r2-l2+3); //(r2-l2+2)+1. 7001->TLE
	int m=(l1+r1)/2;

	for(int i=l1;i<=m;i++)
	{
		for(int j=l2;j<=r2;j++)
		{
			lcs1[j-l2+1]=(s1[i]==s2[j]) ? prev[j-l2]+1 : max(lcs1[j-l2],prev[j-l2+1]);
		}
		prev=lcs1;
	}
	fill(prev.begin(),prev.end(),0);

	for(int i=r1;i>m;i--)
	{
		for(int j=r2;j>=l2;j--)
		{
			lcs2[j-l2+1]=(s1[i]==s2[j]) ? prev[j-l2+2]+1 : max(lcs2[j-l2+2],prev[j-l2+1]);
		}
		prev=lcs2;
	}

	int maxval=-1,idx=0;
	for(int i=l2;i<=r2+1;i++)
	{
		int tmp=lcs1[i-l2]+lcs2[i-l2+1];
		if(maxval<tmp)
		{
			maxval=tmp;
			idx=i;
		}
	}

	lcs(l1,m,l2,idx-1);
	lcs(m+1,r1,idx,r2);
}	

int main()
{
	ios::sync_with_stdio();cin.tie();cout.tie();
	
	cin>>s1>>s2;
	lcs(0,s1.length()-1,0,s2.length()-1);

	cout<<v.size()<<"\n";
	for(auto i:v) cout<<i;
}
