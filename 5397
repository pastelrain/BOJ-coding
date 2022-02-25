#include<bits/stdc++.h>
using namespace std;

struct Manage
{
    struct Node
    {
        char data;
        Node* prev;
        Node* next;
    };
    
    Node* head;
    Node* tail;
    Node* cur;

    Manage()
    {
        head=(Node*)malloc(sizeof(Node));
        tail=(Node*)malloc(sizeof(Node));

        head->prev=NULL;
        head->next=tail;

        tail->prev=head;
        tail->next=NULL;

        cur=tail;
    }

    void ins(char val)
    {
        Node* p=(Node*)malloc(sizeof(Node));

        p->data=val;
        p->next=cur;
        p->prev=cur->prev;

        cur->prev->next=p;
        cur->prev=p;
    }

    void del()
    {
        if(cur->prev==head) return;
        Node* p=cur->prev;

        p->prev->next=cur;
        cur->prev=p->prev;

        free(p);
    }

    void left()
    {
        if(cur->prev==head) return;
        cur=cur->prev;
    }

    void right()
    {
        if(cur==tail) return;
        cur=cur->next;
    }

    void print()
    {
        Node* p=head->next;
        while(p!=tail)
        {
            cout<<(p->data);
            p=p->next;
        }
        cout<<"\n";
    }
};

void solve()
{
    Manage m{};

    string c;
    cin>>c;

    for(int i=0;c[i];i++)
    {
        if(c[i]=='<')
            m.left();
        else if(c[i]=='>')
            m.right();
        else if(c[i]=='-')
            m.del();
        else
            m.ins(c[i]);
    }
    m.print();
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
}
