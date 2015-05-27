class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.empty()){
            return "";
        }
        
        string prefix = strs[0];
        
        for(int i=1; i<strs.size(); i++){
            if(strs[i].size() ==0 || prefix.size()==0){
                return "";
            }
            
            int minLen= min(prefix.size(),strs[i].size());
            int j;
            for(j=0; j<minLen; j++){
                if(prefix[j]!=strs[i][j]){
                    break;
                }
            }
            prefix=prefix.substr(0,j);
        }
        
        return prefix;
        
    }
};