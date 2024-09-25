int phi[N];
void allphi(int n){
    phi[0]=0;
    phi[1]=1;
    for (int i=2;i<=n;i++) phi[i]=i;
    for (int i=2;i<=n;i++){
        if (phi[i]==i){
            for (int j=i;j<=n;j+=i) phi[j]-=phi[j]/i;
        }
    }
}

int phi[N];
void allphi(int n){
    phi[0] = 0;
    phi[1] = 1;
    for (int i=2;i<=n;i++) phi[i]=i-1;
    for (int i=2;i<=n;i++)
        for(int j=2*i;j<=n;j+=i) phi[j]-=phi[i];
}