#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
        putchar('#');
    putchar('\n');
    for (int i = 2; i <= n; i += 2) {
        if (!(i / 2 % 2)) putchar('#');
        for (int j = 1; j < m; ++j)
            putchar('.');
        if (i / 2 % 2) putchar('#');
        putchar('\n');
        for (int j = 1; j <= m; ++j)
            putchar('#');
        putchar('\n');
    }
    return 0;
}
