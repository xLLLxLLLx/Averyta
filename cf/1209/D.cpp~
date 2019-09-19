#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct data {
  int nt, to;
} a[N << 1];
int head[N], c[N], vs[N], cnt = 0, res = 0;

void add(int x, int y) {
  a[++cnt].to = y;
  a[cnt].nt = head[x];
  head[x] = cnt;
}

void dfs(int x) {
//  printf("%d\n", x);
  vs[x] = 1;
  for(int i = head[x]; i; i = a[i].nt) {
    int to = a[i].to;
    if(!vs[to]) {
      res++;
      vs[to] = 1;
      c[++c[0]] = to;
    }
  }
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for(int i = 1, x, y; i <= k; ++i) {
    scanf("%d%d", &x, &y);
    add(x, y), add(y, x);
  }
  for(int i = 1; i <= n; ++i) {
    if(!vs[i]) {
      c[c[0] = 1] = i;
      for(int j = 1; j <= c[0]; ++j) {
        dfs(c[j]);
      }
    }
  }
  printf("%d\n", k - res);
  return 0;
}
