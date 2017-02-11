using namespace std;
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<queue>
#include<algorithm>
#include<stack>
#include<vector>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
int a[1100],d[1100];
bool dif(int i,int j)
{
    int c=0;
    while(i>0)
    {
        c+=(i%10==j%10?0:1);
        i/=10;j/=10;
    }
    return (c==1?true:false);
}
int bs(int n,int i,int j)
{
    int mid;
    mid=(i+j)/2;
    if(a[i]==n){return i;}
    else if(a[j]==n) {return j;}
    else if(a[mid]==n) {return mid;}
    else if(a[mid]>n) {return bs(n,i,mid-1);}
    else if(a[mid]<n){return bs(n,mid+1,j);}
    else return -1;
}
int main()
{
    queue<int> q;
    bool c;
    int t,n,m,i,j,x,f=1;
    a[0]=1009;
    for(t=1011;t<9978;t+=2)
    {
        j=sqrt(t);c=true;
        for(i=2;i<=j;i++)
        {
            if(!(t%i))
            {
                c=false;
                break;
            }
        }
        if(c)
        {
            a[f]=t;
            f++;
        }
    }
    //for(i=0;i<f;i++)printf("%d\n",a[i]);
    //printf("f = %d\n",f);
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<f;i++) d[i]=-1;
        scanf("%d%d",&n,&m);
        if(n==m)
        {
            printf("0\n");
            continue;
        }
        i=bs(n,0,f-1);
        if(i==-1)
        {
            printf("i = -1\n");
            break;
        }
        d[i]=0;
        q.push(i);c=false;
        while(1)
        {
            if(c)
            {
                while(!q.empty()) q.pop();
                break;
            }
            x=q.front();q.pop();
            //printf("x = %d\n",a[x]);
            for(j=0;j<f;j++)
            {
                if(d[j]==-1&&dif(a[x],a[j]))
                {
                    /* if(s==0)
                     {
                         printf("x = %d        ",a[x]);s=1;
                     }
                     printf("%d   ",a[j]);*/
                    q.push(j);
                    d[j]=d[x]+1;
                    if(a[j]==m)
                    {
                        c=true;i=j;
                        break;
                    }
                }
            }
            //if(s==1)
            // printf("\n");
        }
        printf("%d\n",d[i]);
    }
    return 0;
}
