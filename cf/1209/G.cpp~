#include <bits/stdc++.h>
#define ls x << 1
#define rs x << 1
using namespace std;
const int N = 2e5 + 10, inf = 1e9;
set<int> st[N];
int n, q, a[N];

struct Seg {
  int mx[N << 2];
  void upd(int x, int l, int r, int L, int val) {
    if(l == r) {
      mx[x] = val;
      return ;
    }
    int mid = (l + r) >> 1;
    if(L <= mid) upd(ls, l, mid, L, val);
    else upd(rs, mid + 1, r, L, val);
    mx[x] = max(mx[ls], mx[rs]);
  }
  int get(int x, int l, int r, int L, int R) {
    if(L <= l && r <= R) {
      return mx[x];
    }
    int mid = (l + r) >> 1, ans = 0;
    if(L <= mid) ans = max(ans, get(ls, l, mid, L, R));
    if(R > mid) ans = max(ans, get(rs, mid + 1, r, L, R));
    return ans;
  }
} MX;

struct data {
  int mn, l, r, sum;
};

data operator + (data A, data B) {
  if(A.mn < B.mn) return A;
  if(B.mn < A.mn) return B;
  data res;
  res.mn = A.mn;
  res.l = A.l, res.r = B.r;
  res.sum = A.sum + B.sum + MX.get(1, 1, n, A.r + 1, B.l - 1);
  return res;
}

struct Segtree {
  int tag[N << 2];
  data ans[N << 2];
  
  void build(int x, int l, int r) {
    if(l == r) {
      ans[x] = (data){0, l, l, 0};
      return ;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid), build(rs, mid + 1, r);
    ans[x] = ans[ls] + ans[rs];
  }
  
  void down(int x) {
    if(tag[x]) {
      ans[ls].mn -= tag[x];
      ans[rs].mn -= tag[x];
      tag[ls] += tag[x];
      tag[rs] += tag[x];
      tag[x] = 0;
    }
  }
  
  void upd(int x, int l, int r, int L, int val) {
    if(l == r) {
      MX.upd(1, 1, n, L, val);
      ans[x].sum = val;
      return ;
    }
    down(x);
    int mid = (l + r) >> 1;
    if(L <= mid) upd(ls, l, mid, L, val);
    else upd(rs, mid + 1, r, L, val);
    ans[x] = ans[ls] + ans[rs];
    printf("%d %d %d %d %d\n", x, l, r, L, val);
    printf("ans, min = %d l = %d r = %d sum = %d\n", ans[x].mn, ans[x].l, ans[x].r, ans[x].sum);
  }
  
  void upd(int x, int l, int r, int L, int R, int val) {
    printf("%d %d %d %d %d val = %d\n", x, l, r, L, R, val);
    if(L > R) return ;
    if(L <= l && r <= R) {
      printf("bbb%d\n", ans[x].mn);
      ans[x].mn += val;
      printf("aaa%d\n", ans[x].mn);
      tag[x] += val;
      return ;
    }
    down(x);
    int mid = (l + r) >> 1;
    if(L <= mid) upd(ls, l, mid, L, R, val);
    if(R > mid) upd(rs, mid + 1, r, L, R, val);
    ans[x] = ans[ls] + ans[rs];
    printf("ans, min = %d l = %d r = %d sum = %d\n", ans[x].mn, ans[x].l, ans[x].r, ans[x].sum);
  }
} tr;

void remove(int id) {
  tr.upd(1, 1, n, *st[a[id]].rbegin(), 0);
  tr.upd(1, 1, n, *st[a[id]].begin(), *st[a[id]].rbegin() - 1, -1);
}

void put(int id) {
  tr.upd(1, 1, n, *st[a[id]].rbegin(), st[a[id]].size());
  tr.upd(1, 1, n, *st[a[id]].begin(), *st[a[id]].rbegin() - 1, 1);
}

void insert(int id) {
  if(st[a[id]].size()) remove(id);
  st[a[id]].insert(id);
  put(id);
}

void erase(int id) {
  remove(id);  
  st[a[id]].erase(id);
  if(st[a[id]].size()) put(id);
}

int main() {
  scanf("%d%d", &n, &q);
  for(int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    st[a[i]].insert(i);
  }
  tr.build(1, 1, n);
  for(int i = 1; i <= 2e5; ++i) {
    if(st[i].size()) {
      printf("%d %d %d\n", *st[i].begin(), *st[i].rbegin(), st[i].size());
      tr.upd(1, 1, n, *st[i].rbegin(), st[i].size());
      tr.upd(1, 1, n, *st[i].begin(), *st[i].rbegin() - 1, 1);
    }
  }
  printf("qwq%d %d\n", tr.ans[1].sum, n - tr.ans[1].sum);
  for(int i = 1, x, y; i <= q; ++i) {
    scanf("%d%d", &x, &y);
    erase(x);
    a[x] = y;
    insert(x);
    printf("%d\n", n - tr.ans[1].sum);
  }
  return 0;
}
