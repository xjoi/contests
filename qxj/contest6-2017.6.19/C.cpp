#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 500, maxm = 500, maxb = 500;
int n, m, b, p, cnt = 0;
int a[maxn + 1];
int f[maxm + 1][maxb + 1];
int main() {
    scanf("%d%d%d%d", &n, &m, &b, &p);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            for (int k = a[i]; k <= b; ++k)
                f[j][k] = (f[j][k] + f[j - 1][k - a[i]]) % p;
    for (int i = 0; i <= b; ++i)
        cnt = (cnt + f[m][i]) % p;
    printf("%d\n", cnt);
    return 0;
}
