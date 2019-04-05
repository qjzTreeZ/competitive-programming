#include <bits/stdc++.h>
using namespace std;

//{{{
inline int gi() {
    int x, f = 0;
    char c;
    while (!isdigit(c = getchar())) c == '-' && (f = 1);
    for (x = c - '0'; isdigit(c = getchar()); x = x * 10 + c - '0')
        ;
    return f ? -x : x;
}

inline long long gll() {
    int f = 0;
    long long x;
    char c;
    while (!isdigit(c = getchar())) c == '-' && (f = 1);
    for (x = c - '0'; isdigit(c = getchar()); x = x * 10 + c - '0')
        ;
    return f ? -x : x;
}

template <typename T>
void puti(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) puti(x / 10);
    putchar(x % 10 + '0');
}

template <typename T>
inline void putsp(T x) {
    puti(x), putchar(' ');
}

template <typename T>
inline void putln(T x) {
    puti(x), putchar('\n');
}
//}}}

const int N = 500010, E = N << 1;
int n, m, s, e0[N], e1[E], to[E], q0[N], q1[E], qi[E], id[E], ans[N], p[N];
bool vis[N];

int finds(int x) { return p[x] == x ? x : p[x] = finds(p[x]); }

void tarjan(int u, int fa) {
    for (int e = e0[u]; e; e = e1[e]) {
        int v = to[e];
        if (v == fa) continue;
        tarjan(v, u), p[finds(v)] = u, vis[v] = 1;
    }
    for (int q = q0[u]; q; q = q1[q]) {
        int a = id[q], v = qi[q];
        if (vis[v] && !ans[a]) ans[a] = finds(v);
    }
}

int main() {
    n = gi(), m = gi(), s = gi();
    for (int i = 1; i < n; ++i) {
        int x = gi(), y = gi();
        e1[i << 1] = e0[x], e0[x] = i << 1, to[i << 1] = y,
                e1[i << 1 | 1] = e0[y], e0[y] = i << 1 | 1, to[i << 1 | 1] = x;
    }
    for (int i = 1; i <= m; ++i) {
        int x = gi(), y = gi();
        id[i << 1] = id[i << 1 | 1] = i, q1[i << 1] = q0[x], q0[x] = i << 1,
                qi[i << 1] = y, q1[i << 1 | 1] = q0[y], q0[y] = i << 1 | 1,
                qi[i << 1 | 1] = x;
    }
    for (int i = 1; i <= n; ++i) p[i] = i;
    tarjan(s, 0);
    for (int i = 1; i <= m; ++i) putln(ans[i]);
    return 0;
}
