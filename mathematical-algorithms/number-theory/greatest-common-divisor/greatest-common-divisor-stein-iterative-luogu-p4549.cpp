#include <bits/stdc++.h>
using namespace std;

inline int geti() {
    int x, f = 0;
    char c;
    while (!isdigit(c = getchar()))
        if (c == '-') f = 1;
    for (x = c - '0'; isdigit(c = getchar()); x = x * 10 + c - '0')
        ;
    return f ? -x : x;
}

template <typename T>
void puti(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) puti(x / 10);
    putchar(x % 10 + '0');
}

template <typename T>
void putsp(T x) {
    puti(x);
    putchar(' ');
}

template <typename T>
void putln(T x) {
    puti(x);
    putchar('\n');
}

int gcd(int a, int b) {
    if (!(a && b)) return a | b;
    int k = 0;
    while (!((a | b) & 1)) a >>= 1, b >>= 1, ++k;
    while (!(a & 1)) a >>= 1;
    do {
        while (!(b & 1)) b >>= 1;
        if (a > b) swap(a, b);
        b -= a;
    } while (b);
    return a << k;
}

int main() {
    int _ = geti(), __ = 0;
    while (_--) __ = gcd(__, abs(geti()));
    putln(__);
    return 0;
}