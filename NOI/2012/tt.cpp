#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, a, c, x, mod;

void js() {
  ll pos = 1, ans = 0;
  for(int i = 0; i <= n - 1; ++i) {
    ans = (ans + pos) % m;
    pos = pos * x % m;
  }
  printf("%lld\n", ans);
  ans = ans * c % m;
  ans = (ans + pos * a % m) % m;
  printf("%lld\n", ans % mod);
}

int main() {
  cin >> m >> x >> c >> a >> n >> mod;
  js();
  for(int i = 1; i <= n; ++i) {
    a = (a * x % m + c) % m;
  }
  printf("%lld\n", a % mod);
  return 0;
}
