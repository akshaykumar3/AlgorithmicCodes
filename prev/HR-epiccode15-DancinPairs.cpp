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
int a[100000],b[100000];
int getDiff(int x, int y) {
	return (x>y)? (x-y):(y-x);
}
int main()
{
	int n,k,i,j,c=0;
	cin>>n>>k;
	for(i=0;i<n;i++) {
		cin>>a[i];
	}	
	for(i=0;i<n;i++) {
		cin>>b[i];
	}
	sort(a,a+n);
	sort(b,b+n);
	i=0;j=0;
	while(i<n && j<n) {
		int diff = getDiff(a[i],b[j]);
		if(diff <= k) {
			c++;i++;j++;
		} else if(a[i] > b[j]) {
			j++;
		} else {
			i++;
		}
	}
	cout<<c<<endl;
	return 0;
}