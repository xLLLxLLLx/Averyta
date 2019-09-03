#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int a[N][N];

int main() {
  int n, now = 0;
  scanf("%d", &n);
  for(int i = 1; i <= n / 2; ++i)
    for(int j = 1; j <= n / 2; ++j) {
      a[i][j] = now * 4;
      a[i][j + n / 2] = now * 4 + 1;
      a[i + n / 2][j] = now * 4 + 2;
      a[i + n / 2][j + n / 2] = now * 4 + 3;
      ++now;
    }
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j)
      printf("%d ", a[i][j]);
    puts("");
  }
  return 0;
}
