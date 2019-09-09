#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n / 2; i++) {  
        for (int j = 1; j <= m; j++) {
            printf("%d %d\n", i, j);
            printf("%d %d\n", n + 1 - i, m + 1 - j);
        }
    }
    if (n & 1) { 
        n = (n + 1) / 2;
        for (int i = 1; i <= m / 2; i++) {
            printf("%d %d\n", n, i);
            printf("%d %d\n", n, m + 1 - i);
        }
        if (m & 1) printf("%d %d\n", n, (m + 1) / 2);
    }
}
