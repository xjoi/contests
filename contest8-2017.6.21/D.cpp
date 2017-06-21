#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxk = 50, maxn = 100;
int k, x, n, m;
inline int calc(int x, int y) {
    if (!x && y == 2) return 1;
    return 0;
}
struct node {
    LL c1[2], c2[2][2];
    bool h, t;
    node operator + (const node &Other) const {
        node N = {};
        N.h = h;
        N.t = Other.t;
        for (int i = 0; i < 2; ++i)
            N.c1[i] = c1[i] + Other.c1[i];
        for (int i = 0 ; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                N.c2[i][j] = c2[i][j] + Other.c2[i][j];
        ++N.c2[t][Other.h];
        return N;
    }
} f[maxk + 1] = {};
int dp[3][3][maxn + 1][maxn + 1];
int s1[3][3][maxn + 1][maxn + 1], s2[3][3][maxn + 1][maxn + 1];
int main() {
    scanf("%d%d%d%d", &k, &x, &n, &m);
    f[1].c1[0] = 1;
    f[2].c1[1] = 1;
    f[2].h = f[2].t = 1;
    for (int i = 3; i <= k; ++i)
        f[i] = f[i - 2] + f[i - 1];
    if (n > 1) {
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < 3; ++i)
            dp[i][i][1][0] = 0;
        for (int h = 0; h < 3; ++h) {
            for (int i = 2; i <= n; ++i)
                for (int j1 = 0; j1 < 3; ++j1)
                    for (int k = 0; k < i - 1; ++k)
                        if (~dp[h][j1][i - 1][k]) {
                            for (int j2 = 0; j2 < 3; ++j2)
                                dp[h][j2][i][k + calc(j1, j2)] = j1;
                        }
            for (int t = 0; t < 3; ++t)
                for (int k = 0; k < n; ++k)
                    if (~dp[h][t][n][k] && !s1[h][t][k][0]) {
                        s1[h][t][k][0] = 1;
                        for (int dep = n, c = t, j = k; dep; --dep) {
                            s1[h][t][k][dep] = c;
                            int d = dp[h][c][dep][j];
                            j -= calc(d, c);
                            c = d;
                        }
                    }
        }
    } else {
        for (int i = 0; i < 3; ++i) {
            s1[i][i][0][0] = 1;
            s1[i][i][0][1] = i;
        }
    }
    if (m > 1) {
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < 3; ++i)
            dp[i][i][1][0] = 0;
        for (int h = 0; h < 3; ++h) {
            for (int i = 2; i <= m; ++i)
                for (int j1 = 0; j1 < 3; ++j1)
                    for (int k = 0; k < i - 1; ++k)
                        for (int j2 = 0; j2 < 3; ++j2)
                            if (~dp[h][j1][i - 1][k]) dp[h][j2][i][k + calc(j1, j2)] = j1;
            for (int t = 0; t < 3; ++t)
                for (int k = 0; k < m; ++k)
                    if (~dp[h][t][m][k]) {
                        s2[h][t][k][0] = 1;
                        for (int dep = m, c = t, j = k; dep; --dep) {
                            s2[h][t][k][dep] = c;
                            int d = dp[h][c][dep][j];
                            j -= calc(d, c);
                            c = d;
                        }
                    }
        }
    } else {
        for (int i = 0; i < 3; ++i) {
            s2[i][i][0][0] = 1;
            s2[i][i][0][1] = i;
        }
    }
    for (int h1 = 0; h1 < 3; ++h1)
        for (int t1 = 0; t1 < 3; ++t1)
            for (int i = 0; i < n; ++i)
                if (s1[h1][t1][i][0]) {
                    for (int h2 = 0; h2 < 3; ++h2)
                        for (int t2 = 0; t2 < 3; ++t2)
                            for (int j = 0; j < m; ++j)
                                if (s2[h2][t2][j][0]) {
                                    LL cnt = f[k].c1[0] * i + f[k].c1[1] * j;
                                    cnt += f[k].c2[0][0] * calc(t1, h1) + f[k].c2[0][1] * calc(t1, h2) + f[k].c2[1][0] * calc(t2, h1) + f[k].c2[1][1] * calc(t2, h2);
                                    if (cnt == x) {
                                        for (int k = 1; k <= n; ++k)
                                            putchar(s1[h1][t1][i][k] + 65);
                                        putchar('\n');
                                        for (int k = 1; k <= m; ++k)
                                            putchar(s2[h2][t2][j][k] + 65);
                                        putchar('\n');
                                        return 0;
                                    }
                                }
                }
    puts("Happy new year!");
    return 0;
}
