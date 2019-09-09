#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 10;
struct data {
  int x, y;
} c[N];
int a[N], b[N];

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  int maxn = 0;
  for(int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    maxn = max(maxn, a[i]);
  }
  int now = 1, res = 0, len = n;
  for(;;) {
    c[++res] = (data) {a[now], a[now + 1]};
    int pos = min(a[now], a[now + 1]), tmp = max(a[now], a[now + 1]);
    a[now + 1] = tmp, a[++len] = pos;
    now++;
    if(a[now] == maxn) {
      for(int i = now + 1; i <= now + n - 1; ++i)
        b[i - now] = a[i];
      break;  
    }
  }
  for(int o = 1; o <= q; ++o) {
    ll x;
    scanf("%lld", &x);
    if(x <= res) {
      printf("%d %d\n", c[x].x, c[x].y);
    } else {
      x -= res;
      x %= (n - 1);
      if(!x) x = n - 1;
      printf("%d %d\n", maxn, b[x]);
    }
  }
  return 0;
}
