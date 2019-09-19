#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, mod = 1e9 + 7;
struct data {
  int to, w;
};
int now;
int vs[N], nxt[N], c[10];
vector<data> g[N];

void Add(int x, int y, int w) {
  //printf("%d %d %d\n", x, y, w);
  g[x].push_back((data){y, w});
}

void add(int x, int y, int w) {
  int lt = x;
  c[0] = 0;
  for(; w; w /= 10) c[++c[0]] = w % 10;
  reverse(c + 1, c + 1 + c[0]);
  for(int i = 1; i <= c[0]; ++i) {
    if(i == c[0]) Add(lt, y, c[i]);
    else Add(lt, ++now, c[i]), lt = now;
  }
}

int d[N];
queue<int> q;
void bfs() {
  q.push(1);
  memset(d, 0x3f, sizeof d);
  d[1] = 0;
  vs[1] = 1;
  while(!q.empty()) {
    int h = q.front(); q.pop();
    vs[h] = 0;
    for(int i = 0; i < g[h].size(); ++i) {
      int to = g[h][i].to;
      if(d[to] > d[h] + 1) {
        d[to] = d[h] + 1;
        if(!vs[to]) {
          vs[to] = 1;
          q.push(to);
        }
      }
    }
  }
}

int ans[N];
void dfs(int x, int w) {
  //printf("x = %d w = %d\n", x, w);
  int p = x;
  for(; p; p = nxt[p]) ans[p] = w;
  for(int i = 0; i < 10; ++i) {
    int q = -1, fir = -1, p = x;
    for(; p; p = nxt[p]) {
      for(int j = 0; j < g[p].size(); ++j) {
        data res = g[p][j];
        if(!vs[res.to] && d[res.to] == d[p] + 1) {
          if(res.w == i) {
            if(fir == -1) fir = res.to;
            else nxt[res.to] = q;
            vs[q = res.to] = 1; 
          }
        }
      }
    }
    if(~q) dfs(q, (1ll * w * 10 % mod + i) % mod);
  }
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  now = n;
  for(int i = 1, x, y; i <= m; ++i) {
    scanf("%d%d", &x, &y);
    add(x, y, i), add(y, x, i);
  }
  bfs(), dfs(1, 0);
  for(int i = 2; i <= n; ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
