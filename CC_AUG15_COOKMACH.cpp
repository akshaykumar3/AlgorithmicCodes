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
int fn(int a, int b)
{
	int c=0;
	while(a>b)
	{
		a=a>>1;
		c++;
	}
	return c;
}

int main()
{
	int t,a,b,c;
	scanf("%d",&t);
	while(t--)
	{
		c=0;
		scanf("%d%d",&a,&b);
		if(a == b)
		{
			printf("0\n");
			continue;
		}
		while((a&(-a)) != a)
		{
			c++;
			a=a>>1;
		}
		c+=((a>b) ? fn(a,b) : fn(b,a));
		printf("%d\n",c);
	}
	return 0;
}