#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
LL n, m, N;
int main() {
    scanf("%lld%lld%lld", &n, &m, &N);
    LL M = (N + 1) * m / n;
    if (M > N) M = N;
    printf("%lld\n", M);
    return 0;
}
