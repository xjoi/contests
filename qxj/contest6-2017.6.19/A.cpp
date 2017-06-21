#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxk = 26, maxn = 100;
int n, k, cnt = 0;
bool p[26];
char s[maxn + 10];
int b[maxk + 2];
int main() {
    scanf("%d%s", &k, s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; ++i)
        if (!p[s[i] - 97]) {
            p[s[i] - 97] = 1;
            b[++cnt] = i;
        }
    if (cnt < k) printf("NO\n");
    else {
        printf("YES\n");
        b[k + 1] = n + 1;
        for (int i = 1; i <= k; putchar('\n'), ++i)
            for (int j = b[i]; j < b[i + 1]; ++j)
                putchar(s[j]);
    }
    return 0;
}
