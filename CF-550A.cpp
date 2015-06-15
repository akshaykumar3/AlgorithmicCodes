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
int main()
{
    string input;
    cin>>input;
    bool ans = false;
    int i,x1=1000000,x2=-1,y2=-1,y1=1000000;
    for(i=0;i<input.length();i++) {
    	if(input[i] == 'A' && (i+1)<input.length() && input[i+1]=='B') {
    		x1=min(x1,i);
    		x2=max(x2,i);
    	} else if(input[i] == 'B' && (i+1)<input.length() && input[i+1]=='A') {
    		y1=min(y1,i);
    		y2=max(y2,i);
    	}
    }
    if(x2>-1 && y2>-1) {
    	if((y2-x1) > 1 || (x2-y1) > 1)
    		ans=true;
    }
    if(ans) printf("YES\n");
    else printf("NO\n");
	return 0;
}

