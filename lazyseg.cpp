#include<bits/stdc++.h>
using namespace std;

long long a[1000001],tree[1<<21],lazy[1<<21];

long long init(int node,int st,int ed)
{
    if(st==ed) return tree[node]=a[st];
    else return tree[node]=init(node*2,st,(st+ed)/2)+init(node*2+1,(st+ed)/2+1,ed);
}

void updatelazy(int node,int st,int ed)
{
    if(lazy[node])
    {
        tree[node]+=(ed-st+1)*lazy[node];
        if(st!=ed)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
}

void update(int node,int st,int ed,int left,int right,long long diff)
{
    updatelazy(node,st,ed);
    if(left>ed||right<st) return;
    if(left<=st&&right>=ed)
    {
        tree[node]+=(ed-st+1)*diff;
        if(st!=ed)
        {
            lazy[node*2]+=diff;
            lazy[node*2+1]+=diff;
        }
        return;
    }
    update(node*2,st,(st+ed)/2,left,right,diff);
    update(node*2+1,(st+ed)/2+1,ed,left,right,diff);
    tree[node]=tree[node*2]+tree[node*2+1];
}

long long sum(int node,int st,int ed,int left,int right)
{
    updatelazy(node,st,ed);
    if(left>ed||right<st) return 0;
    if(left<=st&&right>=ed) return tree[node];
    return sum(node*2,st,(st+ed)/2,left,right)+sum(node*2+1,(st+ed)/2+1,ed,left,right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    m+=k;
    for(int i=1;i<=n;i++) cin>>a[i];
    init(1,1,n);
    while(m--)
    {
        long long x,b,c,d;
        cin>>x;
        if(x==1)
        {
            cin>>b>>c>>d;
            update(1,1,n,b,c,d);
        }
        else
        {
            cin>>b>>c;
            cout<<sum(1,1,n,b,c)<<"\n";
        }
    }
}
