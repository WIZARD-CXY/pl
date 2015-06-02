#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
const int mod = 142857;

int M,N,K;
vector<int> indegree;
vector<int> virus;
vector<vector<int> > G;

void solve(){
    int res=0;
    
    queue<int> qq;
    // find the first node whose indegree is 0
    
    for(int i=1; i<=N; i++){
        if(indegree[i]==0){
            qq.push(i);
        }
    }
    
    while(!qq.empty()){
        int u = qq.front();
        qq.pop();
        
        for(int i=0; i<G[u].size(); i++){
            int v=G[u][i];
            
            virus[v]+=virus[u];
            virus[v]%=mod;
            
            indegree[v]--;
            
            if(indegree[v]==0){
                qq.push(v);
            }
        }
    }
    
    for(int i=1; i<=N; i++){
        res+=virus[i];
        res%=mod;
    }
    
    cout<<res<<endl;
}
int main(){
    scanf("%d%d%d",&N,&M,&K);
    
    G.assign(N+1,vector<int>());
    indegree.assign(N+1,0);
    virus.assign(N+1,0);
    
    
    for(int i=0; i<K; i++){
        int n;
        scanf("%d",&n);
        virus[n]=1;
    }
    
    for(int i=0; i<M; i++){
        int u,v;
        scanf("%d%d",&u,&v);
        
        indegree[v]++;
        G[u].push_back(v);
    }
    
    solve();
    
}