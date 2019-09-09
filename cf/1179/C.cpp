#include <bits/stdc++.h>
#define ls x << 1
#define rs x << 1 | 1
using namespace std;
const int N = 1e6 + 10;
int a[N];



int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for(int i = 1; i <= m; ++i) {
    scanf("%d", &b[i]);
  }
  sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + m);
  
  return 0;
}
