#include <iostream>
using namespace std;
#include <cstring>
#include <climits>

#define MAXN 10005
int w[MAXN][MAXN];
int dist[MAXN];
bool vis[MAXN];

void dijk(int n, int src){
    for(int i=1; i<=n; i++){
        dist[i]=w[src][i];
    }
      
    dist[src]=0;
    vis[src]=1;

    for(int j=1; j<=n; j++){
       // 选出最小dist的未访问的node
       int minDst=0x7fffffff;
       int minIdx=-1;
       for(int i=1; i<=n; i++){
            if(!vis[i] && dist[i]<minDst){
                  minDst=dist[i];
                  minIdx=i;
            }
       }

       if(minIdx==-1){
       	  break;
       }

       vis[minIdx]=1;

       //relaxation
       for(int i=1; i<=n; i++){
            if(!vis[i] && w[minIdx][i]<0x7fffffff && dist[i]>=(dist[minIdx]+w[minIdx][i])){
                dist[i]=dist[minIdx]+w[minIdx][i];
            }
        }
    }
}


int main(){
	int n,m;
	cin>>n>>m;

	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i!=j){
				w[i][j]=INT_MAX;
			}
			
		}
		dist[i]=INT_MAX;
	}
	for(int i=0; i<n-1; i++){
		int u,v,k;
		cin>>u>>v>>k;
		w[u][v]=w[v][u]=k;
	}

	for(int i=0; i<m; i++){
		string line;
		cin>>line;

		if(line[0]=='Q'){
			//query
			int sum=0;
			for(int i=1; i<n;i++){

				memset(vis,0,sizeof(vis));
				for(int j=1; j<=n; j++){
					dist[j]=INT_MAX;
				}
				dijk(n,i);

				for(int j=i+1;j<=n; j++){
					sum+=dist[j];
					
				}

			}
			cout<<sum<<endl;
		}else{
			//Edit
			int u,v,k;
			cin>>u>>v>>k;
			w[u][v]=w[v][u]=k;
		}
	}
}