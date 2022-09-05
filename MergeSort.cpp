#include<bits/stdc++.h>
using namespace std;


void merge(int *v,int st,int mid,int ed)
{
	int p1=st,p2=mid+1;
	
	queue<int> q;
	while(p1<=mid||p2<=ed)
	{
		if(p1>mid){q.push(v[p2++]); continue;}
		if(p2>ed){q.push(v[p1++]); continue;}

		q.push(v[p1]<v[p2]?v[p1++]:v[p2++]);
	}

	for(int i=st;i<=ed;i++)
	{
		v[i]=q.front();
		q.pop();
	}
}

void mergesort(int *v,int st,int ed)
{
	if(st>=ed) return;

	int mid=(st+ed)/2;
	mergesort(v,st,mid);
	mergesort(v,mid+1,ed);

	merge(v,st,mid,ed);
}

int main()
{
	int n;
	cin>>n;

	int v[n];
	for(int i=0;i<n;i++) cin>>v[i];


	mergesort(v,0,n-1);

	for(int i=0;i<n;i++) cout<<v[i]<<" ";
}
