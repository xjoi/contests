#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 5000;
int n, m;
char s[maxn + 10];
int sum[maxn + 1][maxn + 2];
int Max = 0;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s + 1);
        for (int j = 1, k; j <= m; j = k + 1)
            if (s[j] == '1') {
                for (k = j; k < m && s[k + 1] == '1'; ++k);
                for (int l = j; l <= k; ++l) {
                    ++sum[l][l];
                    --sum[l][k + 1];
                }
            } else k = j;
    }
    for (int i = 1; i <= m; ++i) {
        int s = 0;
        for (int j = i; j <= m; ++j) {
            s += sum[i][j];
            Max = max(Max, s * (j - i + 1));
        }
    }
    printf("%d\n", Max);
    return 0;
}
