#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
int n, k;
LL sum = 0;
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; ++i) {
        int a;
        scanf("%d", &a);
        sum += a;
    }
    printf("%lld\n", max(sum - LL(k - 1) * n, 0ll));
    return 0;
}
