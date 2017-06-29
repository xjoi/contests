#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000000;
int n;
char s[maxn + 10];
int k = 0, mod = 0, cnt = 0;
char t[maxn + 10];
bool flag1 = 1, flag6 = 1, flag8 = 1, flag9 = 1;
int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; ++i)
        if (flag1 && s[i] == '1') flag1 = 0;
        else if (flag6 && s[i] == '6') flag6 = 0;
        else if (flag8 && s[i] == '8') flag8 = 0;
        else if (flag9 && s[i] == '9') flag9 = 0;
        else {
            if (s[i] == '0') {
                ++cnt;
                continue;
            }
            t[++k] = s[i];
            mod = (mod * 10 + s[i] - 48) % 7;
        }
    mod = mod * 10000 % 7;
    for (int i = 1; i <= k; ++i)
        putchar(t[i]);
    if (!mod) printf("1869");
    else if (mod == 1) printf("1896");
    else if (mod == 2) printf("1986");
    else if (mod == 3) printf("1698");
    else if (mod == 4) printf("6198");
    else if (mod == 5) printf("1689");
    else if (mod == 6) printf("1968");
    while (cnt--) putchar('0');
    return 0;
}
