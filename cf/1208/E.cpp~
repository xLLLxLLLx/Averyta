#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct data {
  int w, id;
} a[N];
int b[N];

bool cmp(data A, data B) {
  return A.w > B.w;
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    scanf("%d", &a[i].w);
    a[i].id = i;
  }
  sort(a + 1, a + 1 + n, cmp);
  for(int i = 1; i < n; ++i) {
    printf("%d %d\n", a[i].id * 2, a[i + 1].id * 2);
  }  
  for(int i = 1; i <= n; ++i) {
    b[i] = a[i].id * 2;
  }
  int ed = n;
  for(int i = 1; i <= n; ++i) {
    int pos = i + a[i].w - 1;
    printf("%d %d\n", b[pos], a[i].id * 2 - 1);
    if(pos == ed) b[++ed] = a[i].id * 2 - 1;
  }
  return 0;
}
