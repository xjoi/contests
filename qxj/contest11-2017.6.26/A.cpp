#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 50, maxa = 100000;
int n;
int a[maxn + 1][maxn + 1];
bool f[maxn + 1][maxa + 1];
bool flag = 1;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &a[i][j]);
            f[j][a[i][j]] = 1;
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (a[i][j] > 1) {
                bool flag1 = 1;
                for (int k = 1; k <= n; ++k)
                    if (a[i][k] < a[i][j] && f[j][a[i][j] - a[i][k]]) {
                        flag1 = 0;
                        break;
                    }
                if (flag1) {
                    flag = 0;
                    break;
                }
            }
    if (flag) puts("Yes");
    else puts("No");
    return 0;
}
