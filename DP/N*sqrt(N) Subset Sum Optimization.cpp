#include<bits/stdc++.h>
using namespace std;

#define N 200005
#define int long long
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second

int n,g[N],r[N];
int cnt[N];
vector<pair<int,int>> nums;
void solve(){
	cin >> n;
	int rk=0,tot=0,f=0;
	for(int i=1;i<=n;i++){
		cin >> g[i] >> r[i];
		rk=__gcd(rk,r[i]);
		cnt[g[i]]++;
		tot+=g[i];
		if(g[i]==0) f=1;
	}
	for(int i=1;i<N;i++){
		if(cnt[i]) nums.pb({i,cnt[i]});
	}
	vector<int> dp(N);
	dp[0]=1;
	for(auto u:nums){
		vector<int> newdp(N);
		newdp=dp;
		for(int i=0;i<u.ff;i++){
			int sum=0,cc=0;
			for(int j=i;j<N;j+=u.ff){
				if(cc>u.ss){
					sum-=dp[j-u.ff*cc];
					cc--;
				}
				if(sum>0) newdp[j] = 1;
				sum+=dp[j];
				cc++;
			}
		}
		swap(dp,newdp);
	}
}





signed main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1,cs=0;
	// cin >> t;
	while(t--){
		// cout << "Case " << ++cs << ": ";
		solve();
	}
	
}
