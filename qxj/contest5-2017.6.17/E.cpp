#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
inline int Read() {
    char c;
    while (c = getchar(), !isdigit(c));
    int x = c - 48;
    while (c = getchar(), isdigit(c)) x = x * 10 + c - 48;
    return x;
}
const int maxn = 100000;
int n, Q;
double p[maxn + 1];
struct mes {
    double L, R;
    mes operator + (const mes &Other) const {
        mes res;
        res.L = L * Other.L / (1 - R * (1 - Other.L));
        res.R = Other.R + Other.L * R * (1 - Other.R) / (1 - R * (1 - Other.L));
        return res;
    }
};
struct node {
    int l, r;
    mes imt;
} P[maxn << 2 | 1];
void Build(int k, int l, int r) {
    P[k].l = l;
    P[k].r = r;
    if (l == r) {
        P[k].imt = (mes) {p[l], p[r]};
        return;
    }
    Build(k << 1, l, (l + r) >> 1);
    Build(k << 1 | 1, ((l + r) >> 1) + 1, r);
    P[k].imt = P[k << 1].imt + P[k << 1 | 1].imt;
    return;
}
void Insert(int k, int x) {
    if (P[k].l == x && x == P[k].r) {
        P[k].imt = (mes) {
            p[x], p[x]
        };
        return;
    }
    if (x <= P[k << 1].r) Insert(k << 1, x);
    else Insert(k << 1 | 1, x);
    P[k].imt = P[k << 1].imt + P[k << 1 | 1].imt;
    return;
}
mes Query(int k, int r, int l) {
    if (l <= P[k].l && P[k].r <= r) return P[k].imt;
    mes res;
    if (l <= P[k << 1].r) {
        res = Query(k << 1, r, l);
        if (P[k << 1 | 1].l <= r) res = res + Query(k << 1 | 1, r, l);
    } else res = Query(k << 1 | 1, r, l);
    return res;
}
int main() {
    scanf("%d%d", &n, &Q);
    for (int i = 1, a, b; i <= n; ++i)
        p[i] = double(Read()) / Read();
    Build(1, 1, n);
    while (Q--)
        if (Read() == 1) {
            int x = Read();
            p[x] = double(Read()) / Read();
            Insert(1, x);
        } else printf("%.10lf\n", Query(1, Read(), Read()).L);
    return 0;
}
