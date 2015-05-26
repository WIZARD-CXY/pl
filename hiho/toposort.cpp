#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 100001
vector<int> G[MAXN];

int c[MAXN+1];

bool dfs(int u){
    c[u]=-1;
    
    for(int i=0; i<G[u].size(); i++){
        int v=G[u][i];
        if(c[v]<0){
            return false;// exist acyclic 
        }else if(!c[v] && !dfs(v)){
            return false;
        }
    }
    c[u]=1;
    return true;
}

bool toposort(int n){
    memset(c,0,sizeof(c));
    
    for(int u=1; u<=n; u++)
    {
        if(!c[u]){
            if(!dfs(u)){
                return false;
            }
        } 
    }
    return true;
}

int main(){
    int T;
    scanf("%d",&T);
    
    for(int i=0; i<T; i++){
        
        int n,m;
        scanf("%d%d",&n,&m);
        for(int j=0; j<m; j++){
            int a,b;
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
        }
        
        if(toposort(n)){
            printf("Correct\n");
        }else{
            printf("Wrong\n");
        }
        for(int i=1; i<=n; i++){
            G[i].clear();
        }
    }
}