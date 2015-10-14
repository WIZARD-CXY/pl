class Solution {
public:
    void reverseWords(string &s) {
        int len=s.size();
        
        reverse(s,0,len-1);
        
        int p=0;
        int q=0;
        
        while(p<len && q<len){
            while(q<len && s[q]!=' '){
                q++;
            }
            
            reverse(s,p,q-1);
            
            p=++q;
        }
    }
    
    void reverse(string &s, int start, int end){
        while(start<end){
            swap(s[start++],s[end--]);
        }
    }
};