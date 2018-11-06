#include <bits/stdc++.h>
using namespace std;

inline int geti() {
    int x, f = 0;
    int c;
    while (!isdigit(c = getchar()))
        if (c == '-') f = 1;
    for (x = c - '0'; isdigit(c = getchar()); x = x * 10 + c - '0')
        ;
    return f ? -x : x;
}

inline unsigned getu() {
    unsigned x;
    int c;
    while (!isdigit(c = getchar()))
        ;
    for (x = c - '0'; isdigit(c = getchar()); x = x * 10 + c - '0')
        ;
    return x;
}

const int N = 2010, M = 3010, INF = 2147483647;
int n, m;
int e0[N], e1[M << 1], dst[M << 1], w[M << 1], dist[N], cnt[N], vis[N];

queue<int> q;

inline void clear() {
    for (int i = 1; i <= n; ++i) {
        cnt[i] = 0;
        dist[i] = INF;
    }
    while (!q.empty()) {
        vis[q.front()] = 0;
        q.pop();
    }
}

inline void push(int v) {
    ++cnt[v];
    vis[v] = 1;
    q.push(v);
}

inline int pop() {
    int v = q.front();
    vis[v] = 0;
    q.pop();
    return v;
}

int detect() {
    clear();
    dist[1] = 0;
    push(1);
    while (!q.empty()) {
        int u = pop();
        for (int e = e0[u]; e; e = e1[e]) {
            int v = dst[e];
            int ndist = dist[u] + w[e];
            if (ndist < dist[v]) {
                dist[v] = ndist;
                if (vis[v]) continue;
                if (cnt[v] >= n) return true;
                push(v);
            }
        }
    }
    return false;
}

int main() {
    int T = getu();
    while (T--) {
        n = getu();
        m = getu();
        int ecnt = 0;
        for (int i = 1; i <= n; ++i) e0[i] = 0;
        while (m--) {
            int a = getu(), b = getu(), w0 = geti();
            e1[++ecnt] = e0[a];
            e0[a] = ecnt;
            dst[ecnt] = b;
            w[ecnt] = w0;
            if (w0 >= 0) {
                e1[++ecnt] = e0[b];
                e0[b] = ecnt;
                dst[ecnt] = a;
                w[ecnt] = w0;
            }
        }
        puts(detect() ? "YE5" : "N0");
    }
    return 0;
}