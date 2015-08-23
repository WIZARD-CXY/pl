#include <stdlib.h>
#include <cstdio>
#include <memory.h>
#include <queue>
#include <iostream>
#include <climits>
using namespace std;
int n,m;       
#define Edge 22000
#define Node 110

int edge[Node][Node];
int dist[Node][Node];

void Floyd()
{
    int i,j,k;
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(dist[i][j]>(dist[i][k]+dist[k][j])){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
}

struct Bian{
    int a,b,c;
};
int main(int argc, char* argv[]){
    // first parameter is testfile name
    freopen(argv[1],"r",stdin);

    int T;
    scanf("%d",&T);
    for (int cas=1; cas<=T; cas++) {
        scanf("%d%d",&n,&m);
       
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                dist[i][j] = INT_MAX;
            }
        }
        printf("Case #%d:\n",cas);
        for(int i=0;i<=n;i++)dist[i][i] = 0;
        int a,b,c;

        vector<Bian> edges;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            
            Bian tmp  = Bian();
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            edges.push_back(tmp);
            dist[a][b] = dist[b][a] = min(dist[a][b],c);
        }
        Floyd();
        vector<int>ans;
        ans.clear();
        for (int i=0; i<edges.size(); i++) {
            if(edges[i].c>dist[edges[i].a][edges[i].b]){
                ans.push_back(i);
            }
        }
        
        for(int i=0;i<ans.size();i++){
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}

