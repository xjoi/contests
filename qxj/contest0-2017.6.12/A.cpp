#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100;
int n, m;
int a[maxn + 2];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int x, y; m--; ) {
        scanf("%d%d", &x, &y);
        a[x - 1] += y - 1;
        a[x + 1] += a[x] - y;
        a[x] = 0;
    }
    for (int i = 1; i <= n; ++i)
        printf("%d\n", a[i]);
    return 0;
}
