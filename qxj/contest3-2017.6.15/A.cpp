#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
string a[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string b[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string c[10] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
int n;
string t;
int main() {
    scanf("%d", &n);
    if (n <= 9) t = a[n];
    else {
        if (n <= 19) t = b[n - 10];
        else {
            if (!(n % 10)) t = c[n / 10];
            else t = c[n / 10] + "-" + a[n % 10];
        }
    }
    printf("%s\n", t.c_str());
    return 0;
}
