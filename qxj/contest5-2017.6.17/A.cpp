#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn = 2000, maxm = 2000, mod = 1E9 + 7;
const LL Mod = 1E9 + 7;
int f1[maxn + 1][maxm + 1], f2[maxn + 1][maxm + 1];
int n, m;
LL cnt = 0;
int main() {
    scanf("%d%d", &n, &m);
    for (int j = 2; j <= m; ++j)
        f1[1][j] = 1;
    for (int i = 2; i <= n; ++i) {
        f1[i][2] = f1[i - 1][2] + 1;
        for (int j = 3, sum = f1[i - 1][2]; j <= m; ++j)
            f1[i][j] = (f1[i][j - 1] + (sum = (sum + f1[i - 1][j]) % mod)) % mod;
    }
    for (int j = 2; j <= m; ++j)
        f2[n][j] = 1;
    for (int i = n - 1; i >= 1; --i) {
        f2[i][2] = f2[i + 1][2];
        for (int j = 3, sum = f1[n - i][2]; j <= m; sum = (sum + f1[n - i][j]) % mod, ++j)
            f2[i][j] = ((f2[i][j - 1] + sum) % mod + f1[n - i][j - 1]) % mod;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 2; j <= m; ++j)
            cnt = (cnt + LL(f1[i][j]) * f2[i][j] % Mod * (m - j + 1)) % Mod;
    printf("%lld\n", cnt);
    return 0;
}
