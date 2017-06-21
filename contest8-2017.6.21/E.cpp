#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
const int maxn = 300, maxk = 300;
const double eps = 1E-10;
int n, k;
int t1, t2;
struct node {
    double x1, y1, x2, y2;
} a[maxn * maxk + 100], b[maxn * maxk + 100];
bool check() {
    if (t2 > 1 && b[t2].x1 != int(b[t2].x1)) {
        double k1 = (b[t2 - 1].y1 - b[t2 - 1].y2) / (b[t2 - 1].x1 - b[t2 - 1].x2),
               k2 = (b[t2].y1 - b[t2].y2) / (b[t2].x1 - b[t2].x2);
        if (abs(k1 - k2) < eps) {
            b[t2 - 1].x2 = b[t2].x2;
            b[t2 - 1].y2 = b[t2].y2;
            --t2;
            return 1;
        }
    }
    return 0;
}
double sum1 = 0, sum2;
int main() {
    scanf("%d%d", &n, &k);
    t1 = k;
    for (int i = 1; i <= k; ++i) {
        a[i].x1 = i - 1;
        a[i].y1 = 0;
        a[i].x2 = i;
        a[i].y2 = 0;
    }
    for (int i = 1; i <= n; ++i) {
        double y1, y2;
        scanf("%lf", &y1);
        int head = 1, tail = 1;
        t2 = 0;
        for (int j = 1; j <= k; ++j) {
            scanf("%lf", &y2);
            double K = y2 - y1, B = y1 * j + y2 * (1 - j);
            while (tail < t1 && a[tail + 1].x2 <= j) ++tail;
            for (int k = head; k <= tail; ++k) {
                double Y1 = K * a[k].x1 + B, Y2 = K * a[k].x2 + B;
                if (Y1 >= a[k].y1 && Y2 >= a[k].y2) {
                    b[++t2].x1 = a[k].x1;
                    b[t2].x2 = a[k].x2;
                    b[t2].y1 = Y1;
                    b[t2].y2 = Y2;
                } else {
                    if (Y1 <= a[k].y1 && Y2 <= a[k].y2) b[++t2] = a[k];
                    else {
                        double K2 = (a[k].y1 - a[k].y2) / (a[k].x1 - a[k].x2),
                               B2 = a[k].y1 - K2 * a[k].x1;
                        double X = (B2 - B) / (K - K2), Y = K * X + B;
                        b[++t2].x1 = a[k].x1;
                        b[t2].y1 = max(a[k].y1, Y1);
                        b[t2].x2 = X;
                        b[t2].y2 = Y;
                        b[++t2].x1 = X;
                        b[t2].y1 = Y;
                        b[t2].x2 = a[k].x2;
                        b[t2].y2 = max(a[k].y2, Y2);
                    }
                }
                while (check());
            }
            y1 = y2;
            head = tail + 1;
        }
        t1 = 0;
        sum2 = 0;
        for (int j = 1; j <= t2; ++j) {
            if (abs(b[j].x1 - b[j].x2) < eps) continue;
            a[++t1] = b[j];
            sum2 += (a[t1].y1 + a[t1].y2) * (a[t1].x2 - a[t1].x1) / 2;
        }
        printf("%.12lf\n", sum2 - sum1);
        sum1 = sum2;
    }
    return 0;
}
