// https://www.hackerrank.com/challenges/superman-celebrates-diwali
using namespace std;

#include<stdio.h>
#include<iostream>
//#include<queue>

//#define MAX 2147483647
#define get1(a) (scanf("%d",&a))
//#define get2(a, b) (scanf("%d%d",&a,&b))
#define get3(a, b, c) (scanf("%d%d%d",&a,&b,&c))
//#define p pair<int,int>
#define max(a, b) (a>b?a:b)
//#define min(a, b) (a>b?b:a)

int a[1901][1901], p[1901];

int main() {
    int n, m, h, i, j, d;
    get3(n, h, d);
    for (i = 1; i <= n; i++) {
        get1(m);
        while (m--) {
            get1(j);
            a[i][j]++;
        }
    }

    for (j = h; j > 0; --j) {
        m = j + d <= h ? p[j + d] : 0;
        p[j] = 0;
        for (i = 1; i <= n; ++i) {
            int prev = j + 1 <= h ? a[i][j + 1] : 0;
            a[i][j] += max(m, prev);
            p[j] = max(p[j], a[i][j]);
        }
    }
    printf("%d\n", p[1]);
    return 0;
}