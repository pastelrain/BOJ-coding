#include<bits/stdc++.h>
using namespace std;


void heapify(int *v,int k,int n)
{
    int lchild=2*k;
    int rchild=2*k+1;

    if(lchild>n) return; //no child
    if(lchild==n)        //left only
    {
        if(v[lchild]<v[k]) swap(v[lchild],v[k]);
        return;
    }

    int x=v[lchild]<v[rchild]?lchild:rchild;
    if(v[k]>v[x])
    {
        swap(v[k],v[x]);
        heapify(v,x,n);
    }
}

void buildheap(int *v,int n)
{
    for(int i=n/2;i>0;i--) heapify(v,i,n);
}

void heapsort(int *v,int n)
{
    buildheap(v,n);

    for(int i=n;i>=2;i--)
    {
        swap(v[1],v[i]);
        heapify(v,1,i-1);
    }
}

int main()
{
    int n;
    cin>>n;

    int v[n];
    for(int i=1;i<=n;i++) cin>>v[i];

    heapsort(v,n);

    for(int i=n;i>=1;i--) cout<<v[i]<<" "; 
}
