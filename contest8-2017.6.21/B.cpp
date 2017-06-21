#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 300;
int n, sum = 0;
int a[maxn + 1];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    for (int i = 1, d = 1; ; ) {
        if (a[i]) {
            --a[i];
            --sum;
            putchar('P');
        }
        if (!sum) break;
        if (d) {
            ++i;
            putchar('R');
        } else {
            --i;
            putchar('L');
        }
        if (i == n) d = 0;
        if (i == 1) d = 1;
    }
    return 0;
}
