#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdlib>
using namespace std;
const int maxn = 100, maxlen = 100;
int n;
int len[maxn + 1];
char s[maxn + 1][maxlen + 10];
int tot = -1, head[26];
struct node {
    int p, next;
} edge[maxn];
inline void Add(int u, int v) {
    edge[++tot] = (node) {v, head[u]};
    head[u] = tot;
    return;
}
bool vis[26], Map[26][26];
int indegree[26];
int k = 0;
char order[27];
void DFS(int u) {
    vis[u] = 1;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].p;
        if (vis[v]) {
            puts("Impossible");
            exit(0);
        }
        DFS(v);
    }
    return;
}
queue<int> Q;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s[i] + 1);
        len[i] = strlen(s[i] + 1);
    }
    memset(head, -1, sizeof(head));
    for (int i = 1; i < n; ++i)
        for (int k = 1; ; ++k) {
            if (k > len[i]) break;
            if (k > len[i + 1]) {
                puts("Impossible");
                return 0;
            }
            if (s[i][k] != s[i + 1][k]) {
                if (!Map[s[i][k] - 97][s[i + 1][k] - 97]) {
                    Map[s[i][k] - 97][s[i + 1][k] - 97] = 1;
                    Add(s[i][k] - 97, s[i + 1][k] - 97);
                    ++indegree[s[i + 1][k] - 97];
                }
                break;
            }
        }
    for (int i = 0; i < 26; ++i)
        if (!indegree[i]) Q.push(i);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        order[27 - ++k] = u + 97;
        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].p;
            --indegree[v];
            if (!indegree[v]) Q.push(v);
        }
    }
    if (k < 26) puts("Impossible");
    else while (k) putchar(order[k--]);
    return 0;
}
