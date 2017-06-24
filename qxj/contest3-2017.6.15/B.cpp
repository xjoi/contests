#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 20;
int n, cnt = 0;
char s[maxn + 10];
int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '7') cnt += 1 << (n - i);
        cnt += 1 << (n - i);
    }
    printf("%d\n", cnt);
    return 0;
}
