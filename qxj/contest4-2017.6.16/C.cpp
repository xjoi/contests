#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 100000;
int n;
LL k;
int a[maxn + 1];
int main() {
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int index = (k - 1) / n + 1, i = index, j = index;
    while (i > 1 && a[i - 1] == a[i]) --i;
    while (j < n && a[j] == a[j + 1]) ++j;
    int cnt = j - i + 1;
    LL K = k - LL(i - 1) * n;
    index = (K - 1) / cnt + 1;
    printf("%d %d\n", a[i], a[index]);
    return 0;
}
