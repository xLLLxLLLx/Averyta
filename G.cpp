#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 10;
int pr[N], phi[N];
bool flg[N];

void init(int n) {
  phi[1] = 1;
  for(int i = 2; i <= n; ++i) {
    if(!flg[i]) {
      pr[++pr[0]] = i;
      phi[i] = i - 1;
    }
    for(int j = 1; j <= pr[0]; ++j) {
      if(i * pr[j] > n) break;
      flg[i * pr[j]] = 1;
      if(i % pr[j] == 0) {
        phi[i * pr[j]] = phi[i] * pr[j];
        break;
      } else {
        phi[i * pr[j]] = phi[i] * (pr[j] - 1);
      }
    }
  }
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  if(k == 1) return printf("%d\n", 3), 0;
  init(n);
  sort(phi + 1, phi + 1 + n);
  ll ans = 0;
  for(int i = 1; i <= k + 2; ++i)
    ans += phi[i];
  printf("%lld\n", ans);
  return 0;
}
