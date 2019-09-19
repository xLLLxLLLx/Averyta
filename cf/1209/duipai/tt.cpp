#include<bits/stdc++.h>
#define GX(x,y) x=max(x,y)
#define REP(i,s,t) for(int i=s;i<=t;i++)
using namespace std;
int n,m,a[105][4],f[105][16];
int main(){
	int T; cin>>T;
	while(T--){
		cin>>n>>m;
		REP(j,0,n-1) REP(i,1,m) cin>>a[i][j];
		memset(f,~0x3f,sizeof f);
		f[0][0]=0;
		REP(i,1,m) REP(j,0,(1<<n)-1) REP(k,0,n-1) REP(s,0,(1<<n)-1) if((s&j)==0){
			int tmp=0;
			REP(l,0,n-1) if(s&1<<l) tmp+=a[i][(l+k)%n];
			GX(f[i][j|s],f[i-1][j]+tmp);
		}
		cout<<f[m][(1<<n)-1]<<'\n';
	}
	return 0;
}
