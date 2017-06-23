#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000;
int n, a, cnt;
int main() {
    scanf("%d%d", &n, &a);
    cnt = (-a + n) % n;
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &a);
        if ((i % 2 && cnt != (i - 1 - a + n) % n) || (!(i % 2) && cnt != (a - i + 1 + n) % n)) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}
