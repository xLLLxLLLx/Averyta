#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
vector<int> g[N];
map<int, int> mp;
int a[N], vs[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  int now = 0;
  for(int i = 1; i <= n; ++i) {
    if(!vs[i]) {
      vs[i] = ++now;
      g[now].push_back(i);
      for(int j = i + 1; j <= n; ++j)
        if(a[j] == a[i]) {
          vs[j] = -1;
          g[now].push_back(j);
        }
    }
  }
  int p = 0, maxn = n, ed = 0;
  for(int i = n; i >= 1; --i) {
    if(!mp[a[i]]) {
      mp[a[i]] = 1;
      p = i - 1;
      maxn = min(maxn, i - 1);
    } else break;
  }
//  printf("%d %d\n", maxn, p);
  for(int i = 1; i <= n; ++i) {
    if(vs[i] == -1) break;
    int tmp = g[vs[i]].size();
    if(tmp > 1) ed = max(ed, g[vs[i]][tmp - 1]);
    ed = max(ed, i);
//    printf("%d %d\n", i, ed);
    maxn = min(maxn, max(p, ed) - i);
  }
//  printf("%d\n", maxn);
  printf("%d\n", maxn);
  return 0;
}
