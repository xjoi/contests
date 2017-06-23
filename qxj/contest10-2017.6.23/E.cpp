#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <map>
using namespace std;
int n, Q;
map<int, pair<int, char> > Map;
int main() {
    scanf("%d%d", &n, &Q);
    Map[0] = make_pair(n + 1, 'U');
    Map[n + 1] = make_pair(n + 1, 'L');
    while (Q--) {
        int x, y;
        char d;
        scanf("%d%d %c", &x, &y, &d);
        map<int, pair<int, char> > :: iterator k = Map.lower_bound(x);
        if (k->first == x) {
            puts("0");
            continue;
        }
        if (d == 'L') --k;
        int cnt = abs(x - k->first) + ((d != k->second.second) ? (0) : (k->second.first));
        printf("%d\n", cnt);
        Map[x] = make_pair(cnt, d);
    }
    return 0;
}
