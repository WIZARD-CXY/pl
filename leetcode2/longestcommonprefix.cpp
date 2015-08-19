class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string res;
        
        if(n==0){
            return res;
        }
        if(n==1){
            return strs[0];
        }
        
        res=strs[0];
        
        for(int i=1; i<strs.size(); i++){
            int j;
            for(j=0;j<min(strs[i].size(),res.size()); j++){
                if(res[j]!=strs[i][j]){
                    break;
                }
            }
            res=res.substr(0,j);
        }
        
        return res;
    }
};