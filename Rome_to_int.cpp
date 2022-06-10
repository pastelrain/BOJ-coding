#include<bits/stdc++.h>
using namespace std;

string in;
int ans,cnt[7],inv[6],cnt2[7];
//I=0,V=1,X=2,L=3,C=4,D=5,M=6

int add(char x)
{
	switch(x)
	{
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return  500;
		case 'M': return 1000;
		default: return 0;
	}
}
int level(char x)
{
	switch(x)
	{
		case 'I': return 0;
		case 'V': return 1;
		case 'X': return 2;
		case 'L': return 3;
		case 'C': return 4;
		case 'D': return 5;
		case 'M': return 6;
		default: return 0;
	}
}

int main()
{
	cin>>in;
	for(int i=0;i<in.length();i++)
	{
		if((inv[0]+inv[1])&&(in[i]=='X'||in[i]=='V')) {cout<<"NO"; return 0;}
		if((inv[2]+inv[3])&&(in[i]=='C'||in[i]=='L')) {cout<<"NO"; return 0;}
		if((inv[4]+inv[5])&&(in[i]=='M'||in[i]=='D')) {cout<<"NO"; return 0;}

		if(i&& in[i]=='M'&&in[i-1]=='C') {if(i-1&&in[i-2]=='C') {cout<<"NO"; return 0;} inv[5]++;}
		if(i&& in[i]=='D'&&in[i-1]=='C') {inv[4]++;}
		if(i&& in[i]=='C'&&in[i-1]=='X') {if(i-1&&in[i-2]=='X') {cout<<"NO"; return 0;}inv[3]++;}
		if(i&& in[i]=='L'&&in[i-1]=='X') {inv[2]++;}
		if(i&& in[i]=='X'&&in[i-1]=='I') {if(i-1&&in[i-2]=='I') {cout<<"NO"; return 0;}inv[1]++;}
		if(i&& in[i]=='V'&&in[i-1]=='I') {inv[0]++;}

		if((cnt[1]&&in[i]=='X')||(cnt[3]&&in[i]=='C')||(cnt[5]&&in[i]=='M')) {cout<<"NO"; return 0;}

		if(inv[0]+inv[1]>1||inv[2]+inv[3]>1||inv[4]+inv[5]>1) {cout<<"NO"; return 0;}
		if(((inv[0]||inv[1])&&in[i]=='I')||((inv[2]||inv[3])&&in[i]=='X'&&!(inv[0]||inv[1]))||((inv[4]||inv[5])&&(in[i]=='C'&&!(inv[2]||inv[3])))) {cout<<"NO"; return 0;}


		

		if(i)
		{
			if((in[i]=='M'||in[i]=='D')&&level(in[i-1])<=3) {cout<<"NO"; return 0;}
			if((in[i]=='C'||in[i]=='L')&&level(in[i-1])<=1) {cout<<"NO"; return 0;}
		}

		if(in[i]=='D') cnt[5]++;
		if(in[i]=='L') cnt[3]++;
		if(in[i]=='V') cnt[1]++;
		if(in[i]=='M')
		{
			cnt2[6]++;
			cnt[0]=cnt[2]=cnt[4]=0;
			cnt[6]++;
		}
		if(in[i]=='C')
		{
			cnt2[4]++;
			cnt[0]=cnt[2]=cnt[6]=0;
			cnt[4]++;
		}
		if(in[i]=='X')
		{
			cnt2[2]++;
			cnt[0]=cnt[6]=cnt[4]=0;
			cnt[2]++;
		}
		if(in[i]=='I')
		{
			cnt2[0]++;
			cnt[6]=cnt[2]=cnt[4]=0;
			cnt[0]++;
		}
		if(cnt[0]>3||cnt[2]>3||cnt[4]>3||cnt[6]>3||(cnt[1]>1||cnt[3]>1||cnt[5]>1)) {cout<<"NO"; return 0;}
	}
	cout<<"YES\n";

	for(int i=0;in[i];i++)
	{
		if(!in[i+1]) ans+=add(in[i]);
		else if(add(in[i])>=add(in[i+1])) ans+=add(in[i]);
		else ans-=add(in[i]);
	}

	cout<<ans;
}
