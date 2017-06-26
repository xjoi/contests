#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn = 1000;
const LL mod = 1E9 + 7;
int n, m, last = 0;
LL Pow(LL a, LL b) {
    LL c = 1;
    while (b) {
        if (b & 1) c = c * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return c;
}
LL f[maxn + 1], p[maxn + 1];
LL cnt;
bool s[maxn + 1];
int main() {
    scanf("%d%d", &n, &m);
    f[0] = 1;
    for (int i = 1; i <= n; ++i)
        f[i] = f[i - 1] * i % mod;
    p[n] = Pow(f[n], mod - 2);
    for (int i = n - 1; i >= 0; --i)
        p[i] = p[i + 1] * (i + 1) % mod;
    cnt = f[n - m];
    for (int i = 1, x; i <= m; ++i) {
        scanf("%d", &x);
        s[x] = 1;
    }
    for (int i = 1; i <= n; ++i)
        if (s[i]) {
            if (i - last > 1) {
                if (last) cnt = cnt * Pow(2, i - last - 2) % mod;
                cnt = cnt * p[i - last - 1] % mod;
            }
            last = i;
        }
    if (last < n) cnt = cnt * p[n - last] % mod;
    printf("%d\n", cnt);
    return 0;
}
