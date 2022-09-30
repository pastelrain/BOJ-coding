#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>

ll dist[20001],V,E,st,INF=1e9;
vector<pii> v[20001];

void mindist()
{
    priority_queue<pii,vector<pii>,greater<> > pq;
    pq.push({0,st});
    dist[st]=0;

    while(!pq.empty())
    {
        pii cur=pq.top();
        pq.pop();

        if(dist[cur.second]<cur.first) continue;
        
        for(int i=0;i<v[cur.second].size();i++)
        {
            pii next=v[cur.second][i];
            ll curdist=cur.first+next.first;
            if(dist[next.second]>curdist)
            {
                dist[next.second]=curdist;
                pq.push({curdist,next.second});
            }
        }
    }
}

int main()
{
    cin>>V>>E>>st;

    for(int i=1;i<=V;i++) dist[i]=INF;
    
    for(int v1,v2,e,i=0;i<E;i++)
    {
        cin>>v1>>v2>>e;
        v[v1].push_back({e,v2});
    }
    mindist();
    
    for(int i=1;i<=V;i++)
    {
        if(dist[i]==INF) cout<<"INF\n";
        else cout<<dist[i]<<"\n";
    }
}
