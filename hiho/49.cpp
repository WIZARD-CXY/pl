#include<iostream>
#include<vector>
using namespace std;

vector<int> degree;
vector<int> p;
int n,m;
    
int findP(int x){
    return x==p[x]?x:p[x]=findP(p[x]);
}

bool solve(){
    int count=0;// record the union set num
    
    for(int i=1; i<=n; i++){
        if(p[i]==i){
            count++;
        }
    }
    if(count!=1){
        return false;// the graph is not connected
    }
    
    count=0;// record the num of vertex whose degree is odd
    for(int i=1; i<=n; i++){
        if(degree[i] &1){
            count++;
        }
        if(count>2){
            return false;
        }
    }
    return true;
}
int main(){
    cin>>n>>m;
    
    degree.assign(n+1,0);
    p.assign(n+1,0);
    
    for(int i=1; i<=n; i++){
        p[i]=i;
    }
    
    int u,v;
    
    for(int i=0; i<m; i++){
        cin>>u>>v;
        
        degree[u]++;
        degree[v]++;
        
        int pu=findP(u);
        int pv=findP(v);
        
        if(pv!=pu){
            p[pv]=pu;
        }
    }
    
    if(solve()){
        cout<<"Full"<<endl;
    }else{
        cout<<"Part"<<endl;
    }
}