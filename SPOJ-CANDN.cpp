using namespace std;

#include<stdio.h>
#include<iostream>
#include<queue>

#define MAX 2147483647
#define p pair<int,int>
#define max(a, b) (a>b?a:b)
int d[5001], c[5001], n[5001];
bool vis[5001];
priority_queue<p, vector<p >, greater<p > > q;
vector<p > a[5001];

int main() {
    int nodes, b, charl, nito, e, x, y, w, u, m, v, i, s;
    while (1) {
        scanf("%d%d%d%d%d", &nodes, &b, &charl, &nito, &e);
        if (nodes == -1)
            break;
        for (i = 0; i <= nodes; i++) {
            a[i].clear();
            d[i] = MAX;
            vis[i] = false;
        }
        while (e--) {
            scanf("%d%d%d", &x, &y, &w);
            a[x].push_back(p(w, y));
            a[y].push_back(p(w, x));
        }
        while (!q.empty())
            q.pop();
        d[b] = 0;
        q.push(p(0, b));
        while (!q.empty()) {
            u = q.top().second;
            w = q.top().first;
            q.pop();
            for (i = 0; i < a[u].size(); i++) {
                v = a[u][i].second;
                m = a[u][i].first;
                if (!vis[v] && d[v] > (m + w)) {
                    d[v] = m + w;
                    q.push(p(d[v], v));
                }
            }
            vis[u] = true;
            if (vis[charl] && vis[nito])
                break;
        }
        for (i = 0; i <= nodes; i++) {
            vis[i] = false;
            c[i] = MAX;
        }
        while (!q.empty())
            q.pop();
        c[charl] = 0;
        q.push(p(0, charl));
        while (!q.empty()) {
            u = q.top().second;
            w = q.top().first;
            q.pop();
            for (i = 0; i < a[u].size(); i++) {
                v = a[u][i].second;
                m = a[u][i].first;
                if (!vis[v] && c[v] > (m + w)) {
                    c[v] = m + w;
                    q.push(p(c[v], v));
                }
            }
            vis[u] = true;
            if (vis[b] && vis[nito])
                break;
        }
        for (i = 0; i <= nodes; i++) {
            vis[i] = false;
            n[i] = MAX;
        }
        while (!q.empty())
            q.pop();
        n[nito] = 0;
        q.push(p(0, nito));
        while (!q.empty()) {
            u = q.top().second;
            w = q.top().first;
            q.pop();
            for (i = 0; i < a[u].size(); i++) {
                v = a[u][i].second;
                m = a[u][i].first;
                if (!vis[v] && n[v] > (m + w)) {
                    n[v] = m + w;
                    q.push(p(n[v], v));
                }
            }
            vis[u] = true;
            if (vis[b] && vis[charl])
                break;
        }
        s = 0;
        for (i = 1; i <= nodes; i++) {
            if (d[charl] == (d[i] + c[i]) && d[nito] == (d[i] + n[i])) {
                s = max(s, d[i]);
            }
        }
        printf("%d %d %d\n", s, d[charl] - s, d[nito] - s);
    }
    return 0;
}
