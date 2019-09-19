#include <bits/stdc++.h>
using namespace std;
const int N = 110;
char lx[N];
int a[N], b[N], c[N];

int main() {
  int n;
  scanf("%d%s", &n, lx + 1);
  for(int i = 1; i <= n; ++i) {
    scanf("%d%d", &a[i], &b[i]);
    c[i] = (lx[i] == '1');
  }
  int ans = 0;
  for(int i = 0; i <= 100000; ++i) {
    int pos = 0;
    for(int j = 1; j <= n; ++j) {
      if(i >= b[j]) {
        if((i - b[j]) % a[j] == 0) c[j] ^= 1;
      }
      pos += c[j];
    }
    ans = max(ans, pos);
  }
  printf("%d\n", ans);
  return 0;
}
