#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
struct node {
    int M[4][4];
    int Hash1[4], Hash2[4];
} a[9];
bool v[9];
int x[9], y[9];
int M[10][10];
void DFS(int k) {
    if (k == 9) {
        for (int i = 0; i < 9; ++i) {
            int X = i / 3 * 3, Y = i % 3 * 3;
            if (!y[i]) {
                for (int j = 0; j < 4; ++j)
                    for (int k = 0; k < 4; ++k)
                        M[X + j][Y + k] = a[x[i]].M[j][k];
                continue;
            }
            if (y[i] == 1) {
                for (int j = 0; j < 4; ++j)
                    for (int k = 0; k < 4; ++k)
                        M[X + j][Y + k] = a[x[i]].M[3 - k][j];
                continue;
            }
            if (y[i] == 2) {
                for (int j = 0; j < 4; ++j)
                    for (int k = 0; k < 4; ++k)
                        M[X + j][Y + k] = a[x[i]].M[3 - j][3 - k];
                continue;
            }
            if (y[i] == 3) {
                for (int j = 0; j < 4; ++j)
                    for (int k = 0; k < 4; ++k)
                        M[X + j][Y + k] = a[x[i]].M[k][3 - j];
                continue;
            }
        }
        for (int i = 0; i < 10; putchar('\n'), ++i)
            for (int j = 0; j < 10; ++j)
                printf("%d ", M[i][j]);
        exit(0);
    }
    if (!k) {
        for (int i = 0; i < 9; ++i) {
            v[i] = 1;
            x[k] = i;
            for (int j = 0; j < 4; ++j) {
                y[k] = j;
                DFS(k + 1);
            }
            v[i] = 0;
        }
        return;
    }
    if (k <= 2) {
        for (int i = 0; i < 9; ++i) {
            if (v[i]) continue;
            v[i] = 1;
            x[k] = i;
            for (int j = 0; j < 4; ++j)
                if (a[x[k - 1]].Hash1[(y[k - 1] + 3) % 4] == a[i].Hash2[(j + 1) % 4]) {
                    y[k] = j;
                    DFS(k + 1);
                }
            v[i] = 0;
        }
        return;
    }
    if (k == 3 || k == 6) {
        for (int i = 0; i < 9; ++i) {
            if (v[i]) continue;
            v[i] = 1;
            x[k] = i;
            for (int j = 0; j < 4; ++j)
                if (a[x[k - 3]].Hash1[(y[k - 3] + 2) % 4] == a[i].Hash2[j]) {
                    y[k] = j;
                    DFS(k + 1);
                }
            v[i] = 0;
        }
        return;
    }
    for (int i = 0; i < 9; ++i) {
        if (v[i]) continue;
        v[i] = 1;
        x[k] = i;
        for (int j = 0; j < 4; ++j)
            if (a[x[k - 3]].Hash1[(y[k - 3] + 2) % 4] == a[i].Hash2[j] && a[x[k - 1]].Hash1[(y[k - 1] + 3) % 4] == a[i].Hash2[(j + 1) % 4]) {
                y[k] = j;
                DFS(k + 1);
            }
        v[i] = 0;
    }
    return;
}
int main() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 4; ++k)
                scanf("%d", &a[i].M[j][k]);
        for (int j = 0; j < 4; ++j)
            a[i].Hash1[0] = a[i].Hash1[0] * 100 + a[i].M[0][j];
        for (int j = 3; j >= 0; --j)
            a[i].Hash2[0] = a[i].Hash2[0] * 100 + a[i].M[0][j];
        for (int j = 3; j >= 0; --j)
            a[i].Hash1[1] = a[i].Hash1[1] * 100 + a[i].M[j][0];
        for (int j = 0; j < 4; ++j)
            a[i].Hash2[1] = a[i].Hash2[1] * 100 + a[i].M[j][0];
        for (int j = 3; j >= 0; --j)
            a[i].Hash1[2] = a[i].Hash1[2] * 100 + a[i].M[3][j];
        for (int j = 0; j < 4; ++j)
            a[i].Hash2[2] = a[i].Hash2[2] * 100 + a[i].M[3][j];
        for (int j = 0; j < 4; ++j)
            a[i].Hash1[3] = a[i].Hash1[3] * 100 + a[i].M[j][3];
        for (int j = 3; j >= 0; --j)
            a[i].Hash2[3] = a[i].Hash2[3] * 100 + a[i].M[j][3];
    }
    DFS(0);
    return 0;
}
