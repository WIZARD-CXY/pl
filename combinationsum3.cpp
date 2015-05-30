class Solution {
public:
    vector<vector<int> > res;
    void dfs(int start,int sum,vector<int> &temp, int k, int n){
        if(k==0){
            if(sum==n){
                res.push_back(temp);
            }
            return;
        }
        
        for(int j=start; j<10; j++){
            if(sum+j>n){
                break;
            }
            temp.push_back(j);
            dfs(j+1,sum+j,temp,k-1,n);
            temp.pop_back();
            
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        int sum=0;
        dfs(1,sum,temp,k,n);
        return res;
    }
};