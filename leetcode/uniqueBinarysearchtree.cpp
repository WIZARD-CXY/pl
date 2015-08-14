class Solution {
public:
    int numTrees(int n) {
        vector<int> res(n+1,0);
        
        res[0]=1; //empty tree
        res[1]=1; //only root tree
        
        for(int i=2; i<=n; i++){
            for(int j=0; j<i; j++){
                res[i]+=res[j]*res[i-1-j];
            }
        }
        return res[n];
    }
};