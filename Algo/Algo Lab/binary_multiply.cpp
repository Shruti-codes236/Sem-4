#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
#define ll long long int 
#define ull unsigned long long int
string binary(ull nn)//Converts decimal to binary and return
{
	string bin="";
	while(nn>0)
	{
		if(nn%2) bin="1"+bin;
		else bin="0"+bin;
		nn/=2;
	}
	return bin;
}
int calc_bits(string &s1,string &s2)//for making lengths of same length 
{
	int l1=s1.length();
	int l2=s2.length();
	int i;
	if(l2>l1) 
	{
		for(i=0;i<l2-l1;i++) s1='0'+s1;
		return l2;
	}
	if(l1>l2)
	{
		for(i=0;i<l1-l2;i++) s2='0'+s2;
	}	
	return l1; 
}
string add(string s1,string s2)//to add two numbers and return result
{
	string res="";
	int n=calc_bits(s1,s2);
	//int n=s1.length();
	int cur=0,i;// store carry
	for(i=n-1;i>=0;i--)
	{
		int fb,sb;
		fb=s1[i]-'0';
		sb=s2[i]-'0';
		int sum=(fb+sb+cur)%16;
		res=to_string(sum)+res;
		cur=(fb+sb+cur)/16;
	}
	if(cur) res="1"+res;
	return res;

}
//This relation we are using
//XY=2^n(xl*yl)+2^(n/2)[(xl+xr)(yl+yr)-xl*yl+xr*yr]+xr*yr;
ull multiply(string s1,string s2)
{
	int n=calc_bits(s1,s2);
	//int n=s1.length();
	if(n==0) return 0;
	if(n==1)
	{
		if
	 return (s1[0]-'0')*(s2[0]-'0');
	}
	int f=n/2;//first half bits
	int l=n-f;//last half bits
	string s1l=s1.substr(0,f);// first half string for first number
	string s1r=s1.substr(f,l);//last half string for first number
	string s2l=s2.substr(0,f);//first half string for second number
	string s2r=s2.substr(f,l);//last half string for second number
	ull pr1=multiply(s1l,s2l);
	ull pr2=multiply(s2r,s1r);
	ull pr=multiply(add(s1l,s1r),add(s2l,s2r));
	return pr1*(1<<(8*l))+(pr-pr2-pr1)*(4<<l)+pr2;//final answer will be computed and returned 
}
int main()
{
	string x,y;//input two numbers of n bits
	cin>>x;
	cin>>y;
	ull ans=multiply(x,y);
	string ans2=binary(ans);
	cout<<"Decimal product= "<<ans<<endl;
	//cout<<"Binary product= "<<ans2<<endl;
	return 0;
}
//Time complexity:T(n)=3T(n/2)+O(n) on solving we get O(n^log2(3))