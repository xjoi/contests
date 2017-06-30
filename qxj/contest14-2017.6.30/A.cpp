#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100000;
int n, c, last = 0, cnt = 0;
int main() {
    scanf("%d%d", &n, &c);
    for (int i = 1, t; i <= n; ++i) {
        scanf("%d", &t);
        if (t - last > c) cnt = 0;
        ++cnt;
        last = t;
    }
    printf("%d\n", cnt);
    return 0;
}
