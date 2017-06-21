#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 20, maxm = 20, INF = 0x7f7f7f7f;
int n, m;
char s[maxn][maxm + 1];
int a[maxn][maxm];
int Min[maxn], state[maxn][maxm], cost[maxn][maxm];
int f[1 << maxn];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%s", s[i]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d", &a[i][j]);
    memset(Min, 0x7f, sizeof(Min));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (a[i][j] < Min[i]) Min[i] = a[i][j];
            int sum = 0, Max = 0, t = 0;
            for (int k = 0; k < n; ++k)
                if (s[i][j] == s[k][j]) {
                    t |= 1 << k;
                    sum += a[k][j];
                    if (a[k][j] > Max) Max = a[k][j];
                }
            state[i][j] = t;
            cost[i][j] = sum - Max;
        }
    memset(f, 0x7f, sizeof(f));
    f[0] = 0;
    for (int i = 0, p = (1 << n) - 1; i < p; ++i)
        if (f[i] < INF) {
            int j;
            for (j = 0; j < n; ++j)
                if (!(i & (1 << j))) break;
            f[i | (1 << j)] = min(f[i | (1 << j)], f[i] + Min[j]);
            for (int k = 0; k < m; ++k)
                f[i | state[j][k]] = min(f[i | state[j][k]], f[i] + cost[j][k]);
        }
    printf("%d\n", f[(1 << n) - 1]);
    return 0;
}
