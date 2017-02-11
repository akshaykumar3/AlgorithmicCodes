// https://www.hackerrank.com/challenges/coin-change
using namespace std;

#include<stdio.h>
#include<iostream>
//#include<queue>

//#define MAX 2147483647
#define get1(a) (scanf("%d",&a))
#define get2(a, b) (scanf("%d%d",&a,&b))
//#define get3(a, b, c) (scanf("%d%d%d",&a,&b,&c))
//#define p pair<int,int>
//#define max(a, b) (a>b?a:b)
//#define min(a, b) (a>b?b:a)

long long a[251];
int b[50];

int main() {
    int n, m, i, j;
    get2(n, m);
    for (i = 0; i < m; ++i) {
        get1(b[i]);
    }
    a[0] = 1;
    for (j = 0; j < m; ++j) {
        for (i = b[j]; i <= n; ++i) {
            a[i] += a[i - b[j]];
        }
    }
    printf("%lld\n", a[n]);
    return 0;
}
