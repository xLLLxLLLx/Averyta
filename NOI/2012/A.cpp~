#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct data {
  ll c[2][2];
} ;
ll mod;

ll mul(ll x, ll y) {
  ll pos = 0;
  for(; y; y >>= 1) {
    if(y & 1) pos = (pos + x) % mod;
    x = (x + x) % mod;
  }
  return pos;
}

void Add(ll &x, ll y) {
  x = (x + y) % mod;
}

ll add(ll x, ll y) {
  return (x + y) % mod;
}

ll q_pow(ll x, ll y) {
//  printf("x = %lld y = %lld\n", x, y);
  ll ans = 1;
  for(; y; y >>= 1) {
    //printf("%lld\n", y);
    if(y & 1) ans = mul(ans, x);
    x = mul(x, x);
  }
  return ans;
}

data Mul(data A, data B) {
  data res;
  for(int i = 0; i < 2; ++i)
    for(int j = 0; j < 2; ++j) {
      res.c[i][j] = 0;
      for(int k = 0; k < 2; ++k) {
        Add(res.c[i][j], mul(A.c[i][k], B.c[k][j]));
      }
    }
  return res;
}

ll n, m, a, c, x;

ll Pw(ll y) {
  if(!y) {
    return 1ll;
  }
  data tmp, now, ans;
  for(int i = 0; i < 2; ++i)
    for(int j = 0; j < 2; ++j)
      tmp.c[i][j] = (i == j);
  now.c[0][0] = x, now.c[0][1] = 0;
  now.c[1][0] = 1, now.c[1][1] = 1;
  for(; y; y >>= 1) {
    if(y & 1) tmp = Mul(tmp, now);
    now = Mul(now, now);
  }
  ans.c[0][0] = 1, ans.c[0][1] = 1;
  ans.c[1][0] = 0, ans.c[1][1] = 0;
  ans = Mul(ans, tmp);
//  printf("%lld\n", ans.c[0][0]);
  return ans.c[0][0];
}

int main() {
  cin >> mod >> x >> c >> a >> n >> m;
//  printf("%lld %lld\n", x, n);
  if(x == 1) {
    printf("%lld\n", add(mul(n, c), a) % m);
  } else {
    //printf("%lld %lld\n", x, n);
    ll ans = mul(a, q_pow(x, n));
    //printf("XXXX");
    Add(ans, mul(c, Pw(n - 1)));
    printf("%lld\n", ans % m);
  }
  return 0;
}
