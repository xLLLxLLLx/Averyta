#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
char lx[N];

int main() {
  scanf("%s", lx + 1);
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    int z = lx[x] == lx[y];
    printf("%d", z);
  }
  puts("");
  return 0;
}
