#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn = 15;
const LL mod = 1E9 + 7;
int n;
LL k, a, b;
struct node {
    int N;
    int M[maxn + 1][maxn + 1];
    node operator * (const node &B) const {
        node C = {};
        C.N = N;
        for (int i = 0; i <= N; ++i)
            for (int j = 0; j <= N; ++j)
                for (int k = 0; k <= N; ++k)
                    C.M[i][j] = (LL(M[i][k]) * B.M[k][j] + C.M[i][j]) % mod;
        return C;
    }
    node operator ^ (LL k) const {
        node A = *this, B = *this;
        for (--k; k; A = A * A, k >>= 1)
            if (k & 1) B = B * A;
        return B;
    }
} A = {}, B;
int main() {
    scanf("%d%lld", &n, &k);
    A.M[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld%lld%d", &a, &b, &A.N);
        if (b > k) b = k;
        if (a == b) continue;
        B.N = A.N;
        for (int j = 0; j <= B.N; ++j) {
            for (int k = 0; k < j - 1; ++k)
                B.M[k][j] = 0;
            if (j > 0) B.M[j - 1][j] = 1;
            B.M[j][j] = 1;
            if (j < B.N) B.M[j + 1][j] = 1;
            for (int k = j + 2; k <= B.N; ++k)
                B.M[k][j] = 0;
        }
        A = A * (B ^ (b - a));
    }
    printf("%d\n", A.M[0][0]);
    return 0;
}
