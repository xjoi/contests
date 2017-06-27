#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 200;
int n, m;
struct point {
    int x, y;
    point operator - (const point &Other) const {
        return (point) {x - Other.x, y - Other.y};
    }
    int operator * (const point &Other) const {
        return x * Other.y - Other.x * y;
    }
} p[maxn + 1];
struct node {
    int u, v;
} edge[maxn + 1];
int f[maxn + 1];
int Gf(int k) {
    return (k != f[k]) ? (f[k] = Gf(f[k])) : (k);
}
int F(int x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}
bool judge1(int x, int y) {
    if (max(p[edge[x].u].x, p[edge[x].v].x) < min(p[edge[y].u].x, p[edge[y].v].x)) return 0;
    if (min(p[edge[x].u].x, p[edge[x].v].x) > max(p[edge[y].u].x, p[edge[y].v].x)) return 0;
    if (max(p[edge[x].u].y, p[edge[x].v].y) < min(p[edge[y].u].y, p[edge[y].v].y)) return 0;
    if (min(p[edge[x].u].y, p[edge[x].v].y) > max(p[edge[y].u].y, p[edge[y].v].y)) return 0;
    point k = p[edge[x].v] - p[edge[x].u];
    if (F((p[edge[y].u] - p[edge[x].u]) * k) * F((p[edge[y].v] - p[edge[x].u]) * k) > 0) return 0;
    k = p[edge[y].v] - p[edge[y].u];
    if (F((p[edge[x].u] - p[edge[y].u]) * k) * F((p[edge[x].v] - p[edge[y].u]) * k) > 0) return 0;
    return 1;
}
bool judge2(int x, int y) {
    if (p[y].x < min(p[edge[x].u].x, p[edge[x].v].x)) return 0;
    if (p[y].x > max(p[edge[x].u].x, p[edge[x].v].x)) return 0;
    if (p[y].y < min(p[edge[x].u].y, p[edge[x].v].y)) return 0;
    if (p[y].y > max(p[edge[x].u].y, p[edge[x].v].y)) return 0;
    point k = p[edge[x].v] - p[edge[x].u];
    if (F((p[y] - p[edge[x].u]) * k)) return 0;
    k = p[edge[x].u] - p[edge[x].v];
    if (F((p[y] - p[edge[x].v]) * k)) return 0;
    return 1;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &p[i].x, &p[i].y);
    for (int i = 1; i <= n; ++i)
        f[i] = i;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &edge[i].u, &edge[i].v);
        int k1 = Gf(edge[i].u), k2 = Gf(edge[i].v);
        if (k1 != k2) f[k2] = k1;
    }
    for (int i = 1; i < m; ++i)
        for (int j = i + 1; j <= m; ++j)
            if (judge1(i, j)) {
                int k1 = Gf(edge[i].u), k2 = Gf(edge[j].u);
                if (k1 != k2) f[k2] = k1;
            }
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            if (judge2(i, j)) {
                int k1 = Gf(edge[i].u), k2 = Gf(j);
                if (k1 != k2) f[k2] = k1;
            }
    for (int i = 1; i < n; ++i)
        if (Gf(i) != Gf(i + 1)) {
            puts("NO");
            return 0;
        }
    puts("YES");
    return 0;
}
