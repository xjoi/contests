#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <cstdlib>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 500;
const double eps = 1E-10;
int T;
int n, m;
int num[10000];
struct node {
    string name;
    double score;
    bool operator < (const node &Other) const {
        return (abs(score - Other.score) > eps) ? (score > Other.score) : (name < Other.name);
    }
} p[maxn + 1];
map<string, int> Team;
bool Prime(int k) {
    for (int i = 2, p = sqrt(k); i <= p; ++i)
        if (!(k % i)) return 0;
    return 1;
}
int s[1001];
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        memset(num, 0, sizeof(num));
        int r, c;
        scanf("%d", &r);
        for (int i = 1; i <= r; ++i) {
            scanf("%d", &c);
            num[c] = 1;
        }
        scanf("%d", &r);
        for (int i = 1; i <= r; ++i) {
            scanf("%d", &c);
            num[c] = 2;
        }
        Team.clear();
        int Q;
        scanf("%d", &Q);
        for (int i = 1; i <= Q; ++i) {
            string team;
            int p;
            cin >> team;
            scanf("%d", &p);
            Team[team] = p;
        }
        for (int i = 1; i <= n; ++i) {
            p[i].score = 0;
            string team, sex;
            cin >> p[i].name >> team >> sex;
            int k = Team[team];
            if (k == 1) p[i].score += 36;
            else if (k == 2) p[i].score += 27;
            else if (k == 3) p[i].score += 18;
            if (sex == "F") p[i].score += 33;
            int r, c;
            scanf("%d%d", &r, &c);
            for (int j = 1; j <= r; ++j) {
                int x;
                scanf("%d", &x);
                if (num[x] == 1) p[i].score += 2.5;
                else if (num[x] == 2) p[i].score += 1.5;
                else if (Prime(x)) p[i].score += 1;
                else p[i].score += 0.3;
            }
            for (int j = 1; j <= c; ++j)
                scanf("%d", &s[j]);
            if (c >= 3) {
                sort(s + 1, s + c + 1);
                p[i].score += max(0.0, (s[c - 2] - 1200.0) / 100) * 1.5;
            }
        }
        sort(p + 1, p + n + 1);
        for (int i = 1; i <= m; ++i)
            printf("%s %.3lf\n", p[i].name.c_str(), p[i].score);
    }
    return 0;
}
