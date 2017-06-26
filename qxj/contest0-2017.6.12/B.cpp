#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100, INF = 0x7fffffff;
int n, ans = INF, k1 = 0, k2 = 0;
int a[maxn + 1], b[maxn + 1];
int suma[maxn + 1], sumb[maxn + 1];
int main() {
    scanf("%d", &n);
    for (int i = 1, x, y; i <= n; ++i) {
        scanf("%d%d", &x, &y);
        if (x == 1) a[++k1] = y;
        else b[++k2] = y;
    }
    sort(a + 1, a + k1 + 1);
    sort(b + 1, b + k2 + 1);
    for (int i = 1; i <= k1; ++i)
        suma[i] = suma[i - 1] + a[i];
    for (int i = 1; i <= k2; ++i)
        sumb[i] = sumb[i - 1] + b[i];
    for (int i = 0; i <= k1; ++i)
        for (int j = 0; j <= k2; ++j)
            if (k1 - i + ((k2 - j) << 1) >= suma[i] + sumb[j]) ans = min(ans, k1 - i + ((k2 - j) << 1));
    printf("%d\n", ans);
    return 0;
}
