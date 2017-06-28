#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100000;
int n;
int a[maxn + 1];
int k1, k2;
int t1[maxn + 1], t2[maxn + 1];
bool judge1() {
    t1[k1 = 0] = t2[k2 = 0] = 0;
    for (int i = 1; i <= n; ++i)
        if (t1[k1] < a[i]) {
            if (t2[k2] < a[i] && t1[k1] < t2[k2]) t2[++k2] = a[i];
            else t1[++k1] = a[i];
        } else {
            if (t2[k2] < a[i]) t2[++k2] = a[i];
            else return 0;
        }
    if (!k1) t1[++k1] = t2[k2--];
    if (!k2) t2[++k2] = t1[k1--];
    printf("%d %d\n", k1, k2);
    for (int i = 1; i <= k1; ++i)
        printf("%d ", t1[i]);
    printf("\n");
    for (int i = 1; i <= k2; ++i)
        printf("%d ", t2[i]);
    printf("\n");
    return 1;
}
bool judge2() {
    t1[k1 = 0] = t2[k2 = 0] = n + 1;
    for (int i = 1; i <= n; ++i)
        if (t1[k1] > a[i]) {
            if (t2[k2] > a[i] && t1[k1] > t2[k2]) t2[++k2] = a[i];
            else t1[++k1] = a[i];
        } else {
            if (t2[k2] > a[i]) t2[++k2] = a[i];
            else return 0;
        }
    if (!k1) t1[++k1] = t2[k2--];
    if (!k2) t2[++k2] = t1[k1--];
    printf("%d %d\n", k1, k2);
    for (int i = 1; i <= k1; ++i)
        printf("%d ", t1[i]);
    printf("\n");
    for (int i = 1; i <= k2; ++i)
        printf("%d ", t2[i]);
    printf("\n");
    return 1;
}
int f[maxn + 1][2], t[maxn + 1][2];
bool judge3() {
    memset(t, -1, sizeof(t));
    f[1][0] = t[1][0] = t[1][1] = 0;
    f[1][1] = n + 1;
    for (int i = 2; i <= n; ++i) {
        if (~t[i - 1][0]) {
            if (a[i - 1] > a[i]) {
                f[i][0] = f[i - 1][0];
                t[i][0] = 0;
            }
            if (f[i - 1][0] < a[i]) {
                f[i][1] = a[i - 1];
                t[i][1] = 0;
            }
        }
        if (~t[i - 1][1]) {
            if (f[i - 1][1] > a[i] && (!~t[i][0] || f[i][0] > a[i - 1])) {
                f[i][0] = a[i - 1];
                t[i][0] = 1;
            }
            if (a[i - 1] < a[i] && (!~t[i][1] || f[i][1] < f[i - 1][1])) {
                f[i][1] = f[i - 1][1];
                t[i][1] = 1;
            }
        }
        if (!~t[i][0] && !~t[i][1]) return 0;
    }
    k1 = k2 = 0;
    int j = 0;
    if (~t[n][1]) j = 1;
    for (int i = n; i; j = t[i][j], --i)
        if (j) t2[++k2] = a[i];
        else t1[++k1] = a[i];
    if (!k1) t1[++k1] = t2[k2--];
    if (!k2) t2[++k2] = t1[k1--];
    printf("%d %d\n", k1, k2);
    for (int i = k1; i; --i)
        printf("%d ", t1[i]);
    printf("\n");
    for (int i = k2; i; --i)
        printf("%d ", t2[i]);
    printf("\n");
    return 1;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    if (judge1()) return 0;
    if (judge2()) return 0;
    if (judge3()) return 0;
    puts("Fail");
    return 0;
}
