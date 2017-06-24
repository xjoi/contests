#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 1000;
int n, X, Y;
int Gcd(int x, int y) {
    return (y) ? (Gcd(y, x % y)) : (x);
}
struct node {
    int x, y;
    void reset() {
        if (y < 0) {
            x = -x;
            y = -y;
        }
        int g = Gcd(abs(x), y);
        x /= g;
        y /= g;
        if (!y) x = abs(x);
        return;
    }
    bool operator < (const node &Other) const {
        return (x != Other.x) ? (x < Other.x) : (y < Other.y);
    }
    bool operator == (const node &Other) const {
        return x == Other.x && y == Other.y;
    }
} k[maxn + 1];
int main() {
    scanf("%d%d%d", &n, &X, &Y);
    for (int i = 1; i <= n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        k[i].x = x - X;
        k[i].y = y - Y;
        k[i].reset();
    }
    sort(k + 1, k + n + 1);
    printf("%d\n", unique(k + 1, k + n + 1) - k - 1);
    return 0;
}
