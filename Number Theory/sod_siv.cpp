void sod_siv(){
	sod[1]=1;
	ans[1]=1;
	for(int i=2;i<mx;i++){
	if(!sod[i]){
	sod[i]=1+i;
		for(int j=i+i;j<mx;j+=i){
			if(!sod[j]) sod[j]=1;
			int x=j,m=1,a=0;
			while(!(x%i)){
				a+=m;
				m*=i;
				x/=i;
			}
			a+=m;
			sod[j]*=a;
		}
	}
	if(sod[i]<mx && ans[sod[i]]==-1) ans[sod[i]]=i;
	}
	
}