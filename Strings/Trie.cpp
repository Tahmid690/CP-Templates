#include<bits/stdc++.h>
using namespace std;
#define MAX_NODE 5000010
#define MAX_LEN 15

string S;
int node[MAX_NODE][26];
int root,nnode;
int isWord[MAX_NODE];

void initialize(){
    root=0;
    nnode=0;
    memset(node,-1,sizeof node);
    for(int i=0;i<26;i++) node[root][i]=-1;
}

void insert(){
    cin >> S;
    int now=root;
    for(int i=0;i<S.size();i++){
        if(node[now][S[i]-'a']==-1){
            node[now][S[i]-'a']=++nnode;
            for(int j=0;j<26;j++) node[nnode][j]=-1;
        }
        now=node[now][S[i]-'a'];
    }
    isWord[now]=1;
}
bool check(string k){
    int now=root;
    for(int i=0;i<k.size();i++){
        if(node[now][k[i]-'a']==-1) return 0;
        now=node[now][k[i]-'a'];
    } 
    if(isWord[now]==0) return 0;
    return 1;
}