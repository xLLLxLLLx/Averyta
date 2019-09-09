#include <bits/stdc++.h>
using namespace std;
const int N = 85;
int dx[4] = {0, -1, 1};
int dy[4] = {1, 0, 0};
int a[N][N], f[N][N], vis[N][N];
typedef pair<int, int> P;

void read(int &x) {
  char ch = getchar(); x = 0;
  for(; ch < '0' || ch > '9'; ch = getchar()) ;
  for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
}

queue<P> q;

int main() {
  int n = 80, maxn = 1e9;
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j) {
      read(a[i][j]);
    }
  for(int o = 1; o <= n; ++o) {
    memset(f, 0x3f, sizeof f);
    f[o][1] = a[o][1];
    vis[o][1] = 1;
    q.push(P(o, 1));
    while(!q.empty()) {
      P h = q.front(); q.pop();
      int x = h.first, y = h.second;
      vis[x][y] = 0;
      for(int i = 0; i < 3; ++i) {
        int xx = x + dx[i], yy = y + dy[i];
        if(x == 2 && y == 3) {
        //  printf("qwq%d %d\n", xx, yy);
        }
        if(xx < 1 || xx > n || yy < 1 || yy > n) continue;
        if(f[xx][yy] > f[x][y] + a[xx][yy]) {
          f[xx][yy] = f[x][y] + a[xx][yy];
          if(!vis[xx][yy]) {
            vis[xx][yy] = 1;
            q.push(P(xx, yy));
          }
        }
      }
    }
    //for(int i = 1; i <= n; ++i)
      //for(int j = 1; j <= n; ++j)
        //printf("f[%d][%d]=%d\n", i, j, f[i][j]);
    int pos = 1e9;
    for(int i = 1; i <= n; ++i)
      pos = min(pos, f[i][n]);
    maxn = min(maxn, pos);
    //printf("%d %d\n", o, pos);
  }
  printf("%d\n", maxn);
  return 0;
}
