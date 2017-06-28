#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 300;
int n;
int l[maxn + 1], c[maxn + 1];
vector<int> fac;
int f[maxn * maxn];
int Gcd(int x, int y) {
    return (y) ? (Gcd(y, x % y)) : (x);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &l[i]);
        for (int j = 1, p = sqrt(l[i]); j <= p; ++j)
            if (!(l[i] % j)) {
                fac.push_back(j);
                fac.push_back(l[i] / j);
            }
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", &c[i]);
    sort(fac.begin(), fac.end());
    fac.erase(unique(fac.begin(), fac.end()), fac.end());
    int N = fac.size();
    memset(f, -1, sizeof(f));
    for (int i = 1; i <= n; ++i) {
        int k = lower_bound(fac.begin(), fac.end(), l[i]) - fac.begin();
        if (!~f[k] || f[k] > c[i]) f[k] = c[i];
        for (int j = 0; j < N; ++j)
            if (~f[j]) {
            k = lower_bound(fac.begin(), fac.end(), Gcd(fac[j], l[i])) - fac.begin();
            if (!~f[k] || f[k] > f[j] + c[i]) f[k] = f[j] + c[i];
        }
    }
    printf("%d\n", f[0]);
    return 0;
}
