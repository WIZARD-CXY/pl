class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[256];//保存字符上一次出现的位置
        memset(last, -1, sizeof(last));

        int start = 0, max = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (last[s[i]] < start)
            {
                //if the last pos of  char s[i] is before start, we can safely add it to the new substr
                if(i-start+1>max){
                    max=i-start+1;
                }
            } else{
                // else it means s[i] is already exists in substr
                start=last[s[i]]+1;
            }
            last[s[i]] = i;
        }
        return max;
    }
};