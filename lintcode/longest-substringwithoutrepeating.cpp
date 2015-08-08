class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer 
     */
    int lengthOfLongestSubstring(string s) {
        // write your code here
        int last[256];
        memset(last,-1,sizeof(last));
        int res=0;
        
        int start=0;
        for(int i=0; i<s.size(); i++){
            if(start<=last[s[i]]){
                //current word last occur time is after start
                // dup ,restart
                start=last[s[i]]+1;
            }else{
                int len=i-start+1;
                res=max(res,len);
            }
            last[s[i]]=i;
        }
        
        return res;
    }
};
