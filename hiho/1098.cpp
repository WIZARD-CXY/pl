#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 100005
struct edge{
    int u,v,w;
    edge(int _u, int _v, int _w):u(_u), v(_v), w(_w){};
    bool operator<(const edge &x) const{
        return w <x.w;
    }

};

int p[MAXN];

int find(int x){
    return p[x]==x?x:p[x]=find(p[x]);
}

void merge(int x, int y){
    int px=find(x);
    int py=find(y);

    if(px!=py){
        p[min(px,py)]=max(px,py);
    }
}
int main(){
    int n,m;
    
    while(scanf("%d%d",&n,&m)!=EOF){
        vector<edge> edges;

        for(int i=1; i<=n; i++){
            p[i]=i;
        }
        
        for (int i=0; i<m; i++){
            int u,v,w;

            scanf("%d%d%d",&u,&v,&w);
            edges.push_back(edge(u,v,w));
        }

        sort(edges.begin(),edges.end());
        int ans=0;
        for(int i=0; i<m; i++){
            int px=find(edges[i].u);
            int py=find(edges[i].v);
            if(px!=py){
                merge(edges[i].u,edges[i].v);
                ans+=edges[i].w;
            }
        }
        
        printf("%d\n",ans);
    }
}