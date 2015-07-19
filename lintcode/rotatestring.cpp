class Solution {
public:
  /**
     * param A: A string
     * param offset: Rotate string with offset.
     * return: Rotated string.
     */
    string rotateString(string A, int offset) {
        // wirte your code here
        int len=A.size();
        if(len==0){
            return "";
        }
        
        offset%=len;
        
        string res=A;
        reverse(res.begin(),res.end());
        reverse(res.begin(),res.begin()+offset);
        reverse(res.begin()+offset,res.end());
        
        return res;
    }
};
