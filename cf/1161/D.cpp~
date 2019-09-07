#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2010, mod = 998244353;
struct data {
	int nt, to, w;
} a[N * N];
char lx[N];
int head[N], cnt = 0;

ll mul(ll x, ll y) {
	return x * y % mod;
}

ll add(ll x, ll y) {
	return (x + y) % mod;
}

ll q_pow(ll x, int y) {
	ll ans = 1;
	for(; y; y >>= 1) {
		if(y & 1) ans = mul(ans, x);
		x = mul(x, x);
	}
	return ans;
}

void adde(int x, int y, int w) {
//	printf("%d %d %d\n", x, y, w);
	a[++cnt].to = y;
	a[cnt].w = w;
	a[cnt].nt = head[x];
	head[x] = cnt;
} 

void add(int x, int y, int w) {
	adde(x, y, w), adde(y, x, w);
}

int col[N];

bool check(int x) {
  int flg = 1;
	if(col[x] == -1) col[x] = 0;
//  printf("col[%d]=%d\n", x, col[x]);
	for(int i = head[x]; i; i = a[i].nt) {
		int to = a[i].to;
		if(col[to] == -1) {
			col[to] = col[x] ^ a[i].w;
			flg &= check(to);
		} else {
			if(col[to] ^ col[x] != a[i].w) {
//			  printf("%d %d %d\n", to, x, a[i].w);
			  return false;
			}
		}
	}
	return flg;
}

ll work(int n, int m) {
	memset(head, 0, sizeof head);
	cnt = 0;
	for(int i = 1; i <= n; ++i) {
		if(i >= n - i + 1) break;
		add(i, n - i + 1, 0);
	}
	for(int i = 1; i <= m; ++i) {
		int l = i, r = m - i + 1;
		if(l >= r) break;
		add(n * 2 - m + l, n * 2 - m + r, 0);
	}
	for(int i = 1; i <= n; ++i) {
		if(lx[i] == '0') add(i, n + i, 0);
		if(lx[i] == '1') add(i, n + i, 1);
	}
	for(int i = 1; i <= n - m; ++i) {
		add(i + n, n * 2 + 1, 0);
	}
	add(1, n * 2 + 2, 0);
	add(n * 2 - m + 1, n * 2 + 2, 0);
	add(n * 2 + 2, n * 2 + 1, 1);
	int res = 0;
	memset(col, -1, sizeof col);
	for(int i = 1; i <= 2 * n + 2; ++i) {
		if(col[i] == -1) {
//		  printf("qwq%d\n", i);
			if(check(i)) res++;
			else return 0ll;
		}
	}
//	printf("res = %d\n", res);
	return q_pow(2, res - 1);
}

int main() {
	scanf("%s", lx + 1);
	int n = strlen(lx + 1);
	ll ans = 0;
	for(int i = 1; i < n; ++i) {
//		printf("aaaaaaaaa%d\n", i);
		ans = add(ans, work(n, i));
	}
	printf("%lld\n", ans);
	return 0;
}
