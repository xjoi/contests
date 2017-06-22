#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef long long LL;
const int maxn = 500;
int n;
int map[maxn + 1][maxn + 1];
int rest[maxn + 1];
int dis[maxn + 1][maxn + 1];
LL ans[maxn + 1];
queue<int> Q;
bool exist[maxn + 1];
void SPFA1(int k) {
    int s = rest[k];
    Q.push(s);
    exist[s] = 1;
    for (int i = 1; i <= k; ++i) {
        int u = rest[i];
        if (dis[s][u] > map[s][u]) {
            dis[s][u] = map[s][u];
            Q.push(u);
        }
    }
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        exist[u] = 0;
        for (int i = 1; i <= k; ++i) {
            int v = rest[i];
            if (dis[s][v] > dis[s][u] + dis[u][v]) {
                dis[s][v] = dis[s][u] + dis[u][v];
                if (!exist[v]) {
                    Q.push(v);
                    exist[v] = 1;
                }
            }
        }
    }
    return;
}
void SPFA2(int k) {
    int s = rest[k];
    Q.push(s);
    exist[s] = 1;
    for (int i = 1; i <= k; ++i) {
        int u = rest[i];
        if (dis[u][s] > map[u][s]) {
            dis[u][s] = map[u][s];
            Q.push(u);
        }
    }
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        exist[u] = 0;
        for (int i = 1; i <= k; ++i) {
            int v = rest[i];
            if (dis[v][s] > dis[v][u] + dis[u][s]) {
                dis[v][s] = dis[v][u] + dis[u][s];
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
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &map[i][j]);
    for (int i = n; i; --i)
        scanf("%d", &rest[i]);
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; ++i) {
        int s = rest[i];
        SPFA1(i);
        SPFA2(i);
        LL sum = 0;
        for (int j = 1; j <= i; ++j)
            for (int k = 1; k <= i; ++k) {
                int u = rest[j], v = rest[k];
                if (dis[u][v] > dis[u][s] + dis[s][v]) dis[u][v] = dis[u][s] + dis[s][v];
                sum += dis[u][v];
            }
        ans[n - i + 1] = sum;
    }
    for (int i = 1; i <= n; ++i)
        printf("%lld ", ans[i]);
    return 0;
}
