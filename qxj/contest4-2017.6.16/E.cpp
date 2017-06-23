#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
inline void Read(int &x) {
    char c;
    while (c = getchar(), !isdigit(c));
    x = c - 48;
    while (c = getchar(), isdigit(c)) x = x * 10 + c - 48;
    return;
}
inline void Writeln(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    int a[20], k = 0;
    do a[++k] = x % 10;
    while (x /= 10);
    while (k) putchar(a[k--] + 48);
    putchar(' ');
    return;
}
const int maxn = 100000, maxm = 100000, INF = 0x7fffffff;
int n, m, N;
int Pair[maxn + maxm + 1];
struct node1 {
    int l, r, t, index;
    bool operator < (const node1 &Other) const {
        if (t != Other.t) return t < Other.t;
        return index > Other.index;
    }
} a[maxn + maxm + 1];
struct node2 {
    int x, index;
    bool operator < (const node2 &Other) const {
        if (x != Other.x) return x < Other.x;
        return index < Other.index;
    }
} b[maxn + maxm + 1];
struct node {
    int l, r, Min, index;
} p[(maxn + maxm) << 2 | 1];
void Build(int k, int l, int r) {
    p[k].l = l;
    p[k].r = r;
    p[k].Min = INF;
    p[k].index = 0;
    if (l == r) return;
    Build(k << 1, l, (l + r) >> 1);
    Build(k << 1 | 1, ((l + r) >> 1) + 1, r);
    return;
}
inline void Update(int k) {
    if (p[k << 1].Min < p[k << 1 | 1].Min) {
        p[k].Min = p[k << 1].Min;
        p[k].index = p[k << 1].index;
    } else {
        p[k].Min = p[k << 1 | 1].Min;
        p[k].index = p[k << 1 | 1].index;
    }
    return;
}
void Insert(int k, int index) {
    if (p[k].l == a[index].l && a[index].l == p[k].r) {
        p[k].Min = a[index].r;
        p[k].index = index;
        return;
    }
    if (a[index].l <= p[k << 1].r) Insert(k << 1, index);
    else Insert(k << 1 | 1, index);
    Update(k);
    return;
}
void Del(int k, int x) {
    if (p[k].l == x && x == p[k].r) {
        p[k].Min = INF;
        p[k].index = 0;
        return;
    }
    if (x <= p[k << 1].r) Del(k << 1, x);
    else Del(k << 1 | 1, x);
    Update(k);
    return;
}
int Query(int k, int l, int r) {
    if (l <= p[k].l && p[k].r <= r) return p[k].index;
    int index = 0;
    if (l <= p[k << 1].r) index = Query(k << 1, l, r);
    if (p[k << 1 | 1].l <= r) {
        int K = Query(k << 1 | 1, l, r);
        if (a[index].r > a[K].r) index = K;
    }
    return index;
}
int main() {
    Read(n);
    Read(m);
    N = n + m;
    for (int i = 1; i <= N; ++i) {
        Read(a[i].l);
        Read(a[i].r);
        Read(a[i].t);
        b[i].x = a[i].l;
        a[i].index = b[i].index = i;
    }
    sort(b + 1, b + N + 1);
    for (int i = 1; i <= N; ++i)
        a[b[i].index].l = i;
    sort(a + 1, a + N + 1);
    a[0].r = INF;
    memset(Pair, -1, sizeof(Pair));
    Build(1, 1, N);
    for (int i = 1; i <= N; ++i)
        if (a[i].index <= n) {
            int j;
            while (j = Query(1, a[i].l, n + m), a[j].r <= a[i].r) {
                Pair[a[j].index - n] = a[i].index;
                Del(1, a[j].l);
            }
        } else Insert(1, i);
    for (int i = 1; i <= m; ++i)
        Writeln(Pair[i]);
    return 0;
}
