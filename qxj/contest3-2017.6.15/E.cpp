#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 200000;
int n, N = 0;
struct node {
	int a, b, index;
} p[maxn + 1], t[maxn + 1];
bool cmp1(node x, node y) {
	return (x.a != y.a) ? (x.a > y.a) : (x.b > y.b);
}
bool cmp2(node x, node y) {
	return x.a > y.a;
}
bool win[maxn + 1];
int same[maxn + 1];
int stk[maxn + 1], k = 0;
bool judge(int i, int j, int k) {
    int a1 = t[i].a, b1 = t[i].b, a2 = t[j].a, b2 = t[j].b, a3 = t[k].a, b3 = t[k].b;    
	return LL(a1 - a3) * (b1 - b2) * a2 * b3 > LL(b1 - b3) * (a1 - a2) * a3 * b2;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &p[i].a, &p[i].b);
		p[i].index = i;
	}
	sort(p + 1, p + n + 1, cmp1);
	int index = 0;
	for (int i = 1; i <= n; ++i) {
		if (index) {
			if (p[index].b < p[i].b) t[++N] = p[index = i];
			else if (p[index].a == p[i].a && p[index].b == p[i].b)
				same[p[i].index] = p[index].index;
		} else t[++N] = p[index = i];
	}
	sort(t + 1, t + N + 1, cmp2);
	for (int i = 1; i <= N; ++i) {
		while (k > 1 && judge(stk[k - 1], stk[k], i)) --k;
		stk[++k] = i;
	}
	for (int i = 1; i <= k; ++i)
	   win[t[stk[i]].index] = 1;
	for (int i = 1; i <= n; ++i) {
		if (same[i]) win[i] = win[same[i]];
		if (win[i]) printf("%d ", i);
	}
	return 0;
}
