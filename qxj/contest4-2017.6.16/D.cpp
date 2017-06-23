#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100000, maxm = 100000;
int n, m;
int c[maxm + 1];
struct node1 {
    int u, v, w, index;
    bool operator < (const node1 &Other) const {
        return w < Other.w;
    }
} Edge[maxm + 1];
int tot = -1, head[maxn + 1];
struct node2 {
    int p, next, index;
} edge[maxm << 1 | 1];
inline void Add(int u, int v, int index) {
    edge[++tot] = (node2) {v, head[u], index};
    head[u] = tot;
    return;
}
int f[maxn + 1], F1[maxn + 1], F2[maxn + 1];
int Gf(int k) {
    return (k != f[k]) ? (f[k] = Gf(f[k])) : (k);
}
int dfn[maxn + 1], low[maxn + 1];
void Tarjan(int u, int num, int k) {
    dfn[u] = low[u] = ++k;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].p;
        if (!dfn[v]) {
            Tarjan(v, i, k);
            low[u] = min(low[u], low[v]);
            if (dfn[u] < low[v]) c[edge[i].index] = 2;
        } else if ((i ^ 1) != num)  low[u] = min(low[u], dfn[v]);
    }
    return;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; Edge[i].index = i, ++i)
        scanf("%d%d%d", &Edge[i].u, &Edge[i].v, &Edge[i].w);
    sort(Edge + 1, Edge + m + 1);
    for (int i = 1; i <= n; ++i)
        f[i] = i;
    memset(head, -1, sizeof(head));
    for (int i = 1, j, tot = n; tot > 1 && i <= m; i = j + 1) {
        for (j = i; j < m && Edge[j].w == Edge[j + 1].w; ++j);
        for (int k = i; k <= j; ++k) {
            F1[k] = Gf(Edge[k].u);
            F2[k] = Gf(Edge[k].v);
            if (F1[k] != F2[k]) {
                c[Edge[k].index] = 1;
                Add(F1[k], F2[k], Edge[k].index);
                Add(F2[k], F1[k], Edge[k].index);
            }
        }
        for (int k = i; k <= j; ++k)
            if (F1[k] != F2[k] && !dfn[F1[k]]) Tarjan(F1[k], -1, 0);
        for (int k = i; k <= j; ++k) {
            head[F1[k]] = head[F2[k]] = -1;
            dfn[F1[k]] = dfn[F2[k]] = 0;
            F1[k] = Gf(F1[k]);
            F2[k] = Gf(F2[k]);
            if (F1[k] != F2[k]) {
                f[F2[k]] = F1[k];
                --tot;
            }
        }
    }
    for (int i = 1; i <= m; ++i)
        if (c[i]) {
            if (c[i] > 1) printf("any\n");
            else printf("at least one\n");
        } else printf("none\n");
    return 0;
}
