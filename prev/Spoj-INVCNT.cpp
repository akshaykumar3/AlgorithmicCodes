using namespace std;
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<queue>
#include<algorithm>
#include<stack>
#include<vector>
int c[200000],b[200000];
long long s;
void merge(int i,int j)
{
    int mid,l,k;
    mid=(i+j)/2;
    k=mid+1;
    l=i;
    while(i<=mid&&k<=j)
    {
        if(c[i]<=c[k])
            b[l++]=c[i++];
        else
        {
            b[l++]=c[k++];s+=(k-l);
        }
    }
    if(i>mid)
    {
        for(;k<=j;)
        {
            b[l++]=c[k++];
        }
    }
    else if(k>j)
    {
        for(;i<=mid;)
        {
            b[l++]=c[i++];
        }
    }
}
void mergesort(int i,int j)
{
    int mid;
    if(i>=j)
        return ;
    else
    {
        mid=(i+j)/2;
        mergesort(i,mid);
        mergesort(mid+1,j);
        merge(i,j);
        for(;i<=j;i++)c[i]=b[i];
    }
}
int main()
{
    int t,n,i;
    scanf("%d",&t);
    while(t--)
    {
        s=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&c[i]);
        mergesort(0,n-1);
        printf("%lld\n",s);
    }
    return 0;
}