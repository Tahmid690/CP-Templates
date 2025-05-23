#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R> using o_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define int long long
#define endl "\n"
#define ff first
#define ss second
 
#define INF 1000
 
const int mod=1000000007;
const int N=1000005;
 
 
int n,v[N];
vector<int> g[N];
int sz[N];
int st[N],ft[N],tym,koi[N];
 
void dfs(int u,int p){
    sz[u]=1;
    st[u]=tym;
    koi[tym++]=u;
    for(int v:g[u]){
        if(v==p) continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
    ft[u]=tym;
}
 
int cnt[N],tot,ans[N];
 
void add(int x){
    cnt[v[x]]++;
    if(cnt[v[x]]==1) tot++;
}
void rmv(int x){
    cnt[v[x]]--;
    if(cnt[v[x]]==0) tot--;
}
 
void dsu(int u,int p,int keep){
    int mxsz=-1,bigchild=-1;
    for(auto v:g[u]){
        if(v==p) continue;
        if(mxsz<sz[v]){
            mxsz=sz[v];
            bigchild=v;
        }
    }
    for(auto v:g[u]){
        if(v==bigchild || v==p) continue;
        dsu(v,u,0);
    }
    if(bigchild!=-1) dsu(bigchild,u,1);
    for(auto v:g[u]){
        if(v==bigchild || v==p) continue;
        for(int i=st[v];i<ft[v];i++){
            add(koi[i]);
        }
    }
    add(u);
 
    ans[u]=tot;
    
    if(!keep){
        for(int i=st[u];i<ft[u];i++) rmv(koi[i]);
    }
 
}
 
map<int,int> mp;
int col=1;
 
void solve(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> v[i];  
        if(!mp[v[i]]) mp[v[i]]=col++;
        v[i]=mp[v[i]];
    } 
    for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    dsu(1,0,1);
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
}
 
 
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin >> t;
    
    while(t--){
        solve();
    }
}
