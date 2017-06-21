#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 300000;
int n;
struct node {
    int x, index;
    bool operator < (const node &Other) const {
        return x < Other.x;
    }
} a[maxn + 1];
int b[maxn + 1];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i].x);
        a[i].index = i;
    }
    sort(a + 1, a + n + 1);
    b[a[1].index] = a[1].x;
    for (int i = 2; i <= n; ++i)
        if (b[a[i - 1].index] >= a[i].x) b[a[i].index] = b[a[i - 1].index] + 1;
        else b[a[i].index] = a[i].x;
    for (int i = 1; i <= n; ++i)
        printf("%d ", b[i]);
    return 0;
}
