#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 300000;
int n, cnt = 0, Next = 0;
int stk[maxn + 1], k = 0;
int main() {
    scanf("%d", &n);
    n <<= 1;
    while (n--) {
        char c[10];
        scanf("%s", c);
        if (c[0] == 'a') {
            int x;
            scanf("%d", &x);
            stk[++k] = x;
        } else {
            ++Next;
            if (k) {
                if (stk[k] != Next) {
                    ++cnt;
                    k = 0;
                } else --k;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
