#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10;
int b[N];
ll tr[N], a[N];

int lower(int x) {
  return x & (-x);
}

void upd(int x, int y) {
  for(; x < N; x += lower(x)) 
    tr[x] += y;
}

ll get(int x) {
  ll ans = 0;
  for(; x; x -= lower(x)) 
    ans += tr[x];
  return ans;
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    upd(i + 1, i);
    scanf("%lld", &a[i]);
  }
  for(int i = n; i >= 1; --i) {
    int l = 1, r = n, ans = 0;
    while(l <= r) {
      int mid = (l + r) >> 1;
      if(get(mid) <= a[i]) {
        ans = mid, l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    b[i] = ans;
    upd(ans + 1, -ans);
  }
  for(int i = 1; i <= n; ++i)
    printf("%d ", b[i]);
  puts("");
  return 0;
}
