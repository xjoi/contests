#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 3000, maxm = 3000;
int n, m, s1, t1, l1, s2, t2, l2, Min;
int tot = -1, head[maxn + 1];
struct node {
    int p, next;
} edge[maxm << 1];
inline void Add(int u, int v) {
    edge[++tot] = (node) {v, head[u]};
    head[u] = tot;
    return;
}
int f[maxn + 1][maxn + 1];
queue<int> Q;
void BFS(int s) {
    f[s][s] = 0;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].p;
            if (!~f[s][v]) {
                f[s][v] = f[s][u] + 1;
                Q.push(v);
            }
        }
    }
    return;
}
int main() {
    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        Add(u, v);
        Add(v, u);
    }
    memset(f, -1, sizeof(f));
    for (int i = 1; i <= n; ++i)
        BFS(i);
    scanf("%d%d%d%d%d%d", &s1, &t1, &l1, &s2, &t2, &l2);
    Min = m + 1;
    if (f[s1][t1] <= l1 && f[s2][t2] <= l2) Min = f[s1][t1] + f[s2][t2];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            int k1 = f[s1][i] + f[i][j] + f[j][t1],
                k2 = f[s2][i] + f[i][j] + f[j][t2];
            if (k1 <= l1 && k2 <= l2) Min = min(Min, k1 + k2 - f[i][j]);
            k1 = f[s1][i] + f[i][j] + f[j][t1],
            k2 = f[t2][i] + f[i][j] + f[j][s2];
            if (k1 <= l1 && k2 <= l2) Min = min(Min, k1 + k2 - f[i][j]);
        }
    printf("%d\n", m - Min);
    return 0;
}
