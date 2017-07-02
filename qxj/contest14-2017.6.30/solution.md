# Contest14

[Div. 2](http://codeforces.com/contest/716)

# Before

## Div2. A

### Problem Description
> ZS在打字，他打了 n (n <= 10<sup>5</sup>)个字符，给你打每个字符的时间，若在打第 i 个字符的时刻 t<sub>i</sub>，若前一个字符的输入时间 t<sub>i-1</sub> < t<sub>i</sub> - c (c 是给定的最大时限，c <= 10<sup>9</sup>)，那么之前的输入的字符都会消失，问你当他打完第 n 个字符后，屏幕上有几个字符。 

### Solution
> 直接模拟，计数器 cnt 表示现在屏幕上有多少个字符，当 t<sub>i-1</sub> < t<sub>i</sub> - c 时，cnt 清零。++cnt。最后 cnt 即为答案。时间复杂度 O(n)。

```cpp
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100000;
int n, c, last = 0, cnt = 0;
int main() {
    scanf("%d%d", &n, &c);
    for (int i = 1, t; i <= n; ++i) {
        scanf("%d", &t);
        if (t - last > c) cnt = 0;
        ++cnt;
        last = t;
    }
    printf("%d\n", cnt);
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
using namespace std;
const int maxn = 50000;
int n, cnt;
char s[maxn + 10];
bool p[26], flag = 0;
int k, t[26];
int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    if (n < 26) {
        puts("-1");
        return 0;
    }
    for (int i = 1; i + 25 <= n; ++i) {
        if (flag) continue;
        memset(p, 0, sizeof(p));
        cnt = 0;
        for (int j = i; j <= i + 25; ++j)
            if (s[j] == '?') ++cnt;
            else p[s[j] - 65] = 1;
        k = 0;
        for (int j = 0; j < 26; ++j)
            if (!p[j]) t[k++] = j;
        if (k > cnt) continue;
        else {
            flag = 1;
            for (int j = i, l = 0; j <= i + 25; ++j)
                if (s[j] == '?') s[j] = t[l++] + 65;
        }
    }
    if (!flag) puts("-1");
    else {
        for (int i = 1; i <= n; ++i)
            if (s[i] == '?') putchar('A');
            else putchar(s[i]);
    }
    return 0;
}
```

## Div2. C

### Problem Description
> 

### Solution
> 

```cpp
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
int n;
int last = 2;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        printf("%lld\n", LL(i + 1) * (i + 1) * i - last);
        last = i;
    }
    return 0;
}
```

----------------------------------- 我是一条神奇的分割线 -----------------------------------

## Div2. D

### Problem Description
> 

### Solution
> 

```cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<LL, int> PI;
const int maxn = 1000, maxm = 10000;
const LL INF = 0x3fffffffffffffff;
int n, m, L, source, sink;
int tot = -1, head[maxn + 1];
struct node {
    int p, next, w;
} edge[maxm << 1];
inline void Add(int u, int v, int w) {
    edge[++tot] = (node) {v, head[u], w};
    head[u] = tot;
    return;
}
bool done[maxn + 1];
LL D_sink[maxn + 1], D_source[maxn + 1];
void Dijkstra(int source, LL *d) {
    fill(d, d + n, INF);
    memset(done, 0, sizeof(done));
    set<PI> S;
    d[source] = 0;
    S.insert(make_pair(0, source));
    while (!S.empty()) {
        PI cur = *S.begin();
        S.erase(S.begin());
        int u = cur.second;
        done[u] = 1;
        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].p, w = edge[i].w;
            if (done[v] || !w) continue;
            if (d[v] > d[u] + w) {
                S.erase(make_pair(d[v], v));
                S.insert(make_pair(d[v] = d[u] + w, v));
            }
        }
    }
    return;
}
void Modified_Dijkstra(int source, LL *d, LL *fromsink) {
    fill(d, d + n, INF);
    memset(done, 0, sizeof(done));
    set<PI> S;
    d[source] = 0;
    S.insert(make_pair(0, source));
    while (!S.empty()) {
        PI cur = *S.begin();
        S.erase(S.begin());
        int u = cur.second;
        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].p, w = edge[i].w;
            if (done[v]) continue;
            if (!w) {
                if (d[u] + fromsink[v] >= L) w = 1;
                else w = LL(L) - d[u] - fromsink[v];
                edge[i].w = edge[i ^ 1].w = w;
            }
            if (d[v] > d[u] + w) {
                S.erase(make_pair(d[v], v));
                S.insert(make_pair(d[v] = d[u] + w, v));
            }
        }
    }
    return;
}
int main() {
    scanf("%d%d%d%d%d", &n, &m, &L, &source, &sink);
    memset(head, -1, sizeof(head));
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        Add(u, v, w);
        Add(v, u, w);
    }
    Dijkstra(sink, D_sink);
    if (D_sink[source] < L) {
        puts("NO");
        return 0;
    }
    Modified_Dijkstra(source, D_source, D_sink);
    if (D_source[sink] != L) puts("NO");
    else {
        puts("YES");
        for (int i = 0; i <= tot; i += 2)
            if (edge[i].w) printf("%d %d %d\n", edge[i ^ 1].p, edge[i].p, edge[i].w);
            else printf("%d %d %d\n", edge[i ^ 1].p, edge[i].p, L);
    }
    return 0;
}
```

## Div2. E

### Problem Description
> 

### Solution
> 

```cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
typedef pair<LL, int> PI;
LL Gcd(LL a, LL b) {
    return (b) ? (Gcd(b, a % b)) : (a);
}
LL Ex_gcd(LL a, LL b, LL &x, LL &y) {
    if (b) {
        LL temp = Ex_gcd(b, a % b, x, y), X = x;
        x = y;
        y = X - a / b * y;
        return temp;
    }
    x = 1;
    y = 0;
    return a;
}
const int maxn = 100000;
int n;
LL m, ans = 0;
LL p[maxn];
int tot = -1, head[maxn];
struct node {
    int p, next, w;
} edge[maxn << 1];
inline void Add(int u, int v, int w) {
    edge[++tot] = (node) {v, head[u], w};
    head[u] = tot;
    return;
}
bool vis[maxn];
int root, cnt;
int Max[maxn], size[maxn];
void Gr(int u) {
    size[u] = 1;
    Max[u] = 0;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].p;
        if (vis[v]) continue;
        vis[v] = 1;
        Gr(v);
        vis[v] = 0;
        size[u] += size[v];
        if (size[v] > Max[u]) Max[u] = size[v];
    }
    if (cnt - size[u] > Max[u]) Max[u] = cnt - size[u];
    if (!~root || Max[u] < Max[root]) root = u;
    return;
}
vector<PI> V;
map<LL, int> Map;
void DFS1(int u, int dep, LL d1, LL d2) {
    if (!d1) ++ans;
    if (!d2) ++ans;
    ++Map[d1];
    V.push_back(make_pair(d2, dep));
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].p, w = edge[i].w;
        if (vis[v]) continue;
        vis[v] = 1;
        DFS1(v, dep + 1, (p[dep] * w + d1) % m, (d2 * 10 + w) % m);
        vis[v] = 0;
    }
    return;
}
LL Calc1(int u) {
    LL cnt = 0;
    V.clear();
    Map.clear();
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].p, w = edge[i].w;
        if (vis[v]) continue;
        vis[v] = 1;
        DFS1(v, 1, w, w);
        vis[v] = 0;
    }
    for (int i = 0, n = V.size(); i < n; ++i) {
        PI cur = V[i];
        LL g = Gcd(m, p[cur.second]);
        if (cur.first % g) continue;
        LL x, y;
        Ex_gcd(m / g, p[cur.second] / g, x, y);
        LL P = (-y % m + m) % m * g % m * cur.first % m;
        cnt += Map[P];
    }
    return cnt;
}
void DFS2(int u, int dep, LL d1, LL d2) {
    ++Map[d1];
    V.push_back(make_pair(d2, dep));
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].p, w = edge[i].w;
        if (vis[v]) continue;
        vis[v] = 1;
        DFS2(v, dep + 1, (p[dep] * w + d1) % m, (d2 * 10 + w) % m);
        vis[v] = 0;
    }
    return;
}
LL Calc2(int u, int w) {
    LL cnt = 0;
    V.clear();
    Map.clear();
    vis[u] = 1;
    DFS2(u, 1, w, w);
    vis[u] = 0;
    for (int i = 0, n = V.size(); i < n; ++i) {
        PI cur = V[i];
        LL g = Gcd(m, p[cur.second]);
        if (cur.first % g) continue;
        LL x, y;
        Ex_gcd(m / g, p[cur.second] / g, x, y);
        LL P = (-y % m + m) % m * g % m * cur.first % m;
        cnt += Map[P];
    }
    return cnt;
}
void Divide(int u) {
    root = -1;
    vis[u] = 1;
    Gr(u);
    vis[u] = 0;
    vis[root] = 1;
    ans += Calc1(root);
    for (int i = head[root]; ~i; i = edge[i].next) {
        int v = edge[i].p, w = edge[i].w;
        if (vis[v]) continue;
        ans -= Calc2(v, w);
    }
    for (int i = head[root]; ~i; i = edge[i].next) {
        int v = edge[i].p;
        if (vis[v]) continue;
        cnt = size[v];
        Divide(v);
    }
    return;
}
int main() {
    scanf("%d%lld", &n, &m);
    p[0] = 1;
    for (int i = 1; i < n; ++i)
        p[i] = p[i - 1] * 10 % m;
    memset(head, -1, sizeof(head));
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        w %= m;
        Add(u, v, w);
        Add(v, u, w);
    }
    cnt = n;
    Divide(0);
    printf("%lld\n", ans);
    return 0;
}
```
