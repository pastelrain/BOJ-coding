#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>


vector<pii> v[10001];
int vis[10001];
int dist[10001];

int sum=0;
int cnt=0;

priority_queue<pii,vector<pii>,greater<pii>> pq;
void prim(int cur)
{
    cnt++;
    vis[cur]=1;

    for(int i=0;i<v[cur].size();i++)
    {
        if(vis[v[cur][i].second]==0) pq.push({v[cur][i].first,v[cur][i].second});
    }

    while(!pq.empty())
    {
        pii x=pq.top();
        pq.pop();

        if(vis[x.second]==0)
        {
            sum+=x.first;
            prim(x.second);
            return;
        }
    }
}

int main()
{
    //init
    for(int i=0;i<10001;i++) dist[i]=1e9;

    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int x,y,cost;
        cin>>x>>y>>cost;
        v[x].push_back({cost,y});
        v[y].push_back({cost,x});
    }

    prim(1);
    if(cnt<n) cout<<"impossible";
    else cout<<sum;
}
