#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <queue>
using namespace std;
const int maxn = 20, maxm = 20;
int n, m;
char map[maxn + 1][maxm + 10];
int sx, sy;
int k = -1;
int ox[10], oy[10], v[10];
int id[10], maxd = 0;
int d[maxn + 1][maxm + 1][1 << 8];
struct node {
    int x, y, s;
};
queue<node> Q;
int Max = 0;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", map[i] + 1);
        for (int j = 1; j <= m; ++j)
            if (map[i][j] == 'S') {
                sx = i;
                sy = j;
            } else {
                if (map[i][j] == 'B') {
                    ox[++k] = i;
                    oy[k] = j;
                    v[k] = -10000;
                } else if (isdigit(map[i][j])) {
                    ox[++k] = i;
                    oy[k] = j;
                    id[map[i][j] - 48] = k;
                    maxd = max(maxd, map[i][j] - 48);
                }
            }
    }
    for (int i = 1; i <= maxd; ++i)
        scanf("%d", &v[id[i]]);
    memset(d, 0x7f, sizeof(d));
    d[sx][sy][0] = 0;
    Q.push((node) {sx, sy, 0});
    while (!Q.empty()) {
        node u = Q.front();
        Q.pop();
        int x = u.x, y = u.y, s = u.s;
        //cerr << x << ' ' << y << ' ' << s << ' ' << d[x][y][s] << endl;
        if (x > 1) {
            if (map[x - 1][y] == 'S') {
                int sum = -d[x][y][s] - 1;
                for (int i = 0; i <= k; ++i)
                    if (s & (1 << i)) sum += v[i];
                Max = max(Max, sum);
            }
            else {
                if (map[x - 1][y] == '.') {
                    if (d[x][y][s] + 1 < d[x - 1][y][s]) {
                        d[x - 1][y][s] = d[x][y][s] + 1;
                        Q.push((node) {x - 1, y, s});
                    }
                }
            }
        }
        if (x < n) {
            if (map[x + 1][y] == 'S') {
                int sum = -d[x][y][s] - 1;
                for (int i = 0; i <= k; ++i)
                    if (s & (1 << i)) sum += v[i];
                Max = max(Max, sum);
            } else {
                if (map[x + 1][y] == '.') {
                    if (d[x][y][s] + 1 < d[x + 1][y][s]) {
                        d[x + 1][y][s] = d[x][y][s] + 1;
                        Q.push((node) {x + 1, y, s});
                    }
                }
            }
        }
        if (y > 1) {
            int ns = s;
            for (int i = 0; i <= k; ++i)
                if (ox[i] < x && oy[i] == y) ns ^= 1 << i;
            if (map[x][y - 1] == 'S') {
                int sum = -d[x][y][s] - 1;
                for (int i = 0; i <= k; ++i)
                    if (ns & (1 << i)) sum += v[i];
                Max = max(Max, sum);
            } else {
                if (map[x][y - 1] == '.') {
                    if (d[x][y][s] + 1 < d[x][y - 1][ns]) {
                        d[x][y - 1][ns] = d[x][y][s] + 1;
                        Q.push((node) {x, y - 1, ns});
                    }
                }
            }
        }
        if (y < m) {
            int ns = s;
            for (int i = 0; i <= k; ++i)
                if (ox[i] < x && oy[i] == y + 1) ns ^= 1 << i;
            if (map[x][y + 1] == 'S') {
                int sum = -d[x][y][s] - 1;
                for (int i = 0; i <= k; ++i)
                    if (ns & (1 << i)) sum += v[i];
                Max = max(Max, sum);
            } else {
                if (map[x][y + 1] == '.') {
                    if (d[x][y][s] + 1 < d[x][y + 1][ns]) {
                        d[x][y + 1][ns] = d[x][y][s] + 1;
                        Q.push((node) {x, y + 1, ns});
                    }
                }
            }
        }
    }
    printf("%d\n", Max);
    return 0;
}
