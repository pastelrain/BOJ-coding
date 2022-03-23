#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,a[20001],ans;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a[i]=a[i-1]+x;
    }
    for(int i=n+1;i<=2*n;i++) a[i]=a[i-n]+a[n];

    for(int i=1;i<=n;i++)
    for(int j=i;j<i+n;j++)
    {
        ll sum=a[j]-a[i-1];

        if(sum<0) ans+=(-sum-1)/a[n]+1;
    }
    cout<<ans;
}
