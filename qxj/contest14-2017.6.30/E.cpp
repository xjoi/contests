#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
typedef pair<LL, int> PI;
LL Gcd(LL a, LL b) {
    return (b) ? (Gcd(b, a % b)) : (a);
}
LL Ex_gcd(LL a, LL b, LL &x, LL &y) {
    if (b) {
        LL temp = Ex_gcd(b, a % b, x, y), X = x;
        x = y;
        y = X - a / b * y;
        return temp;
    }
    x = 1;
    y = 0;
    return a;
}
const int maxn = 100000;
int n;
LL m, ans = 0;
LL p[maxn];
int tot = -1, head[maxn];
struct node {
    int p, next, w;
} edge[maxn << 1];
inline void Add(int u, int v, int w) {
    edge[++tot] = (node) {v, head[u], w};
    head[u] = tot;
    return;
}
bool vis[maxn];
int root, cnt;
int Max[maxn], size[maxn];
void Gr(int u) {
    size[u] = 1;
    Max[u] = 0;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].p;
        if (vis[v]) continue;
        vis[v] = 1;
        Gr(v);
        vis[v] = 0;
        size[u] += size[v];
        if (size[v] > Max[u]) Max[u] = size[v];
    }
    if (cnt - size[u] > Max[u]) Max[u] = cnt - size[u];
    if (!~root || Max[u] < Max[root]) root = u;
    return;
}
vector<PI> V;
map<LL, int> Map;
void DFS1(int u, int dep, LL d1, LL d2) {
    if (!d1) ++ans;
    if (!d2) ++ans;
    ++Map[d1];
    V.push_back(make_pair(d2, dep));
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].p, w = edge[i].w;
        if (vis[v]) continue;
        vis[v] = 1;
        DFS1(v, dep + 1, (p[dep] * w + d1) % m, (d2 * 10 + w) % m);
        vis[v] = 0;
    }
    return;
}
LL Calc1(int u) {
    LL cnt = 0;
    V.clear();
    Map.clear();
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].p, w = edge[i].w;
        if (vis[v]) continue;
        vis[v] = 1;
        DFS1(v, 1, w, w);
        vis[v] = 0;
    }
    for (int i = 0, n = V.size(); i < n; ++i) {
        PI cur = V[i];
        LL g = Gcd(m, p[cur.second]);
        if (cur.first % g) continue;
        LL x, y;
        Ex_gcd(m / g, p[cur.second] / g, x, y);
        LL P = (-y % m + m) % m * g % m * cur.first % m;
        cnt += Map[P];
    }
    return cnt;
}
void DFS2(int u, int dep, LL d1, LL d2) {
    ++Map[d1];
    V.push_back(make_pair(d2, dep));
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].p, w = edge[i].w;
        if (vis[v]) continue;
        vis[v] = 1;
        DFS2(v, dep + 1, (p[dep] * w + d1) % m, (d2 * 10 + w) % m);
        vis[v] = 0;
    }
    return;
}
LL Calc2(int u, int w) {
    LL cnt = 0;
    V.clear();
    Map.clear();
    vis[u] = 1;
    DFS2(u, 1, w, w);
    vis[u] = 0;
    for (int i = 0, n = V.size(); i < n; ++i) {
        PI cur = V[i];
        LL g = Gcd(m, p[cur.second]);
        if (cur.first % g) continue;
        LL x, y;
        Ex_gcd(m / g, p[cur.second] / g, x, y);
        LL P = (-y % m + m) % m * g % m * cur.first % m;
        cnt += Map[P];
    }
    return cnt;
}
void Divide(int u) {
    root = -1;
    vis[u] = 1;
    Gr(u);
    vis[u] = 0;
    vis[root] = 1;
    ans += Calc1(root);
    for (int i = head[root]; ~i; i = edge[i].next) {
        int v = edge[i].p, w = edge[i].w;
        if (vis[v]) continue;
        ans -= Calc2(v, w);
    }
    for (int i = head[root]; ~i; i = edge[i].next) {
        int v = edge[i].p;
        if (vis[v]) continue;
        cnt = size[v];
        Divide(v);
    }
    return;
}
int main() {
    scanf("%d%lld", &n, &m);
    p[0] = 1;
    for (int i = 1; i < n; ++i)
        p[i] = p[i - 1] * 10 % m;
    memset(head, -1, sizeof(head));
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        w %= m;
        Add(u, v, w);
        Add(v, u, w);
    }
    cnt = n;
    Divide(0);
    printf("%lld\n", ans);
    return 0;
}
