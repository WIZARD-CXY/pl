#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    int N,M,S,T;
    int dist[N];
    int G[N][N];
    int intree[N];

    while(scanf("%d%d%d%d",&N,&M,&S,&T)!=EOF){
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                G[i][j]=0x7fffffff;
            }
            intree[i]=0;
        }

        for(int i=0; i<M; i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            // use the minimum value 
            G[u][v]=G[v][u]=min(G[u][v],w);
        }

        for(int i=0; i<N; i++){
            dist[i]=G[S][i];
        }

        intree[S]=1;
        dist[S]=0;
        
        for(int i=0; i<N; i++){
            //select the shortest non-intree node
            int minDist=0x7fffffff;
            int minIdx=0;
            for(int j=0; j<N; j++){
                if(!intree[j] && dist[j] < minDist){
                    minDist=dist[j];
                    minIdx=j;
                }
            }

            

            intree[minIdx]=1;

            // relax the other node dist
            for(int j=0; j<N; j++){
                if (!intree[j] && G[minIdx][j]!=0x7fffffff && dist[j] >= (dist[minIdx]+G[minIdx][j])){
                    dist[j]=dist[minIdx]+G[minIdx][j];
                }
            }
        }

        printf("%d\n",dist[T]);
    }
}