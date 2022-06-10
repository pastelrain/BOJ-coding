#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ll128 __int128

ull modpow(ll128 n,ll128 p,ll128 mod)
{
    ll128 tmp=1;
    n%=mod;
    while(p)
    {
        if(p%2) tmp=(n*tmp)%mod;
        n=(n*n)%mod;
        p/=2;
    }
    return (ull)tmp;
}

bool millerrabin(ull n,ull a)
{
    if(a%n==0) return 1;
    ull p=n-1;

    while(1)
    {
        ull tmp=modpow(a,p,n);

        if(tmp==n-1) return 1;
        if(p%2==1) return tmp==1||tmp==n-1;

        p/=2;
    }
}

bool prime(ull n)
{
    if(n%2==0) return 0;

    ll p[12]={2,3,5,7,11,13,17,19,23,29,31,37};

    for(int i=0;i<12;i++)
    {
        if(n==p[i]) return 1;
        if(millerrabin(n,p[i])==0) return 0;
    }

    return 1;
}

ll128 gcd(ll128 a,ll128 b)
{
    while(b)
    {
        ll128 r=a%b;
        a=b;
        b=r;
    }
    return a;
}

ll128 pollardrho(ull n)
{
    if(prime(n)) return n;
    if(n%2==0) return 2;

    ll128 x=rand()%(n-2)+2;
    ll128 y=x;
    ll128 c=rand()%10+1;
    ll128 g=1;
    while(g==1)
    {
        x=(modpow(x,2,n)+c)%n;
        y=(modpow(y,2,n)+c)%n;
        y=(modpow(y,2,n)+c)%n;
        g=gcd(abs((ll)x-(ll)y),n);

        if(g==n) return pollardrho(g);
    }
    if(prime(g)) return g;
    else return pollardrho(g);
}


int main()
{
    ios::sync_with_stdio(0);cin.tie();cout.tie();
    
    ull n,x;
    cin>>n;
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    
    vector<ull> v;

    while(n>1)
    {
        x=pollardrho(n);

        while(n%x==0)
        {
            v.push_back(x);
            n/=x;
        }
    }
    
    sort(v.begin(),v.end());
    for(auto i:v) cout<<i<<"\n";
}
