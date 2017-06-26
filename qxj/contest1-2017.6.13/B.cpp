#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 50, maxm = 50;
int n, m;
char c[maxn + 1][maxm + 2];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int d[maxn + 1][maxm + 1];
bool flag = 0;
void DFS(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if (c[x][y] != c[nx][ny]) continue;
        if (!d[nx][ny]) {
            d[nx][ny] = d[x][y] + 1;
            DFS(nx, ny);
        } else {
            if (d[x][y] - d[nx][ny] >= 3) flag = 1;
        }
    }
    return;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%s", c[i] + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (!d[i][j]) {
                d[i][j] = 1;
                DFS(i, j);
            }
    if (flag) puts("Yes");
    else puts("No");
    return 0;
}
