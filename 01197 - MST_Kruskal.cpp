#include<bits/stdc++.h>
using namespace std;

struct p
{
    int x,y,dist;
};

bool cmp(p a,p b){return a.dist<b.dist;}

int root[10001];

int find(int x)
{
    if(root[x]==x) return x;
    return root[x]=find(root[x]);
}

void Union(int x,int y)
{
    x=find(x);
    y=find(y);

    if(x>y) swap(x,y);
    root[y]=x;
}

p v[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=0;i<10001;i++) root[i]=i;

    int n,m;
    cin>>n>>m;


    for(int i=0;i<m;i++) cin>>v[i].x>>v[i].y>>v[i].dist;

    sort(v,v+m,cmp);

    int ans=0;
    for(int i=0;i<m;i++)
    {
        if(find(v[i].x)!=find(v[i].y))
        {
            Union(v[i].x,v[i].y);
            ans+=v[i].dist;
        }
    }

    cout<<ans;
}
