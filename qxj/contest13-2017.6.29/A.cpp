#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;
const int maxn = 1000000;
typedef long long LL;
int n;
char s[maxn + 10];
LL l = 0, r = 0;
int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int j;
    for (j = 1; j <= n; ++j)
        if (s[j] == '^') break;
    for (int i = 1; i < j; ++i)
        if (isdigit(s[i])) l += (s[i] - 48) * (j - i);
    for (int i = j + 1; i <= n; ++i)
        if (isdigit(s[i])) r += (s[i] - 48) * (i - j);
    if (l > r) puts("left");
    else if (l < r) puts("right");
    else puts("balance");
    return 0;
}
