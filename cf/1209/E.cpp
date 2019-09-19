#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2010, Mask = (1 << 12);
int a[15][N], p[N], mx[N];
int f[2][Mask];

int w[Mask], c[20], n, m;

void Max(int &x, int y) {
  x = max(x, y);
}

void get(int C) {
  memset(w, 0, sizeof w);
  int tot = (1 << n) - 1;
  for(int j = 0; j < n; ++j) {
    for(int k = 0; k < n; ++k) {
      c[(k + j) % n] = a[k][C];
    }
    for(int k = 0; k <= tot; ++k) {
      int pos = 0;
      for(int z = 0; z < n; ++z) {
        if((k >> z) & 1) pos += c[z];
      }
      Max(w[k], pos);
    }
  }
}

bool cmp(int x, int y) {
  return mx[x] > mx[y];
}

int main() {
  int T;
  scanf("%d", &T);
  for(int o = 1; o <= T; ++o) {
    scanf("%d%d", &n, &m);
    memset(f, 0, sizeof f);
    for(int i = 1; i <= m; ++i) mx[i] = 0;
    for(int i = 0; i < n; ++i)
     for(int j = 1; j <= m; ++j) {
      scanf("%d", &a[i][j]);
      mx[j] = max(mx[j], a[i][j]);
     }
    for(int i = 1; i <= m; ++i) p[i] = i;
    sort(p + 1, p + 1 + m, cmp);
    int tot = (1 << n) - 1, now = 0;
    for(int i = 1; i <= min(n, m); ++i) {
      //printf("%d\n", p[i]);
      now ^= 1;
      memset(f[now], 0, sizeof f[now]);
      get(p[i]);
      for(int j = 0; j <= tot; ++j) {
        Max(f[now][j], f[now ^ 1][j]);
        int pos = tot ^ j;
        for(int k = pos; k; k = pos & (k - 1)) {
          Max(f[now][j | k], f[now ^ 1][j] + w[k]);
        }
      }
    }
    printf("%d\n", f[now][tot]);
  }
  return 0;
}
