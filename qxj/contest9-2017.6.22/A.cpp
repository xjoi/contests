#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn = 100000;
int n, m, k;
LL a[maxn + 1];
struct node {
    int l, r, d;
} Q[maxn + 1];
int sum1[maxn + 2];
LL sum2[maxn + 2];
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= m; ++i)
        scanf("%d%d%d", &Q[i].l, &Q[i].r, &Q[i].d);
    for (int i = 1; i <= k; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        ++sum1[x];
        --sum1[y + 1];
    }
    for (int i = 1, sum = 0; i <= m; ++i) {
        sum += sum1[i];
        sum2[Q[i].l] += LL(Q[i].d) * sum;
        sum2[Q[i].r + 1] -= LL(Q[i].d) * sum;
    }
    for (LL i = 1, sum = 0; i <= n; ++i)
        printf("%lld ", (sum += sum2[i]) + a[i]);
    return 0;
}
