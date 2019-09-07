#include <bits/stdc++.h>
using namespace std;
const int N = 110;
vector<int> g[N];
int p[N], a[N][N], w[N];
char lx[2];

bool cmp(int x, int y) {
  return w[x] < w[y];
}

int main() {
  int T;
  scanf("%d", &T);
  for(int o = 1; o <= T; ++o) {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) 
      for(int j = 1; j <= n; ++j) 
        scanf("%d", &a[i][j]);
    puts("B");fflush(stdout);
    int x;
    scanf("%s%d", lx + 1, &x);
    if((lx[1] == 'D') ^ (x > n)) {
      for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
          a[i][j] = -a[i][j];
    }
    for(int i = 1; i <= n; ++i) {
      g[i].resize(n);
      for(int j = 1; j <= n; ++j) g[i][j - 1] = j, w[j] = a[i][j];
      sort(g[i].begin(), g[i].end(), cmp);
    }
    memset(p, -1, sizeof p);
    int m = n;
    while(m) {
      for(int i = 1; i <= n; ++i) {
        if(p[i] == -1) {
          for(int j = 0; j < g[i].size(); ++j) {
            int now = g[i][j];
            if(p[now + n] == -1) {
              p[now + n] = i;
              p[i] = now + n;
              m--;
              break;
            } else if(a[i][now] > a[p[now + n]][now]) {
              p[p[now + n]] = -1;
              p[now + n] = i;
              p[i] = now + n;
              break;
            }
          }
        }
      }
    }
    while(~x) {
      printf("%d\n", p[x]);
      fflush(stdout);
      scanf("%d", &x);
    }
  }
  return 0;
}
