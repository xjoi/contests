#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
int n;
int last = 2;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        printf("%lld\n", LL(i + 1) * (i + 1) * i - last);
        last = i;
    }
    return 0;
}
