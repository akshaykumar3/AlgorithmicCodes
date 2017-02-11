/* Bihar K Lala */
using namespace std;
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<ios>
#include<queue>
#include<algorithm>
#include<stack>
#include<vector>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
#define pa pair<int,int>
#define in 2147483647
#define v 500000
/*int gcd(int i,int j)
{
	return (j==0?i:gcd(j,i%j));
}*/
int t[v];
bool p[v];
void init(int i,int j,int n)
{
    t[n]=0;
    p[n]=false;
    if(j>i)
    {
        init(i,(i+j)/2,2*n);
        init((i+j)/2+1,j,2*n+1);
    }
}
void lazy(int i,int j,int n)
{
    if(p[n])
    {
        t[n]=j+1-i-t[n];
        p[n]=false;
        if(j>i)
        {
            if(p[2*n+1])
                p[2*n+1]=false;
            else
                p[2*n+1]=true;
            if(p[2*n])
                p[2*n]=false;
            else
                p[2*n]=true;
        }
    }
}
void up(int b,int e,int n,int i,int j)
{
    lazy(b,e,n);
    if(b>j||i>e) return ;
    else if(b>=i&&j>=e)
    {
        if(p[n])
            p[n]=false;
        else
            p[n]=true;
        lazy(b,e,n);
        return ;
    }
    up(b,(b+e)/2,2*n,i,j);
    up((b+e)/2+1,e,2*n+1,i,j);
    t[n]=t[2*n]+t[2*n+1];
}
int query(int b,int e,int n,int i,int j)
{
    lazy(b,e,n);
    if(b>j||i>e) return 0;
    else if(b>=i&&j>=e)
    {
        return t[n];
    }
    return (query(b,(b+e)/2,2*n,i,j)+query((b+e)/2+1,e,2*n+1,i,j));
}
int main()
{
    int n,q,i,j,a;
    scanf("%d%d",&n,&q);
    init(0,n-1,1);
    while(q--)
    {
        scanf("%d%d%d",&a,&i,&j);
        if(a) printf("%d\n",query(0,n-1,1,--i,--j));
        else up(0,n-1,1,--i,--j);
    }
    return 0;
}
