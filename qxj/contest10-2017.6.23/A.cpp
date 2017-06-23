#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int maxn = 200000;
int n, cnt = 0;
char s[maxn + 10];
int main() {
    scanf("%d%s", &n, s + 1);
    for (int i = 1; i <= n; ++i)
        if (s[i] == '0') ++cnt;
        else --cnt;
    printf("%d\n", abs(cnt));
    return 0;
}
