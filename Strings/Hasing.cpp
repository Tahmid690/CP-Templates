ll Hash[N],pp[N];

void pre(){
	ll p=31;
	pp[0]=1;
	for(int i=1;i<N;i++){
		pp[i]=(pp[i-1]*p)%mod;
	}
}

ll calchash(string s){
    ll p=31,hashval = 0,pw=1;
    for(int i=0;i<s.size();i++){
        hashval=(hashval+(s[i]-'a'+1)*pw)%mod;
        pw=(pw*p)%mod;
        Hash[i+1]=hashval;
    }
    return hashval;
}

ll subhash(ll i,ll j){
	//don't forget to multiply p^i with main string
	return (((Hash[j]-Hash[i-1]))+mod)%mod;
}
