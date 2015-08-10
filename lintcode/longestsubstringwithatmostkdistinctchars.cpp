class Solution {
public:
    /**
     * @param s : A string
     * @return : The length of the longest substring 
     *           that contains at most k distinct characters.
     */
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        // write your code here
        //dict[i] records ith occur count
        unordered_map<char,int> dict;
        int start=0;
        int res=0;
        
        for(int i=0; i<s.size(); i++){
            dict[s[i]]++;
            
            if(dict.size()<=k){
                res=max(res,i-start+1);
            }else if(dict.size()>k){
                //need to remove the s[start]
                dict[s[start]]--;
                if(dict[s[start]]==0){
                    dict.erase(s[start]);
                }
                start++;
            }
        }
        return res;
    }
};
