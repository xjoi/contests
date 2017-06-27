#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn = 100;
const LL mod = 1E9 + 7;
int n, m;
bool map[maxn + 1][maxn + 1];
int d[maxn + 1], f[maxn + 1], cnt[maxn + 1];
int Gf(int k) {
    return (k != f[k]) ? (f[k] = Gf(f[k])) : (k);
}
int p[maxn + 1];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        f[i] = i;
    for (int i = 1; i <= m; ++i) {
        int x;
        scanf("%d", &x);
        if (!map[i][x]) {
            map[i][x] = map[x][i] = 1;
            ++d[i];
            ++d[x];
            int k1 = Gf(i), k2 = Gf(x);
            if (k1 != k2) f[k2] = k1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        int k = Gf(i);
        ++cnt[k];
        if (d[i] >= 3) p[k] = 1;
        if (d[i] < 2 && !p[k]) p[k] = 2;
    }
    int tot = 0;
    LL temp = 1;
    for (int i = 1; i <= n; ++i)
        if (i == f[i]) {
            if ((!p[i] && cnt[i] < n) || p[i] == 1) {
                puts("0");
                return 0;
            }
            ++tot;
            if (cnt[i] > 1 && n != 2) temp = temp * 2 % mod; 
        }
    for (int i = 1; i < tot; ++i)
        temp = temp * i % mod;
    printf("%lld\n", temp);
    return 0;
}
