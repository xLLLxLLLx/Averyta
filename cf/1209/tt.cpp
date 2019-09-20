#include <bits/stdc++.h>
using namespace std;
set<int> s;

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1, x; i <= n; ++i) {
    scanf("%d", &x);
    s.insert(x);
  }
  printf("%d %d\n", *s.rbegin(), *s.begin());
  return 0;
}
