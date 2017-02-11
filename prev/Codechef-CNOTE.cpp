using namespace std;
#include<iostream>
#include<string.h>
#include<malloc.h>
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
#define w(a) while(a--)
#define w(a,b) while(a>b)
#define s(a,d) scanf("%d",&a)
/*int gcd(int i,int j)
{
	return (j==0?i:gcd(j,i%j));
}*/
int main()
{
	int t,x,y,n,k,p,c,i;
	bool flag;
	s(t,d)
	w(t)
	{
        scanf("%d%d%d%d",&x,&y,&k,&n);
        flag = false;
        z = x-y;
        w(n)
        {
            scanf("%d%d",&p,&c);
            flag = flag | ((p >= z) && (k >= c));
        }
        if(flag)
            printf("LuckyChef\n");
        else
            printf("UnluckyChef\n");
	}
	return 0;
}
