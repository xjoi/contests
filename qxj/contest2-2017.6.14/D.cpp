#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100000, maxm = 5;
struct node {
    int head, tail;
    int index[maxn + 1], key[maxn + 1];
    void clr() {
        head = tail = 0;
        return;
    }
    inline void update(int id) {
        while (head <= tail && index[head] <= id) ++head;
        return;
    }
    inline int top() {
        return key[head];
    }
    void push(int id, int k) {
        while (head <= tail && key[tail] <= k) --tail;
        key[++tail] = k;
        index[tail] = id;
        return;
    }
} dq[maxm + 1];
int n, m, k, Max = 0;
int a[maxn + 1][maxm + 1];
int cnt[maxm + 1];
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);
    for (int i = 1, j = 0; i <= n; ++i, j = max(j, i - 1)) {
        while (j < n) {
            int sum = 0;
            for (int k = 1; k <= m; ++k)
                sum += max(dq[k].top(), a[j + 1][k]);
            if (sum > k) break;
            ++j;
            for (int k = 1; k <= m; ++k)
                dq[k].push(j, a[j][k]);
        }
        if (i <= j && j - i + 1 > Max) {
            Max = j - i + 1;
            for (int k = 1; k <= m; ++k)
                cnt[k] = dq[k].top();
        } 
        for (int k = 1; k <= m; ++k)
            dq[k].update(i);
    }
    for (int i = 1; i <= m; ++i)
        printf("%d ", cnt[i]);
    return 0;
}
