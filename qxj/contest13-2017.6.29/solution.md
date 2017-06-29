# Contest13

[Div. 1](http://codeforces.com/contest/375)

[Div. 2](http://codeforces.com/contest/376)

# Before

## Div2. A

### Problem Description
> 给你一个杠杆（用一个字符串 s 表示，3 ≤ |s| ≤ 10<sup>6</sup>），包括支点位置，每个重物的位置和重量，求这个杠杆的状态（左倾，右倾或平衡）。

### Solution
> 设 k 为支点位置，Lsum = ∑(k - i) * wi (i < k)，Lsum = ∑(i - k) * wi (i > k)，当 Lsum > Rsum 左倾，当 Lsum < Rsum 右倾，当 Lsum = Rsum 时平衡。

```cpp
#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;
const int maxn = 1000000;
typedef long long LL;
int n;
char s[maxn + 10];
LL l = 0, r = 0;
int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int j;
    for (j = 1; j <= n; ++j)
        if (s[j] == '^') break;
    for (int i = 1; i < j; ++i)
        if (isdigit(s[i])) l += (s[i] - 48) * (j - i);
    for (int i = j + 1; i <= n; ++i)
        if (isdigit(s[i])) r += (s[i] - 48) * (i - j);
    if (l > r) puts("left");
    else if (l < r) puts("right");
    else puts("balance");
    return 0;
}
```

## Div2. B

### Problem Description
> 

### Solution
> 

```cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 100;
int n, m;
int M[maxn + 1], sum = 0;
int main() {
    scanf("%d%d", &n, &m);
    for (int a, b, c; m--; ) {
        scanf("%d%d%d", &a, &b, &c);
        M[a] -= c;
        M[b] += c;
    }
    for (int i = 1; i <= n; ++i)
        sum += abs(M[i]);
    sum >>= 1;
    printf("%d\n", sum);
    return 0;
}
```

## Div2. C & Div1. A

### Problem Description
> 

### Solution
> 

```cpp
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000000;
int n;
char s[maxn + 10];
int k = 0, mod = 0, cnt = 0;
char t[maxn + 10];
bool flag1 = 1, flag6 = 1, flag8 = 1, flag9 = 1;
int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; ++i)
        if (flag1 && s[i] == '1') flag1 = 0;
        else if (flag6 && s[i] == '6') flag6 = 0;
        else if (flag8 && s[i] == '8') flag8 = 0;
        else if (flag9 && s[i] == '9') flag9 = 0;
        else {
            if (s[i] == '0') {
                ++cnt;
                continue;
            }
            t[++k] = s[i];
            mod = (mod * 10 + s[i] - 48) % 7;
        }
    mod = mod * 10000 % 7;
    for (int i = 1; i <= k; ++i)
        putchar(t[i]);
    if (!mod) printf("1869");
    else if (mod == 1) printf("1896");
    else if (mod == 2) printf("1986");
    else if (mod == 3) printf("1698");
    else if (mod == 4) printf("6198");
    else if (mod == 5) printf("1689");
    else if (mod == 6) printf("1968");
    while (cnt--) putchar('0');
    return 0;
}
```

## Div2. D & Div1. B

### Problem Description
> 

### Solution
> 

```cpp
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
```

----------------------------------- 我是一条神奇的分割线 -----------------------------------

## Div2. E & Div1. C

### Problem Description
> 

### Solution
> 

```cpp
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
```

## Div1. D

### Problem Description
> 

### Solution
> 1. 莫队算法O(n<sup>1.5</sup>)。
> 2. 

```cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 100000, maxm = 100000;
int n, m;
int c[maxn + 1];
int tot = -1, head[maxn + 1];
struct node1 {
    int p, next;
} edge[maxn << 1];
inline void Add(int u, int v) {
    edge[++tot] = (node1) {v, head[u]};
    head[u] = tot;
    return;
}
struct node2 {
    int l, r, L, k, index;
    bool operator < (const node2 &Other) const {
        return (L != Other.L) ? (L < Other.L) : (r < Other.r);
    }
} Q[maxm + 1];
int Ans[maxn + 1];
int Loc[maxn + 1], Cnt[maxn + 1], col[maxn + 1];
void DFS(int u, int fa) {
    col[Loc[u]] = c[u];
    Cnt[u] = 1;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].p;
        if (v == fa) continue;
        Loc[v] = Loc[u] + Cnt[u];
        DFS(v, u);
        Cnt[u] += Cnt[v];
    }
    return;
}
int ct[maxn + 1], cnt[maxn + 1];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &c[i]);
    memset(head, -1, sizeof(head));
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        Add(u, v);
        Add(v, u);
    }
    Loc[1] = 1;
    DFS(1, 0);
    for (int i = 1, p = sqrt(n), v; i <= m; ++i) {
        scanf("%d%d", &v, &Q[i].k);
        Q[i].l = Loc[v];
        Q[i].r = Loc[v] + Cnt[v] - 1;
        Q[i].L = Q[i].l / p;
        Q[i].index = i;
    }
    sort(Q + 1, Q + m + 1);
    for (int i = 1, l = 1, r = 0; i <= m; ++i) {
        while (l > Q[i].l) ++cnt[++ct[col[--l]]];
        while (r < Q[i].r) ++cnt[++ct[col[++r]]];
        while (l < Q[i].l) --cnt[ct[col[l++]]--];
        while (r > Q[i].r) --cnt[ct[col[r--]]--];
        Ans[Q[i].index] = cnt[Q[i].k];
    }
    for (int i = 1; i <= m; ++i)
        printf("%d\n", Ans[i]);
    return 0;
}
```

## Div1. E

### Problem Description
> 

### Solution
> 

```cpp

```
