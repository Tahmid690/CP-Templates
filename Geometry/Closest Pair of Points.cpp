#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define int long long
// #define ll long long
#define pb push_back
#define endl "\n"
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
 
const long long mod  = 1000000007;
const int N = 500005;
 
int n;
vector<pair<int,int>> poi;
 
int dis(int i,int j){
	return (poi[i].ff-poi[j].ff)*(poi[i].ff-poi[j].ff)+(poi[i].ss-poi[j].ss)*(poi[i].ss-poi[j].ss);
}
 
int win(int l,int r){
	if(r-l+1<4){
		int mn=dis(l,l+1);
		for(int i=l;i<=r;i++){
			for(int j=i+1;j<=r;j++){
				mn=min(mn,dis(i,j));
			}
		}
		// cout << l << " " << r << " - " << mn << endl;
		return mn;
	}
	int mid=(l+r)/2;
 
	int ret=min(win(l,mid),win(mid+1,r));
	int x=sqrt((double)ret)+2;
	vector<pair<int,int>> ptr;
	for(int i=l;i<=r;i++){
		if(abs(poi[i].ff-poi[mid].ff)<=x) ptr.push_back({poi[i].ss,i});
	}
	sort(all(ptr));
 
	for(int i=0;i<ptr.size();i++){
		for(int j=i+1;j<ptr.size() && ptr[j].ff-ptr[i].ff<x;j++){
			ret=min(ret,dis(ptr[i].ss,ptr[j].ss));
		}
	}
 
	// cout << l << " " << r << " -> " << ret << endl;
 
	return ret;
 
}
 
 
void solve(){
    cin >> n;
    poi.resize(n);
    for(int i=0;i<n;i++) cin >> poi[i].ff >> poi[i].ss;
    sort(all(poi));
	
	cout << win(0,n-1) << endl;
 
    
    
}
    
 
 
 
 
signed main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // fflush(stdout);
    int t=1;
    // cin >> t;
    while(t--){
        solve();
    }
 
 
 
 
}
