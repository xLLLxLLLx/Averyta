#include <bits/stdc++.h>
#define ls x << 1
#define rs x << 1 | 1
#define ll long long
using namespace std;
const int N = 1e6 + 10;
ll c[N];
int a[N], mx[N << 2];

void upd(int l, int r, int w) {
  c[l] += w;
  c[r + 1] -= w;
}

void build(int x, int l, int r) {
  if(l == r) {
    scanf("%d", &a[l]);
    mx[x] = a[l];
    return ;
  }
  int mid = (l + r) >> 1;
  build(ls, l, mid), build(rs, mid + 1, r);
  mx[x] = max(mx[ls], mx[rs]);
}

int get(int x, int l, int r, int L, int R) {
  if(L <= l && r <= R) {
    return mx[x];
  }
  int mid = (l + r) >> 1;
  if(R <= mid) return get(ls, l, mid, L, R);
  if(L > mid) return get(rs, mid + 1, r, L, R);
  else return max(get(ls, l, mid, L, R), get(rs, mid + 1, r, L, R));
}

int main() {
  int n, w;
  cin >> n >> w;
  for(int o = 1, num; o <= n; ++o) {
    scanf("%d", &num);
    build(1, 1, num);
    if(num == w) {
      for(int i = 1; i <= w; ++i)
        upd(i, i, a[i]);
    }
    else if(num * 2 <= w) {
      int pos = 0;
      for(int i = 1; i <= num; ++i) {
        pos = max(pos, a[i]);
        upd(i, i, pos);
      }
      if(num + 1 <= w - num) upd(num + 1, w - num, pos);
      pos = 0;
      for(int i = num; i >= 1; --i) {
        pos = max(pos, a[i]);
        //printf("%d %d %d\n", o, w - i + num, pos);
        upd(w + i - num, w + i - num, pos);    
      }
    } else {
      int pos = 0;
      for(int i = 1; i <= w - num; ++i) {
        pos = max(pos, a[i]);
        upd(i, i, pos);
      }
      for(int i = w - num + 1; i <= num; ++i) {
        upd(i, i, get(1, 1, num, (i - (w - num)), i));
      }
      pos = 0;
      for(int i = 1; i <= w - num; ++i) {
        pos = max(pos, a[num - i + 1]);
        upd(w - i + 1, w - i + 1, pos);
      }
    }
  }
  for(int i = 1; i <= w; ++i) {
    c[i] += c[i - 1];
//    printf("%lld\n", c[i]);
  }
  for(int i = 1; i <= w; ++i)
    printf("%lld ", c[i]);
  puts("");
  return 0;
}
