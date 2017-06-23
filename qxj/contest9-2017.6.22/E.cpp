#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 100000;
int n, m, N;
int a[maxn + 1], A[maxn + 1], b[maxn << 1 | 1];
struct Qs {
    int t, a, b;
} Q[maxn + 1];
map<int, int> Map;
bool c[maxn << 1 | 1];
struct mes {
    int cnt;
    LL sum, ans;
    mes operator + (const mes &Other) const {
        mes A;
        A.cnt = cnt + Other.cnt;
        A.sum = sum + Other.sum;
        A.ans = ans + Other.ans + Other.sum * cnt - sum * Other.cnt;
        return A;
    }
};
struct node {
    int l, r;
    mes imt;
} p[maxn << 3 | 1];
void Build(int k, int l, int r) {
    p[k].l = l;
    p[k].r = r;
    if (l == r) {
        if (c[l]) p[k].imt = (mes) {1, b[l], 0};
        else p[k].imt = (mes) {0, 0, 0};
        return;
    }
    Build(k << 1, l, (l + r) >> 1);
    Build(k << 1 | 1, ((l + r) >> 1) + 1, r);
    p[k].imt = p[k << 1].imt + p[k << 1 | 1].imt;
    return;
}
void Insert(int k, int x) {
    if (p[k].l == x && x == p[k].r) {
        p[k].imt = (mes) {1, b[x], 0};
        return;
    }
    if (x <= p[k << 1].r) Insert(k << 1, x);
    else Insert(k << 1 | 1, x);
    p[k].imt = p[k << 1].imt + p[k << 1 | 1].imt;
    return;
}
void Del(int k, int x) {
    if (p[k].l == x && x == p[k].r) {
        p[k].imt = (mes) {0, 0, 0};
        return;
    }
    if (x <= p[k << 1].r) Del(k << 1, x);
    else Del(k << 1 | 1, x);
    p[k].imt = p[k << 1].imt + p[k << 1 | 1].imt;
    return;
}
mes Query(int k, int l, int r) {
    if (l <= p[k].l && p[k].r <= r) return p[k].imt;
    mes A = (mes) {0, 0, 0};
    if (l <= p[k << 1].r) A = Query(k << 1, l, r);
    if (p[k << 1 | 1].l <= r) A = A + Query(k << 1 | 1, l, r);
    return A;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        b[i] = A[i] = a[i];
    }
    N = n;
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &Q[i].t, &Q[i].a, &Q[i].b);
        if (Q[i].t == 1) b[++N] = (A[Q[i].a] += Q[i].b);
    }
    sort(b + 1, b + N + 1);
    N = unique(b + 1, b + N + 1) - b - 1;
    for (int i = 1; i <= N; ++i)
        Map[b[i]] = i;
    for (int i = 1; i <= n; ++i)
        c[Map[a[i]]] = 1;
    Build(1, 1, N);
    for (int i = 1; i <= m; ++i)
        if (Q[i].t == 1) {
            Del(1, Map[a[Q[i].a]]);
            Insert(1, Map[a[Q[i].a] += Q[i].b]);
        } else {
            if (Q[i].b < b[1] || b[N] < Q[i].a) {
                printf("0\n");
                continue;
            }
            int l = lower_bound(b + 1, b + N + 1, Q[i].a) - b,
                r = upper_bound(b + 1, b + N + 1, Q[i].b) - b - 1;
            printf("%lld\n", Query(1, l, r).ans);
        }
    return 0;
}
