/* https://www.hackerrank.com/challenges/journey-to-the-moon */
using namespace std;

#include<stdio.h>
#include<iostream>
#include<queue>

#define get(a, b) (scanf("%d%d",&a,&b))
#define N 100000
bool vis[N];
vector<int> a[N];
queue<int> q;

int main() {
    int n, i, m, j, x, y, count;
    long long sum = 0, ssum = 0, ans;
    get(n, m);
    while (m--) {
        get(i, j);
        a[i].push_back(j);
        a[j].push_back(i);
    }
    for (i = 0; i < n; i++) {
        if (vis[i])
            continue;

        count = 0;
        q.push(i);
        vis[i] = true;
        while (!q.empty()) {
            x = q.front();
            count++;
            q.pop();
            for (j = 0; j < a[x].size(); ++j) {
                y = a[x][j];
                if (!vis[y]) {
                    q.push(y);
                    vis[y] = true;
                }
            }
        }
        sum += count;
        ssum += (count * count);
    }
    sum *= sum;

    ans = (sum - ssum)/2;
    printf("%lld\n", ans);
    return 0;
}