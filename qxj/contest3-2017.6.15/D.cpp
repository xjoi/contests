#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn = 1000000;
const LL mod = 1E9 + 7;
LL Pow(LL a, LL b) {
    LL c = 1;
    while (b) {
        if (b & 1) c = c * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return c;
}
int n, m, len;
char t[maxn + 10];
int Next[maxn + 1];
bool P[maxn + 1];
int p[maxn + 1];
int cnt;
int main() {
    scanf("%d%d%s", &n, &m, t + 1);
    len = strlen(t + 1);
    Next[1] = 0;
    for (int i = 2, j = 0; i <= len; ++i) {
        while (j && t[i] != t[j + 1]) j = Next[j];
        if (t[i] == t[j + 1]) ++j;
        Next[i] = j;
    }
    for (int i = Next[len]; i; i = Next[i])
        P[i] = 1;
    for (int i = 1; i <= m; ++i)
        scanf("%d", &p[i]);
    if (!m) cnt = n;
    else cnt = p[1] - 1 + n - p[m] - len + 1;
    for (int i = 2; i <= m; ++i)
        if (p[i - 1] + len <= p[i]) cnt += p[i] - p[i - 1] - len;
        else {
            if (!P[p[i - 1] + len - p[i]]) {
                printf("0\n");
                return 0;
            }
        }
    printf("%lld\n", Pow(26, cnt));
    return 0;
}
