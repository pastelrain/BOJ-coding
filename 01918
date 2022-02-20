#include<bits/stdc++.h>
using namespace std;

char c[101];
int a[128];
stack<char> s;

void init()
{
    a['+']=a['-']=1;
    a['*']=a['/']=2;
}

int main()
{
    init();

    cin>>c;
    for(int i=0;c[i];i++)
    {
        if('A'<=c[i]&&c[i]<='Z') cout<<c[i];

        else if(c[i]=='(')
        {
            s.push(c[i]);
        }

        else if(c[i]==')')
        {
            while(s.top()!='(')
            {
                cout<<s.top();
                s.pop();
            }
            s.pop();
        }

        else
        {
            while(!s.empty()&&a[s.top()]>=a[c[i]])
            {
                cout<<s.top();
                s.pop();
            }
            s.push(c[i]);
        }
    }
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
}
