    #include<bits/stdc++.h>
    #define ll long long
    #define mp make_pair
    using namespace std;
    const int mxn=1e6+6;
    ll ans[mxn];
    int q[mxn],t[mxn],l[mxn],n,w;
    int main(){
    	cin>>n>>w;
    	for(int ii=1;ii<=n;++ii){
    		cin>>l[ii];
    		for(int i=1;i<=l[ii];++i)cin>>t[i];t[l[ii]+1]=0;
    		int ta=0,x1;
    		for(int i=1;i<=l[ii]+1;++i){
    			for(;ta>=1 and t[q[ta-1]]>=t[q[ta]] and t[i]>=t[q[ta]] and q[ta-1]+w-l[ii]>=i-1;--ta);
    			q[++ta]=i;
    		}
    		x1=q[1];
    		if(t[q[1]]<0)x1=w-l[ii]+1;
    		for(int i=1;i<=ta;++i){
    			ans[x1]+=t[q[i]];
    			if(i<ta){
    				if(t[q[i]]<t[q[i+1]])x1=q[i+1];
    				else x1=q[i]+w-l[ii]+1;
    				ans[x1]-=t[q[i]];
    			}
    		}
    	}
    	for(int i=1;i<=w;++i)cout<<(ans[i]+=ans[i-1])<<endl;
    	cout<<endl;
    }
