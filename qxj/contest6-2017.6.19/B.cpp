#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100;
int n, cnt = 0, k;
bool f[maxn + 1][maxn + 1];
int dx[4] = {1, -1,  0, 0};
int dy[4] = {0,  0, -1, 1};
bool judge(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx > n || ny < 0 || ny > n) continue;
        if (f[nx][ny]) return 0;
    }
    return 1;
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; cnt < k && i <= n; ++i)
        for (int j = 1; cnt < k && j <= n; ++j)
            if (judge(i, j)) {
                ++cnt;
                f[i][j] = 1;
            }
    if (cnt < k) printf("NO\n");
    else {
        printf("YES\n");
        for (int i = 1; i <= n; putchar('\n'), ++i)
            for (int j = 1; j <= n; ++j)
                if (f[i][j]) putchar('L');
                else putchar('S');
    }
    return 0;
}
