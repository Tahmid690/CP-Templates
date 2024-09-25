//Dice Combinations
#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n;
int dp[1000006];
int DP(int num){
    if(num<0) return 0;
    if(num==0) return 1;
    if(dp[num]!=-1) return dp[num];
    int ret=0;
    for(int i=1;i<=6;i++) ret=(ret+DP(num-i))%mod;
    return dp[num]=ret%mod;
}
void solve(){
    memset(dp,-1,sizeof dp);
    cin >> n;
    cout << DP(n) << endl;
}
int main(){
    int t=1;
    //cin >> t;
    while(t--) solve();
    
}


//Minimizing Coins
#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,x,coins[105];
int dp[1000006];
int DP(int sum){
    if(sum==x) return 0;
    if(sum>x) return 1000000009;
    if(dp[sum]!=-1) return dp[sum];
    int ret=1000000009,k=0;
    for(int i=0;i<n;i++) ret=min(ret,1+DP(sum+coins[i]));
    return dp[sum]=ret;
}
void solve(){
    memset(dp,-1,sizeof dp);
    cin >> n >> x;
    for(int i=0;i<n;i++) cin >> coins[i];
    sort(coins,coins+n,greater<int>());
    int ans=DP(0);
    if(ans>=1000000009) ans=-1;
    cout << ans << endl;
}
int main(){
    int t=1;
    //cin >> t;
    while(t--) solve();
    
}


//Coin Combinations I
#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,x,ara[105];
int dp[1000006];
int DP(int num){
    if(num<0) return 0;
    if(num==0) return 1;
    if(dp[num]!=-1) return dp[num];
    int ret=0;
    for(int i=0;i<n;i++) ret=(ret+DP(num-ara[i]))%mod;
    return dp[num]=ret%mod;
}
void solve(){
    memset(dp,-1,sizeof dp);
    cin >> n >> x;
    for(int i=0;i<n;i++) cin >> ara[i];
    cout << DP(x) << endl;
}
int main(){
    int t=1;
    //cin >> t;
    while(t--) solve();
    
}


//Coin Combinations II
#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,x,ara[105];
int dp[1000006];
 
int main(){
    scanf("%d %d",&n,&x);
    for(int i=0;i<n;i++) scanf("%d",&ara[i]);
    dp[0]=1;
    for(int j=0;j<n;j++){
    	for(int i=1;i<=x;i++){
    		if(i>=ara[j]) dp[i]+=dp[i-ara[j]];
    		dp[i]%=mod;
    	}
    }
    
    printf("%d\n",dp[x]);
    
}



//Removing Digits
#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,ara[105];
int dp[1000006];
 
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        int x=i;
        while(x!=0){
            if(x%10!=0){
            if(dp[i]!=0) dp[i]=min(dp[i],dp[i-(x%10)]+1);
            else dp[i]=dp[i-(x%10)]+1;
            }
            x/=10;
            
        }
    }
    cout << dp[n] << endl;
    
}



//Grid Paths
#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n;
string s[1000];
int dp[1005][1005];
 
int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> s[i];
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(i==n-1 && j==n-1){ if(s[i][j]!='*') dp[i][j]=1;}
            else{
                if(s[i][j]!='*') dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
            dp[i][j]%=mod;
        }
    }
    
    cout << dp[0][0] << endl;
    
}



//Book Shop
#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,x,price[1005],page[1005];
int dp[1005][100005];
 
int main(){
    
    cin >> n >> x;
    for(int i=0;i<n;i++) cin >> price[i];
    for(int i=0;i<n;i++) cin >> page[i];
    for(int i=n-1;i>=0;i--){
        for(int j=x;j>=0;j--){
            if(j+price[i]<=x) dp[i][j]=max(dp[i+1][j],page[i]+dp[i+1][j+price[i]]);
            else dp[i][j]=dp[i+1][j];
        }
    }
    cout << dp[0][0] << endl;
    
}


//Array Description
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,arr[100009];
ll dp[100009][105];
const ll mod=1000000007;
 
ll DP(ll pos,ll prev){
    if(prev<1 || prev>m) return 0;
    if(pos>=n) return 1;
    if(dp[pos][prev]!=-1) return dp[pos][prev];
    ll ret=0;
    if(arr[pos]!=0){
        if(pos!=0 && abs(prev-arr[pos])>1) ret=0;
        else ret=DP(pos+1,arr[pos])%mod;
    }
    else{
        ret=ret+DP(pos+1,prev-1)%mod;
        ret=ret+DP(pos+1,prev)%mod;
        ret=ret+DP(pos+1,prev+1)%mod;
    }
    return dp[pos][prev]=ret%mod;
    
}
void solve(){
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> arr[i];
    ll ans=0;
    memset(dp,-1,sizeof dp);
    if(arr[0]==0){
        for(int i=1;i<=m;i++) ans=(ans+DP(1,i))%mod;
    }
    else ans=DP(1,arr[0]);
    cout << ans%mod << endl;
}
int main(){
    int t=1;
    //cin >> t;
    while(t--) solve();
}



//Edit Distance
#include<bits/stdc++.h>
using namespace std;
string a,b;
int dp[5005][5005];
int edit_dis(int i,int j){
    if(i==0) return j;
    if(j==0) return i;
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i-1]==b[j-1]) return dp[i][j]=edit_dis(i-1,j-1);
    return dp[i][j]=1+min(edit_dis(i-1,j-1),min(edit_dis(i,j-1),edit_dis(i-1,j)));
    
}
void solve(){
    cin >> a >> b ;
    memset(dp,-1,sizeof dp);
    cout << edit_dis(a.size(),b.size());
}
int main(){
    int t=1;
    //cin >> t;
    while(t--) solve();
}


//Rectangle Cutting
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a,b,dp[505][505];
int DP(int x,int y){
    if(x==y) return 0;
    if(dp[x][y]!=-1) return dp[x][y];
    int ret=1000000009;
    for(int i=1;i<x;i++) ret=min(ret,DP(i,y)+DP(x-i,y)+1);
    for(int i=1;i<y;i++) ret=min(ret,DP(x,i)+DP(x,y-i)+1);
    return dp[x][y]=ret;
}
void solve(){
    cin >> a >> b;
    memset(dp,-1,sizeof dp);
    cout << DP(a,b) << endl;
}
int main(){
    int t=1;
    //cin >> t;
    while(t--) solve();
}


//Money Sums
#include<bits/stdc++.h>
using namespace std;
int n,ara[105];
map<int,int> mp;
bool vis[105][100005];
void dp(int pos,int sum){
    if(vis[pos][sum]==1) return;
    mp[sum]=1;
    if(pos>=n) return;
    dp(pos+1,sum+ara[pos]);
    dp(pos+1,sum);
    vis[pos][sum]=1;
}
void solve(){
    mp.clear();
    memset(vis,0,sizeof vis);
    cin >> n;
    for(int i=0;i<n;i++) cin >> ara[i];
    dp(0,0);
    cout << mp.size()-1 << endl;
    for(auto u:mp) if(u.first!=0) cout << u.first << " ";
}
int main(){
    int t=1;
    //cin >> t;
    while(t--) solve();
    
}



//Removal Game
#include<bits/stdc++.h>
using namespace std;
#define ll long
struct score{
    ll first=0,second=0;
};
ll n,ara[5005];
score dp[5005][5005][2];
int main(){
    
    cin >> n;
    for(int i=0;i<n;i++) cin >> ara[i];
    
    
    for(int l=n-1;l>=0;l--){
        for(int r=0;r<n;r++){
            for(int k=1;k>=0;k--){
                if(l>r) continue;
                score ret;
                if(k==0){
                    score a,b;
                    a=dp[l+1][r][1];
                    if(r!=0) b=dp[l][r-1][1];
                    if(a.first+ara[l]>b.first+ara[r]){
                    a.first+=ara[l];
                    ret=a;
                        }
                    else{
                    b.first+=ara[r];
                    ret=b;
                        }
                    }
                else{
                    score a,b;
                    a=dp[l+1][r][0];
                    if(r!=0) b=dp[l][r-1][0];
                    if(a.second+ara[l]>b.second+ara[r]){
                    a.second+=ara[l];
                    ret=a;
                    }
                    else{
                    b.second+=ara[r];
                    ret=b;
                    }
                }
                
                dp[l][r][k]=ret;
            }
        }
    }
    cout << dp[0][n-1][0].first << endl;
}


//Two Sets II
#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int n,x,dp[505][130000];
 
int DP(int pos,int sum){
    if(sum==x) return 1;
    if(sum>x || pos>n) return 0;
    if(dp[pos][sum]!=-1) return dp[pos][sum];
    return dp[pos][sum]=((DP(pos+1,pos+sum)%mod)+(DP(pos+1,sum)%mod))%mod;
}
#define ll long long
ll bigmod(int a,int b,int m){
    if(b==0) return 1;
    ll ret=bigmod(a,b/2,m);
    ret*=ret;
    ret%=m;
    if(b%2==1) ret*=a;
    return ret%m;
    
}
void solve(){
    cin >> n;
    x=(n*(n+1))/2;
    if(x%2==1){
        cout << 0 << endl;
        return;
    }
    x/=2;
    
    memset(dp,-1,sizeof dp);
    cout << (DP(1,0)*bigmod(2,mod-2,mod))%mod << endl;
}
int main(){
    int t=1;
    //cin >> t;
    while(t--) solve();
}


//Increasing Subsequence
#include<bits/stdc++.h>
using namespace std;
int LIS(int arr[],int n){
    vector<int> V;
    for(int i=0;i<n;i++){
        auto it=lower_bound(V.begin(),V.end(),arr[i]);
        if(V.end()==it) V.push_back(arr[i]);
        else V[it-V.begin()]=arr[i];
    }
    return V.size();
}
int main(){
    int n,ara[200005];
    cin >> n;
    for(int i=0;i<n;i++) cin >> ara[i];
    cout << LIS(ara,n) << endl;
}


//Projects
#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct job{
    ll strt=0,fin=0,income=0;
};
bool cmp(job a,job b){
    return a.fin<b.fin;
}
ll n,dp[200005];
job ara[200005];
int binserch(int i){
    int lo=0,hi=i,mid=-1;
    while((lo+hi)/2!=mid){
        mid=(lo+hi)/2;
        if(ara[mid].fin<ara[i].strt) lo=mid;
        else hi=mid;
    }
    return mid;
}
int main(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> ara[i].strt >> ara[i].fin >> ara[i].income;
    sort(ara+1,ara+n+1,cmp);
    memset(dp,0,sizeof dp);
    
    for(int i=1;i<=n;i++) dp[i]=ara[i].income;
    for(int i=1;i<=n;i++){
        int j=binserch(i);
        
        dp[i]=max(dp[i],ara[i].income+dp[j]);
        dp[i]=max(dp[i],dp[i-1]);
    }
    cout << dp[n] << endl;
}
 

//Elevator Rides

#include<bits/stdc++.h>
using namespace std;
int n,x,w[25];
pair<int,int> dp[(1<<20)+5];
int main(){
    cin >> n >> x;
    for(int i=0;i<n;i++) cin >> w[i];
    dp[0]={1,0};
    for(int i=1;i<(1<<n);i++){
        
        for(int j=0;j<n;j++){
            
            if(i & (1<<j)){
                pair<int,int> xixi;
                xixi=dp[i ^ (1<<j)];
                
                if(xixi.second+w[j]<=x){
                    xixi.second+=w[j];
                }
                else{
                    xixi.first++;
                    xixi.second=w[j];
                }
                if(dp[i].first!=0 || dp[i].second!=0) dp[i]=min(dp[i],xixi);
                else dp[i]=xixi;
            }
        }
        
    }
    cout << dp[(1<<n)-1].first << endl;
}


//Counting Numbers

#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll dp[20][2][11][2];
ll DP(int pos,int issmall,int last,int isstrt){
    if(pos==20) return 1;
    if(dp[pos][issmall][last][isstrt]!=-1) return dp[pos][issmall][last][isstrt];
    int hi=s[pos]-'0',lo=0;
    if(issmall) hi=9;
    int x;
    x=isstrt;
    ll ret=0;
    for(int i=hi;i>=lo;i--){
        if(i==last && isstrt) continue;
        int y;
        y=x;
        if(i!=0) y=1;
        if(i<hi || issmall) ret+=DP(pos+1,1,i,y);
        else ret+=DP(pos+1,0,i,y);
    }
  
    return dp[pos][issmall][last][isstrt]=ret;
}
int main(){
    
    ll x,y,a,b;
    cin >> a >> b;
    a--;
    
    s.clear();
    for(int i=0;i<20;i++){
        s.push_back(b%10+'0');
        b/=10;
    }
    reverse(s.begin(),s.end());
    
    memset(dp,-1,sizeof dp);
    x=DP(1,0,0,0);
    
    s.clear();
    for(int i=0;i<20;i++){
        s.push_back(a%10+'0');
        a/=10;
    }
    reverse(s.begin(),s.end());
    memset(dp,-1,sizeof dp);
    y=DP(1,0,10,0);
    
    cout << x-y << endl;
}
//Counting Towers
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,dp[1000005][2];

void solve(){
    cin >> n;
    memset(dp,0,sizeof dp);
    dp[n+1][0]=dp[n+1][1]=1;
    
    for(int i=n;i>=2;i--){
        for(int j=1;j>=0;j--){
            if(j==0){
                dp[i][j]=(dp[i+1][0]+dp[i+1][1]+dp[i+1][0]+2*dp[i+1][0])%mod;
            }
            else{
                dp[i][j]=(dp[i+1][0]+dp[i+1][1]+dp[i+1][1])%mod;
            }
        }
    }
    cout << (dp[2][0]+dp[2][1])%mod << endl;
    
}
signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}