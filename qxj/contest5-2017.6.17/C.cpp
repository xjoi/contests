#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int x, y[4], cnt = 0;
int main() {
    scanf("%d%d", &x, &y[1]);
    y[2] = y[3] = y[1];
    while (y[1] < x || y[2] < x || y[3] < x) {
        sort(y + 1, y + 4);
        y[1] = min(x, y[2] + y[3] - 1);
        ++cnt;
    }
    printf("%d\n", cnt);
    return 0;
}
