#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
LL x;
int a[30], k = 0;
int main() {
    scanf("%lld", &x);
    do a[++k] = x % 10;
    while (x /= 10);
    for (int i = 1; i < k; ++i)
        a[i] = min(a[i], 9 - a[i]);
    if (a[k] != 9) a[k] = min(a[k], 9 - a[k]);
    while (k) x = x * 10 + a[k--];
    printf("%lld\n", x);
    return 0;
}
