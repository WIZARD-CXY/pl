class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //record the last exist index of s
        int last[256];
        memset(last,-1,sizeof(last));
        
        int start=0,end=0;
        int res=0;
        
        while(end<s.size()){
            if(last[s[end]]>=start){
                // alreay exist in start to end range
                // need a new start
                start=last[s[end]]+1;
            }else{
                // not exist in start to end range
                int len=end-start+1;
                res=max(res,len);
            }
            last[s[end]]=end;
            end++;
        }
        
        return res;
    }
};