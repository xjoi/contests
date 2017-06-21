#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;
inline int Read() {
    char c;
    while (c = getchar(), !isdigit(c));
    int x = c - 48;
    while (c = getchar(), isdigit(c)) x = x * 10 + c - 48;
    return x;
}
inline void Writeln(int x) {
    int a[20], k = 0;
    do a[++k] = x % 10;
    while (x /= 10);
    while (k) putchar(a[k--] + 48);
    putchar('\n');
    return;
}
const int maxn = 1000004, maxp = 19;
int Q, n = 4;
int d[maxn + 1], Maxdp, Maxl;
int f[maxn + 1][maxp + 1];
int LCA(int u, int v) {
    int sum = 0;
    if (d[u] < d[v]) swap(u, v);
    for (int i = d[u] - d[v], j = 0; i; i >>= 1, ++j)
        if (i & 1) {
            sum += 1 << j;
            u = f[u][j];
        }
    if (u == v) return sum;
    for (int i = log2(d[u]); i >= 0; --i)
        if (f[u][i] != f[v][i]) {
            sum += 1 << i << 1;
            u = f[u][i];
            v = f[v][i];
        }
    return sum + 2;
}
int main() {
    scanf("%d", &Q);
    d[2] = d[3] = d[4] = 1;
    f[Maxl = Maxdp = 2][0] = f[3][0] = f[4][0] = 1;
    while (Q--) {
        int v = Read();
        f[n + 1][0] = f[n + 2][0] = v;
        d[n + 1] = d[n + 2] = d[v] + 1;
        int p = log2(d[n + 1]);
        for (int i = 1; i <= p; ++i)
            f[n + 1][i] = f[f[n + 1][i - 1]][i - 1];
        for (int i = 1; i <= p; ++i)
            f[n + 2][i] = f[f[n + 2][i - 1]][i - 1];
        if (d[v] == d[Maxdp]) {
            ++Maxl;
            Maxdp = n + 1;
        } else {
            int k = LCA(Maxdp, n + 1);
            if (k > Maxl) Maxl = k;
        }
        n += 2;
        Writeln(Maxl);
    }
    return 0;
}
