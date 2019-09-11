#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10, M = 1e6 + 10, mod = 1e9 + 7;
struct data {
  int l, r, id;
} q[N];
ll d[N], qz[N];
int lst[N], a[N], yz[M], pr[N];

ll add(ll x, ll y) {
  return (x + y) % mod;
}

ll mul(ll x, ll y) {
  return x * y % mod;
}

ll q_pow(ll x, int y) {
  ll ans = 1;
  for(; y; y >>= 1) {
    if(y & 1) ans = mul(ans, x);
    x = mul(x, x);
  }
  return ans;
}

void init() {
  for(int i = 2; i < M; ++i) {
    if(!yz[i]) yz[i] = i, pr[++pr[0]] = i;
    for(int j = 1; j <= pr[0]; ++j) {
      if(i * pr[j] >= M) break;
      if(!yz[i * pr[j]]) yz[i * pr[j]] = j;
      if(i % pr[j] == 0) break;
    }
  }
}

ll tr[N];

int lower(int x) {
  return x & (-x);
}

void upd(int x, ll y) {
  for(; x; x -= lower(x)) {
    tr[x] = mul(tr[x], y);
  }
}

ll go(int x) {
  ll ans = 1;
  for(; x < N; x += lower(x)) {
    ans = mul(ans, tr[x]);
  }
  return ans;
}

bool cmp(data A, data B) {
  return A.r < B.r;
}

void insert(int id, int s) {
  upd(lst[id], mul(pr[id], q_pow(pr[id] - 1, mod - 2)));
  upd(s, mul(pr[id] - 1, q_pow(pr[id], mod - 2)));
  lst[id] = s;
}

int main() {
  init();
  int n;
  scanf("%d", &n);
  qz[0] = 1;
  for(int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    qz[i] = mul(qz[i - 1], a[i]);
  }
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; ++i) {
    q[i].id = i;
    scanf("%d%d", &q[i].l, &q[i].r);
  }
  sort(q + 1, q + 1 + T, cmp);
  int now = 1;
  printf("xxx\n");
  for(int i = 1; i <= n; ++i) {
    printf("qwq%d %d\n", i, now);
    for(; a[i] != 1;) {
      insert(yz[a[i]], i);
      a[i] /= pr[yz[a[i]]];
      printf("%d %d\n", a[i], pr[yz[a[i]]]);
    }
    for(int j = now; j <= T; ++j) {
      now = j;
      if(q[j].r != i) {
        break;
      }
      d[q[j].id] = mul(go(q[j].l), mul(qz[q[j].r], q_pow(qz[q[j].l - 1], mod - 2)));
    }
    
  }
  for(int i = 1; i <= T; ++i)
    printf("%lld\n", d[i]);
  return 0;
}
