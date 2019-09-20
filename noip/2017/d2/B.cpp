#include <bits/stdc++.h>
using namespace std;
const int N = 12, M = 1e3 + 10, MASK = (1 << 12);
struct data {
  int nt, to; 
} a[M << 1];
int f[MASK][N][N], head[N], cnt = 0;

void add(int x, int y) {
  a[++cnt].to = y;
  a[cnt].nt = head[x];
  head[x] = cnt;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 1, x, y; i <= m; ++i) {
    scanf("%d%d", &x, &y);
    x--, y--;
    add(x, y), add(y, x);
  }
  int tot = (1 << n) - 1, ans = 1e9;
  for(int o = 0; o < n; ++o) {
    memset(f, -1, sizeof f);
    f[(1 << o)][o][1] = 0;
    for(int j = 0; j <= tot; ++j) {
      for(int k = 0; k < n; ++k) {
        for(int t = 0; t < n; ++t) {
          if(f[j][k][t] == -1) continue;
          for(int i = head[k]; i; i = a[i].nt) {
            int to = a[i].to;
            if((j >> to) & 1) continue;
          }
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
