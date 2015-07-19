class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        // write your code here
        int len=s.size();
        if(len==0){
            return "";
        }
        
        int start=0;
        
        //delete leading space
        while(start<len && s[start]==' '){
            start++;
        }
        
        if(start==len){
            return "";
        }
        
        int end=len-1;
        //delete trailing space
        while(end>=0 && s[end]==' '){
            end--;
        }
        
        s=s.substr(start,end-start+1);
        
        // reverse s
        reverse(s.begin(),s.end());
        
        int p=0,q=0;
        string res="";
        string temp;
        while(p<s.size() && q<=s.size()){
           if(s[q]==' ' || q==s.size()){
                string temp=s.substr(p,q-p);
                reverse(temp.begin(),temp.end());
                res+=(temp+" ");
                while(q<s.size() && s[q]==' '){
                    q++;
                }
                // move to the next start
                p=q;
            }else{
                q++;
            }
        }
       
        return res.substr(0,res.size()-1);
        
    }
};
