#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
int m, b;
LL Max = 0;
int main() {
    scanf("%d%d", &m, &b);
    for (int x = 0, y = b; y >= 0; x += m, --y)
        Max = max(Max, LL(x + 1) * (y + 1) * (x + y) / 2);
    printf("%lld\n", Max);
    return 0;
}
