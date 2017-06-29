#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn = 5000;
const LL INF = 0x7fffffffffffffff;
int n;
struct node1 {
    int u, v, w;
} Edge[maxn];
int tot = -1, head[maxn + 1];
struct node2 {
    int p, next, w;
} edge[maxn << 1];
inline void Add(int u, int v, int w) {
    edge[++tot] = (node2) {v, head[u], w};
    head[u] = tot;
    return;
}
int cnt[maxn + 1];
LL DFS1(int u, int fa) {
    LL sum = 0;
    cnt[u] = 1;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].p, w = edge[i].w;
        if (v == fa) continue;
        sum += DFS1(v, u);
        sum += LL(w) * cnt[v];
        cnt[u] += cnt[v];
    }
    return sum;
}
LL DFS2(int u, int fa, int size) {
    LL sum = 0;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].p, w = edge[i].w;
        if (v == fa) continue;
        sum += LL(size - cnt[v]) * cnt[v] * w;
        sum += DFS2(v, u, size);
    }
    return sum;
}
LL DFS3(int u, int fa, int size, LL sum) {
    LL Min = sum;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].p, w = edge[i].w;
        if (v == fa) continue;
        LL s = sum + LL(size - cnt[v] * 2) * w;
        Min = min(Min, DFS3(v, u, size, s));
    }
    return Min;
}
LL Min = INF;
int main() {
    scanf("%d", &n);
    memset(head, -1, sizeof(head));
    for (int i = 1; i < n; ++i) {
        scanf("%d%d%d", &Edge[i].u, &Edge[i].v, &Edge[i].w);
        Add(Edge[i].u, Edge[i].v, Edge[i].w);
        Add(Edge[i].v, Edge[i].u, Edge[i].w);
    }
    for (int i = 1; i < n; ++i) {
        LL sum1 = DFS1(Edge[i].u, Edge[i].v),
           sum2 = DFS1(Edge[i].v, Edge[i].u),
           sum3 = DFS2(Edge[i].u, Edge[i].v, cnt[Edge[i].u]),
           sum4 = DFS2(Edge[i].v, Edge[i].u, cnt[Edge[i].v]),
           sum5 = DFS3(Edge[i].u, Edge[i].v, cnt[Edge[i].u], sum1),
           sum6 = DFS3(Edge[i].v, Edge[i].u, cnt[Edge[i].v], sum2);
        Min = min(Min, sum3 + sum4 + sum5 * cnt[Edge[i].v] + sum6 * cnt[Edge[i].u] + LL(Edge[i].w) * cnt[Edge[i].u] * cnt[Edge[i].v]);
    }
    printf("%lld\n", Min);
    return 0;
}
