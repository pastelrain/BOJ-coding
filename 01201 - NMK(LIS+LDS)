#include<bits/stdc++.h>
using namespace std;

int n,m,k;

int main()
{
    cin>>n>>m>>k;

    if( n<m+k-1 || n>m*k )
    {
        cout<<"-1";
        return 0;
    }

    vector<int> v;
    for(int i=0;i<k;i++)
        v.push_back(k-i);
    
    n-=k;

    while(--m)
    {
        k+=n/m;

        for(int i=0;i<n/m;i++)
            v.push_back(k-i);
        
        n-=n/m;
    }

    for(auto i:v)
        cout<<i<<" ";
}
