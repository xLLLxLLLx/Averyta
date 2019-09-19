#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N], vs[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + 1 + n);
  int res = 0;
  for(int i = 1; i <= n; ++i) {
    if(!vs[i]) {
      vs[i] = 1;
      res++;
      for(int j = i + 1; j <= n; ++j) {
        if(a[j] % a[i] == 0) vs[j] = 1;
      }
    }
  }
  printf("%d\n", res);
  return 0;
}
