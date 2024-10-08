#define mx 100005
vector<int>prime;
bool vis[mx];
void sieve(){
    for(int i=3; i*i<=mx; i+=2) {
        if(vis[i]==0) {
            for(int j=i*i; j<mx; j+=2*i)
                vis[j]=1;
        }
    }
    prime.pb(2);
    for(int i=3; i<mx; i+=2) if(vis[i]==0) prime.pb(i);
}