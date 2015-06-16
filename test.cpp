#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<limits.h>
#include<stack>
#include<queue>
using namespace std;

vector<vector<int> > res;

void dfs(vector<int> &candidates, vector<int> &path, int start, int target){
        if(target==0){
            res.push_back(path);
            return;
        }
        
        int previous=-1;
        
        for(int i=start ; i<candidates.size(); i++){
            if(target < candidates[i]){
                return; //prune
            }
            
            if(candidates[i]==previous){
                continue;
            }
            path.push_back(candidates[i]);
            previous=candidates[i];
            dfs(candidates,path,i+1,target-candidates[i]);
            path.pop_back();
        }
    }
    
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        
        vector<int> path;
        dfs(candidates,path,0,target);
        
        return res;
    }
    
    
    
int main(){

    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(4);

   combinationSum2(vec,7);

   for(int i=0; i<res.size();i++){
    for(int j=0; j<res[i].size(); j++){
        cout<<res[i][j]<<" ";

    
   }
   cout<<endl;
}
}