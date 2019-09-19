#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], b[N], nm[10], c[N];

int main() {
  int T;
  scanf("%d", &T);
  for(int o = 1, n; o <= T; ++o) {
    scanf("%d", &n);
    c[0] = 0;
    for(int i = 1; i <= n; ++i) b[i] = 0;
    memset(nm, 0, sizeof nm);
    int pos = 0;
    for(int i = 1; i <= n; ++i) {
      scanf("%1d", &a[i]);
      nm[a[i]]++;
    }
    for(int i = 1; i <= n; ++i) {
      while(!nm[pos] && pos <= 10) pos++;
      if(pos > 10) break;
      if(a[i] == pos) {
        b[i] = 1;
        c[++c[0]] = a[i];
        nm[pos]--;
      }
    }
    for(int i = 1; i <= n; ++i) {
      if(!b[i]) c[++c[0]] = a[i];
    }
    int flg = 1;
    for(int i = 2; i <= n; ++i) {
      if(c[i] < c[i - 1]) {
        flg = 0;
        break;
      }
    }
    if(!flg) {
      puts("-");
      continue;
    }
    for(int i = 1; i <= n; ++i)
      printf("%d", 2 - b[i]);
    puts("");
  }
  return 0;
}
