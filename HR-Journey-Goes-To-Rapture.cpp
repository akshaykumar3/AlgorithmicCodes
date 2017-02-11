/* https://www.hackerrank.com/challenges/jack-goes-to-rapture */
using namespace std;

#include<stdio.h>
#include<iostream>
#include<queue>

#define MAX 2147483647
//#define get1(a) (scanf("%d",&a))
#define get2(a, b) (scanf("%d%d",&a,&b))
#define get3(a, b, c) (scanf("%d%d%d",&a,&b,&c))
#define p pair<int,int>
#define max(a, b) (a>b?a:b)
int d[50001];
priority_queue<p, vector<p >, greater<p > > q;
vector<p > a[50001];

int main() {
    int n, i, x, j, k, y, current;
    get2(n, x);
    while (x--) {
        get3(i, j, k);
        a[i].push_back(p(k, j));
        a[j].push_back(p(k, i));
    }
//    cout<<"Input done.\n";
    for (i = 0; i <= n; ++i) {
        d[i] = MAX;
    }
    d[1] = 0;
    q.push(p(0, 1));
    while (!q.empty()) {
//        cout<<"Inside\n";
        j = q.top().second;
        k = q.top().first;
        q.pop();
        for (i = 0; i < a[j].size(); ++i) {
            x = a[j][i].second;
            y = a[j][i].first;
            current = max((y - k), 0);
            if (d[x] > (k + current)) {
                d[x] = k + current;
                q.push(p(d[x], x));
            }
        }
    }
    if (MAX == d[n]) {
        printf("NO PATH EXISTS\n");
    } else {
        printf("%d\n", d[n]);
    }
    return 0;
}
