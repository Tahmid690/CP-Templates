// "Say:He is the Most Merciful,We have believed in him and upon him we have relied" [67:29]

//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
//#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
using namespace std;
                                                     

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<ll> vll;
typedef vector<int> vii;
typedef map<int,int> mpi;
typedef map<ll,ll> mpl;
typedef unordered_map<int,int> umpi;
typedef unordered_map<ll,ll> umpl;
 
#define ump unordered_map
#define mod 1000000007
#define inf 1000000000000000006
#define ff first
#define ss second
#define pb push_back
#define all(v) v.begin(), v.end()
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define pi acos(-1.0)
#define dec(n) fixed << setprecision(n)
#define N 200006
#define int long long
int n,a,b;
char c;
struct node{
	int sum,prop;
	node *l,*r;
	node(): sum(0),prop(0),l(NULL),r(NULL) { }
};
struct segtree{
	
	void propagate(node *v,int l,int r){
		v->l->prop=v->prop;
		v->r->prop=v->prop;
		int xx=v->prop;
		v->prop=0;
		int mid=(l+r)/2;
		
		v->l->sum=(mid-l+1)*xx;
		v->r->sum=(r-(mid+1)+1)*xx;
	}
	void update(node *v,int l,int r,int a,int b,int u){
		if(b<l || a>r) return;
		if(l>=a && r<=b){
			v -> sum = (r-l+1)*u;
			v -> prop =u;
			return;
		}
		if(v->l==NULL) v->l=new node();
		if(v->r==NULL) v->r=new node();
		if(v->prop!=0) propagate(v,l,r);
		update(v->l,l,(l+r)/2,a,b,u);
		update(v->r,(l+r)/2 +1,r,a,b,u);
		v -> sum= v->l->sum + v->r->sum;
	}
	int query(node *v,int l,int r,int a,int b){
		if(r<a || l>b) return 0;
		if(l>=a && r<=b){
			return v -> sum;
		} 
		if(v->prop!=0) propagate(v,l,r);
		return query(v->l,l,(l+r)/2,a,b)+query(v->r,(l+r)/2 +1,r,a,b);
	}
}sg;

void solve(){
	node *root =new node();
	cin >> n;
	while(n--){
		cin >> c;
		if(c=='+'){
			cin >> a >> b;
			sg.update(root,1,1000000005,a,b,1);
		}
		else{
			cout << sg.query(root,1,1000000000,1,1000000005) << endl;
		}
	}
}
signed main(){
    fastio;
    //srand(chrono::steady_clock::now().time_since_epoch().count());
    int T=1,cs=0;
    //cin >> T;
    while(T--){
        //cout << "Case " << ++cs << ": " ; 
    	solve();
    } 
}