#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000;
int n;
int a[maxn + 1];
void turn() {
    for (int i = 1; i <= n; ++i)
        if (i % 2) a[i] = (a[i] + 1) % n;
        else a[i] = (a[i] - 1 + n) % n;
    return;
}
bool judge() {
    for (int i = 1; i <= n; ++i)
        if (a[i] != i - 1) return 0;
    return 1;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    if (judge()) {
        puts("Yes");
        return 0;
    }
    for (int i = 1; i < n; ++i)
        if (turn(), judge()) {
            puts("Yes");
            return 0;
        }
    puts("No");
    return 0;
}
