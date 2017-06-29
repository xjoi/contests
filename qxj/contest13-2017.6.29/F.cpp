#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 100000, maxm = 100000;
int n, m;
int c[maxn + 1];
int tot = -1, head[maxn + 1];
struct node1 {
    int p, next;
} edge[maxn << 1];
inline void Add(int u, int v) {
    edge[++tot] = (node1) {v, head[u]};
    head[u] = tot;
    return;
}
struct node2 {
    int l, r, L, k, index;
    bool operator < (const node2 &Other) const {
        return (L != Other.L) ? (L < Other.L) : (r < Other.r);
    }
} Q[maxm + 1];
int Ans[maxn + 1];
int Loc[maxn + 1], Cnt[maxn + 1], col[maxn + 1];
void DFS(int u, int fa) {
    col[Loc[u]] = c[u];
    Cnt[u] = 1;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].p;
        if (v == fa) continue;
        Loc[v] = Loc[u] + Cnt[u];
        DFS(v, u);
        Cnt[u] += Cnt[v];
    }
    return;
}
int ct[maxn + 1], cnt[maxn + 1];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &c[i]);
    memset(head, -1, sizeof(head));
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        Add(u, v);
        Add(v, u);
    }
    Loc[1] = 1;
    DFS(1, 0);
    for (int i = 1, p = sqrt(n), v; i <= m; ++i) {
        scanf("%d%d", &v, &Q[i].k);
        Q[i].l = Loc[v];
        Q[i].r = Loc[v] + Cnt[v] - 1;
        Q[i].L = Q[i].l / p;
        Q[i].index = i;
    }
    sort(Q + 1, Q + m + 1);
    for (int i = 1, l = 1, r = 0; i <= m; ++i) {
        while (l > Q[i].l) ++cnt[++ct[col[--l]]];
        while (r < Q[i].r) ++cnt[++ct[col[++r]]];
        while (l < Q[i].l) --cnt[ct[col[l++]]--];
        while (r > Q[i].r) --cnt[ct[col[r--]]--];
        Ans[Q[i].index] = cnt[Q[i].k];
    }
    for (int i = 1; i <= m; ++i)
        printf("%d\n", Ans[i]);
    return 0;
}
