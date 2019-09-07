#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int a[N][N], b[N][N];

void fail() {
  puts("Impossible");
  exit(0);
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j)
      scanf("%d", &a[i][j]);
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j)
      scanf("%d", &b[i][j]);
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j) {
      int x = a[i][j], y = b[i][j];
      a[i][j] = min(x, y), b[i][j] = max(x, y);
    }
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j < m; ++j) {
      if(a[i][j + 1] <= a[i][j]) fail();
      if(b[i][j + 1] <= b[i][j]) fail();
    }
  for(int j = 1; j <= m; ++j)
    for(int i = 1; i < n; ++i) {
      if(a[i + 1][j] <= a[i][j]) fail();
      if(b[i + 1][j] <= b[i][j]) fail();
    }
  puts("Possible");
  return 0;
}
