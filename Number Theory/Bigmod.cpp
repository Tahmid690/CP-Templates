#define ll long long
ll bigmod(ll a,ll b){
    if(b==0) return 1;
    ll ret=bigmod(a,b/2);
    ret*=ret;
    ret%=mod;
    if(b%2==1) ret*=a;
    return ret%mod;
    
}
ll binpow(ll a,ll b){
    if(b==0) return 1;
    ll ret=binpow(a,b/2);
    ret*=ret;
    if(b%2==1) ret*=a;
    return ret;
    
}
