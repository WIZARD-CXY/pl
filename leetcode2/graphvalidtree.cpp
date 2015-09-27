struct unionset{
    int cnt;
    vector<int> p;
    
    unionset(int n){
        cnt=n;
        for(int i=0; i<n; i++){
            p.push_back(i);
        }
    }
    
    bool merge(int x,int y){
        int px=find(x);
        int py=find(y);
        if(px!=py){
           p[min(px,py)]=max(px,py);
           cnt--;
           return true;
        }else{
            //exist cycle
            return false;
        }
    }
    
    int find(int x){
        return x==p[x]?x:p[x]=find(p[x]);
    }
};

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        unionset uset=unionset(n);
        
        for(auto e : edges){
            if(!uset.merge(e.first,e.second)){
                return false;
            }
        }
        
        //only one connected componet
        return uset.cnt==1;
    }
};