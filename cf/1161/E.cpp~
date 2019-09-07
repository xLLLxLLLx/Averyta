#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct data {
	int x, y;
} a[N], c[N];
int b[N], d[N];
vector<int> g[4];
typedef pair<int, int> P;
map<P, int> mp;

void ask(int n) {
	printf("Q %d ", n);
	for(int i = 1; i <= n; ++i) {
		printf("%d %d ", a[i].x, a[i].y);
	}
	puts("");
	fflush(stdout);
	for(int i = 1, x; i <= n; ++i) {
		scanf("%1d", &x);
		mp[P(a[i].x, a[i].y)] = x;
	}
}

int main() {
	int T, res, top;
	scanf("%d", &T);
	for(int o = 1; o <= T; ++o) {
	  for(int i = 1; i <= 3; ++i) g[i].clear();
		int n;
		scanf("%d", &n);
		memset(d, 0, sizeof d);
		res = 0;
		for(int i = 1; i + 1 <= n; i += 2) {
			a[++res].x = i, a[res].y = i + 1;
		}
		if(res) ask(res);
		res = 0;
		for(int i = 2; i + 1 <= n; i += 2) {
		  a[++res].x = i, a[res].y = i + 1;
		}
		if(res) ask(res);
		res = 0, top = 0;
		for(int i = 1; i <= n; ++i)
		  if(!mp[P(i - 1,i)]) b[++top] = i;
		for(int i = 1; i <= top; i += 4) {
		  if(i + 2 <= top) a[++res].x = b[i], a[res].y = b[i + 2];
		  if(i + 3 <= top) a[++res].x = b[i + 1], a[res].y = b[i + 3];
		} 
		if(res) ask(res);
		res = 0;
		for(int i = 3; i <= top; i += 4) {
		  if(i + 2 <= top) a[++res].x = b[i], a[res].y = b[i + 2];
		  if(i + 3 <= top) a[++res].x = b[i + 1], a[res].y = b[i + 3];
		}
		if(res) ask(res);
		d[b[1]] = 1;
		if(top > 1) d[b[2]] = 2;
		for(int i = 3; i <= top; ++i) {
		  if(mp[P(b[i - 2], b[i])]) d[b[i]] = d[b[i - 2]];
		  else d[b[i]] = 6 - d[b[i - 2]] - d[b[i - 1]];
		}
		int now;
		for(int i = 1; i <= n; ++i) {
		  if(d[i]) now = d[i];
		  d[i] = now;
		  g[d[i]].push_back(i);
		}
		printf("A %d %d %d\n", g[1].size(), g[2].size(), g[3].size());
		for(int i = 1; i <= 3; ++i) {
		  for(int j = 0; j < (int)g[i].size(); ++j) {
		    printf("%d ", g[i][j]);
		  }
		  puts("");
		}
		fflush(stdout);
	}
	return 0;
}
