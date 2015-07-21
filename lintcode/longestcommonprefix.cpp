class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        string res;
        int len=strs.size();
        if(len==0){
            return res;
        }
        //set the first string as res
        res=strs[0];
        
        for(int i=1; i<strs.size(); i++){
            // get the longest prefix with strs[i]
            int j=0;
            for(; j<min(res.size(),strs[i].size()); j++){
                if(res[j]!=strs[i][j]){
                    break;
                }
            }
            res=res.substr(0,j);
        }
        return res;
    }
};
