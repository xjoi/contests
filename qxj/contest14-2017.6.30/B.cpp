#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 50000;
int n, cnt;
char s[maxn + 10];
bool p[26], flag = 0;
int k, t[26];
int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    if (n < 26) {
        puts("-1");
        return 0;
    }
    for (int i = 1; i + 25 <= n; ++i) {
        if (flag) continue;
        memset(p, 0, sizeof(p));
        cnt = 0;
        for (int j = i; j <= i + 25; ++j)
            if (s[j] == '?') ++cnt;
            else p[s[j] - 65] = 1;
        k = 0;
        for (int j = 0; j < 26; ++j)
            if (!p[j]) t[k++] = j;
        if (k > cnt) continue;
        else {
            flag = 1;
            for (int j = i, l = 0; j <= i + 25; ++j)
                if (s[j] == '?') s[j] = t[l++] + 65;
        }
    }
    if (!flag) puts("-1");
    else {
        for (int i = 1; i <= n; ++i)
            if (s[i] == '?') putchar('A');
            else putchar(s[i]);
    }
    return 0;
}
