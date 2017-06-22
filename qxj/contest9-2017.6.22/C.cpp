#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef long long LL;
const int maxn = 50;
const LL mod = 1E9 + 7;
int n, k, cnt = 0;
LL f[maxn + 1][maxn + 1][2];
int d[maxn + 1][maxn + 1][2];
struct node {
    int c[2][2];
    bool p;
};
queue<node> Q;
LL C[maxn + 1][maxn + 1];
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1, a; i <= n; ++i) {
        scanf("%d", &a);
        if (a == 50) ++cnt;
    }
    for (int i = 0; i <= n; ++i)
        C[i][0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    memset(d, -1, sizeof(d));
    d[0][cnt][0] = 0;
    f[0][cnt][0] = 1;
    node s = {};
    s.c[0][0] = cnt;
    s.c[0][1] = n - cnt;
    Q.push(s);
    while (!Q.empty()) {
        node u = Q.front();
        Q.pop();
        if (u.p && u.c[1][0] + u.c[1][1] == n) continue;
        int cnt1 = u.c[u.p][0], cnt2 = u.c[u.p][1];
        for (int i = 0, sum1 = 0; i <= cnt1 && sum1 <= k; ++i, sum1 += 50)
            for (int j = 1 - bool(i), sum2 = j * 100; j <= cnt2 && sum1 + sum2 <= k; ++j, sum2 += 100) {
                node v = u;
                v.c[v.p][0] -= i;
                v.c[v.p][1] -= j;
                v.p ^= 1;
                v.c[v.p][0] += i;
                v.c[v.p][1] += j;
                if (!~d[v.c[1][1]][v.c[0][0]][v.p]) {
                    d[v.c[1][1]][v.c[0][0]][v.p] = d[u.c[1][1]][u.c[0][0]][u.p] + 1;
                    f[v.c[1][1]][v.c[0][0]][v.p] = f[u.c[1][1]][u.c[0][0]][u.p] * C[cnt1][i] % mod * C[cnt2][j] % mod;
                    Q.push(v);
                } else {
                    if (d[v.c[1][1]][v.c[0][0]][v.p] == d[u.c[1][1]][u.c[0][0]][u.p] + 1)
                        f[v.c[1][1]][v.c[0][0]][v.p] = (f[v.c[1][1]][v.c[0][0]][v.p] + f[u.c[1][1]][u.c[0][0]][u.p] * C[cnt1][i] % mod * C[cnt2][j] % mod) % mod;
                }
            }
    }
    printf("%d\n%lld\n", d[n - cnt][0][1], f[n - cnt][0][1]);
    return 0;
}
