#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;
inline int Read() {
    char c;
    while (c = getchar(), !isdigit(c));
    return c - 48;
}
const int maxn = 100;
int n;
int a[maxn + 1], b[maxn + 1];
bool cmp(int x, int y) {
    return x > y;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        a[i] = Read();
    for (int i = 1; i <= n; ++i)
        b[i] = Read();
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    bool judge = 1;
    for (int i = 1; i <= n; ++i)
        if (a[i] <= b[i]) {
            judge = 0;
            break;
        }
    if (judge) {
        printf("YES\n");
        return 0;
    }
    sort(a + 1, a + n + 1, cmp);
    sort(b + 1, b + n + 1, cmp);
    judge = 1;
    for (int i = 1; i <= n; ++i)
        if (a[i] >= b[i]) {
            judge = 0;
            break;
        }
    if (judge) {
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}
