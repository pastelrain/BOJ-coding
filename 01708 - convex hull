#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

vector<pii> v;
stack<ll> s;

ll ccw(pii a,pii b,pii c)
{
    ll x=a.first*(b.second-c.second)+b.first*(c.second-a.second)+c.first*(a.second-b.second);
    if(x>0) return 1;
    else if(x==0) return 0;
    else return -1;
}

bool cmp(pii a,pii b)
{
    ll x=ccw(v[0],a,b);
    if(x) return x>0?1:0;

    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}

int main()
{
    int n;
    cin>>n;

    ll x,y;
    cin>>x>>y;
    v.push_back({x,y});

    for(ll i=1;i<n;i++)
    {
        cin>>x>>y;
        v.push_back({x,y});

        if(v[0]>v[i]) swap(v[0],v[i]);
    }

    for(int i=1;i<n;i++)
    {
        v[i]={v[i].first-v[0].first,v[i].second-v[0].second};
    }
    v[0]={0,0};

    sort(v.begin()+1,v.end(),cmp);

    s.push(0);
    s.push(1);

    for(int i=2;i<n;i++)
    {
        while(s.size()>=2)
        {
            pii cur;
            cur.second=s.top();
            s.pop();
            cur.first=s.top();

            if(ccw(v[cur.first],v[cur.second],v[i])>0)
            {
                s.push(cur.second);
                break;
            }
        }
        s.push(i);
    }
    cout<<s.size();
}
