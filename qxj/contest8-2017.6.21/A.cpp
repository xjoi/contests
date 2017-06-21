#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a, b, cnt = 0;
int main() {
    scanf("%d%d", &a, &b);
    cnt = a;
    while (a / b) {
        cnt += a / b;
        a = a / b + a % b;
    }
    printf("%d\n", cnt);
    return 0;
}
