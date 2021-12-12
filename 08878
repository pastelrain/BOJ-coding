#include<bits/stdc++.h>
using namespace std;

double x,p,r,ans;

int main()
{
    scanf("%lf%lf",&x,&p);
    x/=100;p/=100;
    if(p>0)
    {
        int L=1,W=1,S;
        while(L<=20528)
        {
            int f=0;
            double ans1=0;
            while(W<=2498)
            {
                r=(1-p)/p;
                double P=(1-pow(r,-L))/(pow(r,W)-pow(r,-L));
                double asdf=P*W-(1-P)*L*(1-x);
                if(asdf>ans)
                {
                    ans=asdf;
                    f=1;
                    S=W;
                }
                if(asdf<ans1) break;
                ans1=asdf;
                W++;
            }
            if(f==0) break;
            L++;
            W=S;
        }
    }
    printf("%.9lf",ans);
}
