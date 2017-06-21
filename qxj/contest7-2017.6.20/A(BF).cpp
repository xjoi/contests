#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100000, maxk = 25;
int n, m, k, cnt;
int x[maxn + 1], a[maxn + 1];
int rp[maxk + 1];
int main() {
    while (scanf("%d%d%d", &n, &m, &k) == 3) {
        for (int i = 1; i <= n; ++i)
            scanf("%d", &x[i]);
        for (int i = 1; i <= m; ++i)
            scanf("%d", &a[i]);
        cnt = 0;
        for (int i = 1; i <= n - m + 1; ++i) {
            memset(rp, 0, sizeof(rp));
            bool flag = 0;
            for (int j = 1; j <= m; ++j)
                if (!rp[a[j]]) rp[a[j]] = x[i + j - 1];
                else if (rp[a[j]] != x[i + j - 1]) {
                    flag = 1;
                    break;
                }
            if (flag) continue;
            for (int i = 1; i <= k; ++i)
                if (rp[i]) {
                    for (int last = i, j = i + 1; j <= k; ++j)
                        if (rp[j]) {
                            if (rp[last] >= rp[j]) {
                                flag = 1;
                                break;
                            }
                            last = j;
                        }
                    break;
                }
            if (!flag) {
                ++cnt;
                i += m - 1;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
