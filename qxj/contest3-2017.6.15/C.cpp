#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
int a, b, n;
int main() {
    scanf("%d%d%d", &a, &b, &n);
    while (n--) {
        int l, t, m, r;
        scanf("%d%d%d", &l, &t, &m);
        r = (t - a) / b + 1;
        LL x = 1 - l, y = b, z = 2 * a - 2 * b + LL(l) * b;
        LL A = y, B = x * y + z, C = x * z - 2ll * t * m;
        double delta = double(B) * B - 4 * A * C;
        if (delta < 0) {
            printf("-1\n");
            continue;
        }
        int L = l;
        while (l <= r) {
            int mid = (l + r) >> 1;
            LL sum = A * mid * mid + B * mid + C;
            if (sum <= 0) l = mid + 1;
            else r = mid - 1;
        }
        if (L <= r) printf("%d\n", r);
        else printf("-1\n");
    }
    return 0;
}
