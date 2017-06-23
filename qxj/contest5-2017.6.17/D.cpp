#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxt = 100, maxn = 100001, mod = 1E9 + 7;
int a, b, k, t, cnt = 0;
int f[maxn << 1 | 1], sum[maxn << 1 | 1];
int main() {
    scanf("%d%d%d%d", &a, &b, &k, &t);
    f[maxn] = 1;
    for (int i = 1; i <= t; ++i) {
        sum[-k * i + maxn - 1] = 0;
        for (int j = -k * i + maxn, p = k * i + maxn; j <= p; ++j)
            sum[j] = (sum[j - 1] + f[j]) % mod;
        for (int j = -k * i + maxn, p = -k * i + k * 2 + maxn; j < p; ++j)
            f[j] = sum[j + k];
        for (int j = k * i + maxn, p = k * i - k * 2 + maxn, q = k * i + maxn; j > p; --j)
            f[j] = (sum[q] - sum[j - k - 1] + mod) % mod;
        for (int j = -k * i + k * 2 + maxn, p = k * i - k * 2 + maxn; j <= p; ++j)
            f[j] = (sum[j + k] - sum[j - k - 1] + mod) % mod;
    }
    sum[-k * t + maxn - 1] = 0;
    for (int i = -k * t + maxn, j = k * t + maxn; i <= j; ++i)
        sum[i] = (sum[i - 1] + f[i]) % mod;
    for (int i = -k * t, j = -k * t - 1, p = k * t; i <= p; ++i) {
        while (j < p && i - j - 1 > b - a) ++j;
        cnt = (cnt + LL(f[i + maxn]) * sum[j + maxn] % LL(mod)) % mod;
    }
    printf("%d\n", cnt);
    return 0;
}
