#include <cstdio>
#include <algorithm>

int main(){
    int n;

    while(scanf("%d",&n)!=EOF){
        int dist[n+1];
        int G[n+1][n+1];
        int intree[n+1];

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                int w;
                scanf("%d",&w);
                G[i][j]=w;
            }
        }

        for(int i=1; i<=n; i++){
            intree[i]=0;
            dist[i]=G[1][i];
        }

        intree[1]=1;
        int ans=0;
        
        for(int i=1; i<=n; i++){
            //select the shortest non-intree node
            int minDist=0x7fffffff;
            int minIdx=0;
            for(int j=1; j<=n; j++){
                if(!intree[j] && dist[j] < minDist){
                    minDist=dist[j];
                    minIdx=j;
                }
            }
            
            if(minDist==0x7fffffff){
                break;
            }

            ans+=dist[minIdx];
            intree[minIdx]=1;

            for(int j=1; j<=n; j++){
                if (!intree[j] && dist[j]>G[minIdx][j]){
                    dist[j]=G[minIdx][j];
                }
            }
        }

        printf("%d\n",ans);
    }
}