using namespace std;
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ios>
#include<queue>
#include<algorithm>
#include<stack>
#include<vector>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
#define pa pair<long long,long long>
#define in 2000000000
#define pb(a) push_back(a)
#define ln 9000000000000000000
/*int gcd(int i,int j)
{
	return (j==0?i:gcd(j,i%j));
}*/
long long a = 0;
int b[26];
int main()
{
	string s;
	int n,i;
	cin>>n>>s;
	for(i=0;i<n;i++) {
		b[s[i]-'a']++;
	}
	for(i=0;i<26;i++) {
		a += b[i];
		a = a + (b[i] * (b[i] - 1)) / 2;
	}
	cout<<a<<endl;
	return 0;
}

