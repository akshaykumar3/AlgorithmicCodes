// https://www.hackerrank.com/challenges/stockmax
using namespace std;

#include<stdio.h>
#include<iostream>
//#include<queue>

//#define MAX 2147483647
#define get1(a) (scanf("%d",&a))
//#define get2(a, b) (scanf("%d%d",&a,&b))
//#define get3(a, b, c) (scanf("%d%d%d",&a,&b,&c))
//#define p pair<int,int>
#define max(a, b) (a>b?a:b)
//#define min(a, b) (a>b?b:a)

int a[50000];

int main() {
    int t,n,i,cur;
    long long sum;
    get1(t);
    while(t--) {
        get1(n);
        for (i = 0; i < n; ++i) {
            get1(a[i]);
        }
        sum = 0;
        cur = 0;
        for (i=n-1;i>-1;i--) {
            cur=max(cur,a[i]);
            sum +=(cur-a[i]);
        }
        printf("%lld\n",sum);
    }
    return 0;
}