#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXLEN=10005;// extra 0 here because the limitation is not same as the problem describes
const int MAXN=105;
int G[MAXN][MAXN];

int main(){
    int n,m;

    while(scanf("%d%d",&n,&m)!=EOF){

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; ++j) 
               if(i!=j){
                   G[i][j] = MAXLEN;
               } else{
                   G[i][j]=0;
               }
        } 

        for(int i=1; i<=m; i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            G[u][v]=G[v][u]=min(G[u][v],w);
        }


        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    if(i!=j && j!=k){
                        G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
                    }              
                }
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<n; j++){
                    printf("%d ", G[i][j]);
            }
            printf("%d\n",G[i][n]);
        }
    }
 
}