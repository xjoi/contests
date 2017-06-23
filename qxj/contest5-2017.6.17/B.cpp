#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int maxn = 100000, INF = 0x7fffffff;
int n, ans = INF;
int cnt[5];
char s[maxn + 10];
int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    if (n % 2) {
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i <= n; ++i)
        if (s[i] == 'L') ++cnt[1];
        else if (s[i] == 'R') ++cnt[2];
        else if (s[i] == 'U') ++cnt[3];
        else ++cnt[4];
    for (int i = 0; i <= n; i += 2)
        ans = min(ans, (abs(i / 2 - cnt[1]) + abs(i / 2 - cnt[2]) + abs((n - i) / 2 - cnt[3]) + abs((n - i) / 2 - cnt[4])) / 2);
    printf("%d\n", ans);
    return 0;
}
