#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    int N,M,S,T;

    while(scanf("%d%d%d%d",&N,&M,&S,&T)!=EOF){
        int dist[N+1];
        int G[N+1][N+1];
        int intree[N+1];
        
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
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

        for(int i=1; i<=N; i++){
            dist[i]=G[S][i];
        }

        intree[S]=1;
        dist[S]=0;
        
        for(int i=1; i<=N; i++){
            //select the shortest non-intree node
            int minDist=0x7fffffff;
            int minIdx=0;
            for(int j=1; j<=N; j++){
                if(!intree[j] && dist[j] < minDist){
                    minDist=dist[j];
                    minIdx=j;
                }
            }
        
            if (minDist == 0x7fffffff){
                break;
            }
            

            intree[minIdx]=1;

            // relax the other node dist
            for(int j=1; j<=N; j++){
                if (!intree[j] && G[minIdx][j]!=0x7fffffff && dist[j] >= (dist[minIdx]+G[minIdx][j])){
                    dist[j]=dist[minIdx]+G[minIdx][j];
                }
            }
        }

        printf("%d\n",dist[T]);
    }
}