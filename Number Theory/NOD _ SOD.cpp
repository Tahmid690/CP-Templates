ll NOD(ll n) {
    ll ret=1;
    for(int i=0; i<prime.size() && prime[i]*prime[i]<=n; i++) {
        if(n%prime[i]==0) {
            ll cnt=1;
            while(n%prime[i]==0) {
                cnt++;
                n/=prime[i];
            }
            ret*=cnt;
        }
    }
    if(n>1) ret*=2;
    return ret;
}

ll SOD(ll n) {
    ll ret=1;
    for(int i=0; i<prime.size() && prime[i]*prime[i]<=n; i++) {
        if(n%prime[i]==0) {
            ll tmp=1,x=prime[i];
            while(n%prime[i]==0) {
                tmp+=x;
                x*=prime[i];
                n/=prime[i];
            }
            ret*=tmp;
        }
    }
    if(n>1) ret*=(1+n);
    return ret;
}