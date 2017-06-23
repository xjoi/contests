#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, k, cnt = 0;
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1, m; i <= k; ++i) {
        scanf("%d", &m);
        int x;
        scanf("%d", &x);
        if (x != 1) {
            for (int i = 2; i <= m; ++i)
                scanf("%d", &x);
            cnt += (m << 1) - 1;
            continue;
        }
        for (int i = 2; i <= m; ++i) {
            scanf("%d", &x);
            if (x != i) {
                for (int j = i + 1; j <= m; ++j)
                    scanf("%d", &x);
                cnt += (m - i + 1) << 1;
                break;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
