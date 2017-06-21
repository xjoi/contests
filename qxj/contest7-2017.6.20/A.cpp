#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100000, maxk = 25;
int n, m, k, cnt;
int a[maxn + 1], b[maxn + 1];
int first[maxk + 1], pre[maxk + 1], succ[maxk + 1];
int Next[maxn + 1];
bool cmp(int *a, int *b, int k) {
    if (a[first[b[k]]] != a[k]) return 0;
    if (pre[b[k]] && a[pre[b[k]]] >= a[k]) return 0;
    if (succ[b[k]] && a[succ[b[k]]] <= a[k]) return 0;
    return 1;
}
int main() {
    while (scanf("%d%d%d", &n, &m, &k) == 3) {
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        for (int i = 1; i <= m; ++i)
            scanf("%d", &b[i]);
        memset(first, 0, sizeof(first));
        for (int i = 1, j; i <= m; ++i) {
            if (!first[b[i]]) first[b[i]] = i;
            for (j = b[i] - 1; j >= 1 && !first[j]; --j);
            pre[b[i]] = first[j];
            for (j = b[i] + 1; j <= k && !first[j]; ++j);
            succ[b[i]] = first[j];
        }
        Next[1] = 0;
        for (int i = 2, j = 0; i <= m; ++i) {
            while (j && !cmp(b + i - j - 1, b, j + 1)) j = Next[j];
            if (cmp(b + i - j - 1, b, j + 1)) ++j;
            Next[i] = j;
        }
        cnt = 0;
        for (int i = 1, j = 0; i <= n; ++i) {
            while (j && !cmp(a + i - j - 1, b, j + 1)) j = Next[j];
            if (cmp(a + i - j - 1, b, j + 1)) ++j;
            if (j == m) {
                ++cnt;
                j = 0;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
