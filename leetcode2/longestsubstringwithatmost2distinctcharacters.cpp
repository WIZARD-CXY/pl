class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char,int> cnt;
        
        int start=0;
        int res=0;
        for(int i=0; i<s.size(); i++){
            cnt[s[i]]++;
            
            while(cnt.size()>2){
                //remove start from substrin
                if((--cnt[s[start]])==0){
                    cnt.erase(s[start]);
                }
                start++;
            }
            
            res=max(res,i-start+1);
        }
        
        return res;
    }
};