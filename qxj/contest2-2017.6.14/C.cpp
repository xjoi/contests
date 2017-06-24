#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 300000, maxlen = 600000;
const LL mod1 = 1E9 + 7, mod2 = 998244353, base1 = 2333333333, base2 = 3927345117;
int n, m;
char s[maxlen + 10];
struct node {
    LL x, y;
    bool operator < (const node &Other) const {
        return (x != Other.x) ? (x < Other.x) : (y < Other.y);
    }
    node up (LL X, LL Y) {
        node New = *this;
        New.x = (x + X + mod1) % mod1;
        New.y = (y + Y + mod2) % mod2;
        return New;
    }
} hash[maxn + 1];
node Hash(char *s) {
    LL hash1 = 0, hash2 = 0;
    for (int i = 0; s[i]; ++i) {
        hash1 = (hash1 * base1 + s[i]) % mod1;
        hash2 = (hash2 * base2 + s[i]) % mod2;
    }
    return (node) {hash1, hash2};
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s);
        hash[i] = Hash(s);
    }
    sort(hash + 1, hash + n + 1);
    for (int i = 1; i <= m; ++i) {
        scanf("%s", s);
        node h = Hash(s);
        int len = strlen(s);
        bool flag = 0;
        LL b1 = 1, b2 = 1;
        for (int i = len - 1; i >= 0; --i) {
            if (s[i] != 'a' && binary_search(hash + 1, hash + n + 1, h.up(b1 * ('a' - s[i]) % mod1, b2 * ('a' - s[i]) % mod2))) {
                flag = 1;
                break;
            }
            if (s[i] != 'b' && binary_search(hash + 1, hash + n + 1, h.up(b1 * ('b' - s[i]) % mod1, b2 * ('b' - s[i]) % mod2))) {
                flag = 1;
                break;
            }
            if (s[i] != 'c' && binary_search(hash + 1, hash + n + 1, h.up(b1 * ('c' - s[i]) % mod1, b2 * ('c' - s[i]) % mod2))) {
                flag = 1;
                break;
            }
            b1 = b1 * base1 % mod1;
            b2 = b2 * base2 % mod2;
        }
        if (flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
