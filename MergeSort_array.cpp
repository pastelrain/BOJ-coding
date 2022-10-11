#include<cstdio>
#define max(a,b) (a>b?a:b)

int cnt=0;

void merge(int *v,int st,int ed)
{
    int tmp[ed-st+1];
    int mid=(st+ed)/2;

    int p1=st,p2=mid+1,p=0;

    while(p1<=mid&&p2<=ed)
    {
        if(v[p1]<v[p2]) tmp[p++]=v[p1++];
        else tmp[p++]=v[p2++];
    }

    cnt=max(cnt,max(mid-p1,ed-p2)+1);

    while(p1<=mid) tmp[p++]=v[p1++];
    while(p2<=ed) tmp[p++]=v[p2++];

    for(int i=0;i<p;i++) v[st+i]=tmp[i];
}

void mergeSort(int *v,int st,int ed)
{
    if(st>=ed) return;

    int mid=(st+ed)/2;

    mergeSort(v,st,mid);
    mergeSort(v,mid+1,ed);
    merge(v,st,ed);
}

int main()
{
    int n;
    scanf("%d",&n);

    int v[n];
    for(int i=0;i<n;i++) scanf("%d",v+i);

    mergeSort(v,0,n-1);
    printf("%d",cnt);
}
