#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  for(int o = 1; o <= T; ++o) {
    int a, b, n;
    cin >> a >> b >> n;
    int pos = n % 3;
    if(!pos) printf("%d\n", a);
    else if(pos == 1) printf("%d\n", b);
    else printf("%d\n", a ^ b);
  }
  return 0;
}
