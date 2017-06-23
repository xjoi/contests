#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100;
int n, sum = 0;
int a[maxn + 1];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; sum += a[i], ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = n, tot = 0; i; --i) {
        tot += a[i];
        if (tot > sum - tot) {
            printf("%d\n", n - i + 1);
            return 0;
        }
    }
    return 0;
}
