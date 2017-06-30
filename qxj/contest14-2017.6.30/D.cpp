#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<LL, int> PI;
const int maxn = 1000, maxm = 10000;
const LL INF = 0x3fffffffffffffff;
int n, m, L, source, sink;
int tot = -1, head[maxn + 1];
struct node {
    int p, next, w;
} edge[maxm << 1];
inline void Add(int u, int v, int w) {
    edge[++tot] = (node) {v, head[u], w};
    head[u] = tot;
    return;
}
bool done[maxn + 1];
LL D_sink[maxn + 1], D_source[maxn + 1];
void Dijkstra(int source, LL *d) {
    fill(d, d + n, INF);
    memset(done, 0, sizeof(done));
    set<PI> S;
    d[source] = 0;
    S.insert(make_pair(0, source));
    while (!S.empty()) {
        PI cur = *S.begin();
        S.erase(S.begin());
        int u = cur.second;
        done[u] = 1;
        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].p, w = edge[i].w;
            if (done[v] || !w) continue;
            if (d[v] > d[u] + w) {
                S.erase(make_pair(d[v], v));
                S.insert(make_pair(d[v] = d[u] + w, v));
            }
        }
    }
    return;
}
void Modified_Dijkstra(int source, LL *d, LL *fromsink) {
    fill(d, d + n, INF);
    memset(done, 0, sizeof(done));
    set<PI> S;
    d[source] = 0;
    S.insert(make_pair(0, source));
    while (!S.empty()) {
        PI cur = *S.begin();
        S.erase(S.begin());
        int u = cur.second;
        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].p, w = edge[i].w;
            if (done[v]) continue;
            if (!w) {
                if (d[u] + fromsink[v] >= L) w = 1;
                else w = LL(L) - d[u] - fromsink[v];
                edge[i].w = edge[i ^ 1].w = w;
            }
            if (d[v] > d[u] + w) {
                S.erase(make_pair(d[v], v));
                S.insert(make_pair(d[v] = d[u] + w, v));
            }
        }
    }
    return;
}
int main() {
    scanf("%d%d%d%d%d", &n, &m, &L, &source, &sink);
    memset(head, -1, sizeof(head));
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        Add(u, v, w);
        Add(v, u, w);
    }
    Dijkstra(sink, D_sink);
    if (D_sink[source] < L) {
        puts("NO");
        return 0;
    }
    Modified_Dijkstra(source, D_source, D_sink);
    if (D_source[sink] != L) puts("NO");
    else {
        puts("YES");
        for (int i = 0; i <= tot; i += 2)
            if (edge[i].w) printf("%d %d %d\n", edge[i ^ 1].p, edge[i].p, edge[i].w);
            else printf("%d %d %d\n", edge[i ^ 1].p, edge[i].p, L);
    }
    return 0;
}
