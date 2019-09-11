#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 10;
struct data {
  int fr, nt, to, id;
} a[N << 1];
int head[N], vs[N], vis[N], d[N], mv[N];
int cnt = 0, n, m, p[N];
ll t = 0;
typedef pair<int, int> P;
vector<P> q;

void add(int x, int y, int id) {
  a[++cnt].fr = x;
  a[cnt].to = y;
  a[cnt].id = id;
  a[cnt].nt = head[x];
  head[x] = cnt;
}

void dfs(int u) {
  vs[u] = 1;
  for(int i = head[u]; i; i = a[i].nt) {
    head[u] = i;
    ++t;
    if(vis[a[i].id]) continue;
    vis[a[i].id] = 1;
    dfs(a[i].to);
    p[++p[0]] = a[i].id;
    i = head[u];
  }
}

void check() {
  //puts("hello");
  t += p[0];
  int res = p[0];
  p[0] = p[res], p[res + 1] = p[1];  
  for(int i = 1; i <= res; ++i) {
    //printf("%d %d\n", a[p[i] * 2].fr, a[p[i] * 2].to);
    if(i & 1) continue;
    else if(p[i] <= m) {
      if(p[i + 1] <= m && p[i - 1] <= m) mv[p[i]] = 1;
    }
  }
}

int main() {
  //freopen("out", "r", stdin);
  scanf("%d%d", &n, &m);
  for(int i = 1, x, y; i <= m; ++i) {
    scanf("%d%d", &x, &y);
    add(x, y, i), add(y, x, i);
    d[x]++, d[y]++;
  }
  int now = m;
  for(int i = 1; i <= n; ++i) {
    if(d[i] & 1) add(0, i, ++now), add(i, 0, now);
  }
  for(int i = 0; i <= n; ++i) {
    if(vs[i]) continue;
    //puts("xx");
    p[0] = 0, dfs(i);
    check();
  }
  for(int i = 1; i <= m; ++i) {
    if(!mv[i]) {
      q.push_back(P(a[i * 2].fr, a[i * 2].to));
    }
  }
  printf("%d\n", q.size());
  for(int i = 0; i < q.size(); ++i) {
    printf("%d %d\n", q[i].first, q[i].second);
  }
  return 0;
}
