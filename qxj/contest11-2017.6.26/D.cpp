#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
const int maxk = 10000, maxn = 10000, maxm = 10000, INF = 0x7f7f7f7f;
int n, m, k, s, t;
int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};
int tot = -1, head[maxk + maxn + maxm + 2];
struct node {
    int p, next, w;
} edge[maxk * 20 + 2];
inline void Add(int u, int v, int w) {
    edge[++tot] = (node) {v, head[u], w};
    head[u] = tot;
    return;
}
map<pair<int, int>, int> Map;
int d[maxn + maxm + maxk + 2];
queue<int> Q;
bool exist[maxn + maxm + maxk + 2];
void SPFA() {
    memset(d, 0x7f, sizeof(d));
    d[s] = 0;
    Q.push(s);
    exist[s] = 1;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        exist[u] = 0;
        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].p, w = edge[i].w;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                if (!exist[v]) {
                    Q.push(v);
                    exist[v] = 1;
                }
            }
        }
    }
    return;
}
int main() {
    scanf("%d%d%d", &n, &m, &k);
    memset(head, -1, sizeof(head));
    for (int i = 1, r, c; i <= k; ++i) {
        scanf("%d%d", &r, &c);
        for (int j = 0, temp; j < 4; ++j)
            if (temp = Map[make_pair(r + dr[j], c + dc[j])]) {
                Add(i, temp, 0);
                Add(temp, i, 0);
            }
        Map[make_pair(r, c)] = i;
        Add(i, k + r, 1);
        Add(k + r, i, 0);
        if (r > 1) {
            Add(i, k + r - 1, 1);
            Add(k + r - 1, i, 0);
        }
        if (r < n) {
            Add(i, k + r + 1, 1);
            Add(k + r + 1, i, 0);
        }
        Add(i, k + n + c, 1);
        Add(k + n + c, i, 0);
        if (c > 1) {
            Add(i, k + n + c - 1, 1);
            Add(k + n + c - 1, i, 0);
        }
        if (c < m) {
            Add(i, k + n + c + 1, 1);
            Add(k + n + c + 1, i, 0);
        }
    }
    s = Map[make_pair(1, 1)];
    t = Map[make_pair(n, m)];
    if (!t) {
        t = k + n + m + 1;
        Add(k + n, t, 0);
        Add(k + n + m, t, 0);
    }
    SPFA();
    printf("%d\n", (d[t] != INF) ? (d[t]) : (-1));
    return 0;
}
