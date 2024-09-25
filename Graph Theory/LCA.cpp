
struct anc{
	int par[N][25],lvl[N];
	void construct(int n){
		lvl[0]=-1;
		memset(par,-1,sizeof par);
		dfs(1,0);
		par[1][0]=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;(1<<j)<n;j++){
				if(par[i][j-1]!=-1) par[i][j]=par[par[i][j-1]][j-1];
			}
		}
	}
	void dfs(int x,int p){
		lvl[x]=lvl[p]+1;
		par[x][0]=p;
		for(auto u:g[x]){
			if(u==p) continue;
			dfs(u,x);
		}
	}

	int kthanc(int x,int k){
		for(int i=0;i<25;i++){
			if(k & (1<<i)){
				x=par[x][i];
			}
			if(x==-1) break;
		}
		return x;
	}

	int lca(int a,int b){
		if(lvl[a]<lvl[b]) swap(a,b);
		for(int i=24;i>=0;i--){
			if(lvl[a]-(1<<i)>=lvl[b]) a=par[a][i];
		}
		for(int i=24;i>=0;i--){
			if(par[a][i]!=-1 && par[a][i]!=par[b][i]){
				a=par[a][i];
				b=par[b][i];
			}

		}
		if(a==b) return a;
		return par[a][0];
	}
	
}p;