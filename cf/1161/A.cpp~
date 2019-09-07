#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
int a[N], st[N], nm[N], ed[N];
 
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= k; ++i) {
		scanf("%d", &a[i]);
		if(!st[a[i]]) st[a[i]] = i;
		ed[a[i]] = i;
		nm[a[i]]++;
	} 
	ll ans = 0;
	for(int i = 1; i <= n; ++i) {
//		if(st[i] == 1) continue;
		if(nm[i]) {
//			printf("qwq%d\n", i);
			int pos = st[i];
			if(i + 1 <= n && ed[i + 1] <= pos) ans++;
			if(i > 1 && ed[i - 1] <= pos) ans++;
		} else {
			ans++;
			if(i + 1 <= n) ans++;
			if(i > 1) ans++;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
