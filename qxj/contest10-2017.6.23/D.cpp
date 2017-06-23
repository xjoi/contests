#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 200000, maxm = 200000, INF = 0x7fffffff;
typedef long long LL;
int n, m;
LL ll, lr, l, r;
struct node1 {
    LL l, r;
    int index;
    bool operator < (const node1 &Other) const {
        return (r != Other.r) ? (r < Other.r) : (l > Other.l);
    }
} Q[maxn + 1];
int ans[maxn];
struct node2 {
    LL x;
    int index;
    bool operator < (const node2 &Other) const {
        return x < Other.x;
    }
} a[maxm + 1];
struct node {
    int l, r, Min;
} p[maxm << 2 | 1];
void Build(int k, int l, int r) {
    p[k].l = l;
    p[k].r = r;
    if (l == r) {
        p[k].Min = l;
        return;
    }
    Build(k << 1, l, (l + r) >> 1);
    Build(k << 1 | 1, ((l + r) >> 1) + 1, r);
    p[k].Min = min(p[k << 1].Min, p[k << 1 | 1].Min);
    return;
}
void Del(int k, int x) {
    if (p[k].l == x && x == p[k].r) {
        p[k].Min = INF;
        return;
    }
    if (x <= p[k << 1].r) Del(k << 1, x);
    else Del(k << 1 | 1, x);
    p[k].Min = min(p[k << 1].Min, p[k << 1 | 1].Min);
    return;
}
int Query(int k, int l, int r) {
    if (l <= p[k].l && p[k].r <= r) return p[k].Min;
    int Min = INF;
    if (l <= p[k << 1].r) Min = Query(k << 1, l, r);
    if (p[k << 1 | 1].l <= r) Min = min(Min, Query(k << 1 | 1, l, r));
    return Min;
}
int main() {
    scanf("%d%d%lld%lld", &n, &m, &ll, &lr);
    for (int i = 1; i < n; ++i) {
        scanf("%lld%lld", &l, &r);
        Q[i].l = l - lr;
        Q[i].r = r - ll;
        Q[i].index = i;
        ll = l;
        lr = r;
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%lld", &a[i].x);
        a[i].index = i;
    }
    sort(a + 1, a + m + 1);
    for (int i = 1; i < n; ++i) {
        if (Q[i].r < a[1].x || a[m].x < Q[i].l) {
            puts("No");
            return 0;
        }
        Q[i].l = lower_bound(a + 1, a + m + 1, (node2) {
            Q[i].l
        }) - a;
        Q[i].r = upper_bound(a + 1, a + m + 1, (node2) {
            Q[i].r
        }) - a - 1;
    }
    sort(Q + 1, Q + n);
    Build(1, 1, m);
    for (int i = 1; i < n; ++i) {
        int Min = Query(1, Q[i].l, Q[i].r);
        if (Min != INF) {
            ans[Q[i].index] = a[Min].index;
            Del(1, Min);
        } else {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    for (int i = 1; i < n; ++i)
        printf("%d ", ans[i]);
    return 0;
}
