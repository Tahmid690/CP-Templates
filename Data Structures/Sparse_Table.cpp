#define N 200005
int sparse[N][25],logtable[N];
void build_sparse(int ara[],int n){
    logtable[1]=0;
    for(int i=2;i<N;i++) logtable[i]=logtable[i/2]+1;
    
    for(int i=0;i<n;i++) sparse[i][0]=ara[i];
    for(int j=1;j<=25;j++){
        for(int i=0;i+(1<<j)<=n;i++){
            sparse[i][j]=sparse[i][j-1]+sparse[i+(1<<(j-1))][j-1];
        }
    }
}
int query_sum(int l,int r){
    long long sum=0;
    for(int j=25;j>=0;j--){
        if((1<<j)<=(r-l+1)){
            sum+=sparse[l][j];
            l+=(1<<j);
        }
    }
    return sum;
}

int min_query(int l,int r){
    int j=logtable[r-l+1];
    int mini=min(sparse[l][j],sparse[r-(1<<j)+1][j]);
    return mini;
}
