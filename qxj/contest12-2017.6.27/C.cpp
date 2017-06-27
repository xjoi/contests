#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const double eps = 1E-10;
int cnt = 0;
struct node {
    double x, y;
    double dis(const node &Other) {
        return sqrt(pow(x - Other.x, 2) + pow(y - Other.y, 2));
    }
} p[4], q[4];
bool judge(double x, double y) {
    return abs(x - y) < eps;
}
int main() {
    for (int i = 0; i < 4; ++i)
        scanf("%lf%lf", &p[i].x, &p[i].y);
    if (judge(p[0].dis(p[1]), p[0].dis(p[3])) && judge(p[2].dis(p[1]), p[2].dis(p[3]))) cnt += 2;
    if (judge(p[1].dis(p[0]), p[1].dis(p[2])) && judge(p[3].dis(p[0]), p[3].dis(p[2]))) cnt += 2;
    if ((p[1].x - p[2].x) / (p[1].y - p[2].y) == (p[0].x - p[3].x) / (p[0].y - p[3].y) && judge(p[1].dis(p[3]), p[2].dis(p[0])) && judge(p[1].dis(p[0]), p[2].dis(p[3]))) cnt += 2;
    if ((p[0].x - p[1].x) / (p[0].y - p[1].y) == (p[3].x - p[2].x) / (p[3].y - p[2].y) && judge(p[1].dis(p[3]), p[0].dis(p[2])) && judge(p[0].dis(p[3]), p[1].dis(p[2]))) cnt += 2;
    printf("%d\n", cnt);
    return 0;
}
