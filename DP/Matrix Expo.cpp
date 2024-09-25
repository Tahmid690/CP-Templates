struct mat{
	ll a[2][2]={{0,0},{0,0}};
	mat operator *(const mat& p){
		mat pro;
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				for(int k=0;k<2;k++){
					pro.a[i][k]=(pro.a[i][k]+a[i][j]*p.a[j][k])%mod;
				}
			}
		}
		return pro;
	}
};
mat exp(mat a,ll k){
	mat pro;
	for(int i=0;i<2;i++) pro.a[i][i]=1;
	while(k>0){
		if(k%2) pro=pro*a;
		a=a*a;
		k/=2;
	}
	return pro;
}
ll n;
void solve(){
	cin >> n;
	mat base;
	base.a[0][0]=0;
	base.a[0][1]=1;
	base.a[1][0]=1;
	base.a[1][1]=1;
	mat ans=exp(base,n-1);
	if(n==0) cout << 0 << endl;
	else cout << ans.a[1][1] << endl;
}