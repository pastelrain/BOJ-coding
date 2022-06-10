#define private public
#include<bitset>
#undef private
#include<bits/stdc++.h>
#include<x86intrin.h>
using namespace std;

//https://gall.dcinside.com/mgallery/board/view/?id=ps&no=10146
//https://gist.github.com/cgiosy/a441de545c9e96b1d7b02cc7a00561f9?fbclid=IwAR0fsDcITukZOAyqXx4JNd8vXaGRNcg83-06VKcsOoWmaiDsGG918LCCDM8
template<size_t _Nw> void _M_do_sub(_Base_bitset<_Nw> &A,const _Base_bitset<_Nw> &B)
{
    for(int i=0,c=0;i<_Nw;i++)
        c=_subborrow_u64(c,A._M_w[i],B._M_w[i],(unsigned long long*)&A._M_w[i]);
}
template<> void _M_do_sub(_Base_bitset<1> &A,const _Base_bitset<1> &B)
{
    A._M_w-=B._M_w;
}
template<size_t _Nb> bitset<_Nb>& operator-=(bitset<_Nb> &A,const bitset<_Nb> &B)
{
    _M_do_sub(A, B);
    return A;
}
template<size_t _Nb> inline bitset<_Nb> operator-(const bitset<_Nb> &A,const bitset<_Nb> &B)
{
    bitset<_Nb> C(A);
    return C-=B;
}

string s1,s2;
bitset<50000> bit,v[26];
int main()
{
    ios::sync_with_stdio();cin.tie();cout.tie();
    cin>>s1>>s2;

    for(int i=0;i<s2.length();i++) v[s2[i]-'A'][i]=1;
    for(int i=0;i<s1.length();i++)
    {
        auto tmp=bit|v[s1[i]-'A'];
        bit<<=1; bit[0]=1;

        bit=tmp&(tmp^(tmp-bit));
    }

    cout<<bit.count();
}
//https://blog.naver.com/PostView.naver?blogId=jinhan814&logNo=222545486610&categoryNo=81&parentCategoryNo=52&viewDate=&currentPage=1&postListTopCurrentPage=1&from=postView
