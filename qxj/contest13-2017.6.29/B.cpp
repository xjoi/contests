#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 100;
int n, m;
int M[maxn + 1], sum = 0;
int main() {
    scanf("%d%d", &n, &m);
    for (int a, b, c; m--; ) {
        scanf("%d%d%d", &a, &b, &c);
        M[a] -= c;
        M[b] += c;
    }
    for (int i = 1; i <= n; ++i)
        sum += abs(M[i]);
    sum >>= 1;
    printf("%d\n", sum);
    return 0;
}
