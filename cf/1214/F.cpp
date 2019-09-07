#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int a[N], cnt[N];

void insert(int x, int b) {
  if(cnt[x] >= 2) return ;
  if(b == -1) {
    cnt[x]++;
    return ;
  }
  insert(x, b - 1);
  if(x & (1 << b)) insert(x ^ (1 << b), b - 1);
}

int ask(int x) {
  int ans = 0;
  for(int i = 20; i >= 0; --i) {
    if(!((x >> i) & 1) && cnt[ans | (1 << i)] >= 2) ans |= (1 << i);
  }
  return x | ans;
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  int ans = 0;
  for(int i = n; i >= 1; --i) {
    if(i <= n - 2) ans = max(ans, ask(a[i]));
    insert(a[i], 20);
  }
  printf("%d\n", ans);
  return 0;
}
