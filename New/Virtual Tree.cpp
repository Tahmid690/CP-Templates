#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define ff first
#define ss second
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long LL;
 
const int mod = 1000000007;
const int N = 2e5+5;
const int LOGN = 20;


int n,q;
vector<int> g[N];

int tin[N], tout[N], depth[N];
int up[N][LOGN];
int timer;

void dfs_lca(int u, int p, int d) {
    depth[u] = d;
    tin[u] = ++timer;
    up[u][0] = p;
    for (int i = 1; i < LOGN; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    for (int v : g[u]) {
        if (v != p) dfs_lca(v, u, d + 1);
    }
    tout[u] = timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int get_lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = LOGN - 1; i >= 0; i--) {
        if (!is_ancestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

vector<pair<int, int>> adj_vt[N]; 
bool is_key[N];

void add_vt_edge(int u, int v) {
    int w = depth[v] - depth[u]; 
    adj_vt[u].push_back({v, w});
    adj_vt[v].push_back({u, w});
}

void build_virtual_tree(vector<int>& nodes) {
    auto cmp = [&](int a, int b) { return tin[a] < tin[b]; };
    sort(nodes.begin(), nodes.end(), cmp);
    vector<int> st;
    st.push_back(1);
    for (int u : nodes) {
        if (u == 1) continue;
        int lca = get_lca(u, st.back());
        if (lca != st.back()) {
            while (st.size() > 1 && depth[st[st.size() - 2]] >= depth[lca]) {
                add_vt_edge(st[st.size() - 2], st.back());
                st.pop_back();
            }
            if (st.back() != lca) {
                add_vt_edge(lca, st.back());
                st.pop_back();
                st.push_back(lca);
            }
        }
        st.push_back(u);
    }
    while (st.size() > 1) {
        add_vt_edge(st[st.size() - 2], st.back());
        st.pop_back();
    }
}

LL ans=0;
LL dp(int u,int p){

    LL sum=is_key[u];
    for(auto [v,w]:adj_vt[u]){
        if(v==p) continue;
        if(is_key[u] && is_key[v] && w==1) ans-=1e17;
        sum+=dp(v,u);
    }
    if(sum>=2){
        if(is_key[u]){
            ans+=(sum-1);
            return 1;
        }
        else{
            ans++;
            return 0;
        }
    }
    return sum;
}


void solve(){
    cin >> n;
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    timer = 0;
    dfs_lca(1, 1, 0);


    cin >> q;
    while(q--){
        int k;
        cin >> k;
        vector<int> Q;
        Q.resize(k);
        for(int i=0;i<k;i++){
            cin >> Q[i];
            is_key[Q[i]]=true;
        }

        build_virtual_tree(Q);

        ans=0;
        int x=dp(1,-1);


        if(ans<0) cout << -1 << endl;
        else cout << ans << endl;
        function<void(int, int)> cleanup = [&](int u, int p) {
            is_key[u] = false;
            for (auto& edge : adj_vt[u]) {
                int v = edge.first;
                if (v != p) cleanup(v, u);
            }
            adj_vt[u].clear();
        };
        cleanup(1, -1);



    }

}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
