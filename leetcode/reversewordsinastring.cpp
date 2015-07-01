class Solution {
public:
    void reverseWords(string &s) {
        vector<string> res;
        
        int len=s.size();
        
        int i=0;
        //trim the leading " "
        while(s[i]==' ' && i<len) i++;
        //trim the trailing " "
        while(s[len-1]==' ' && len>0) len--;
        
        while(i<len){
            int start =i;
            
            if(s[i]!= ' '){
                while(s[i]!=' ' && i<len) i++;
                
                res.push_back(s.substr(start,i-start));
            }else{
                while(s[i]==' ' && i<len) i++;
                res.push_back(" ");
            }
        }
        reverse(res.begin(),res.end());
        s="";
        for(int i=0; i<res.size(); i++){
            s+=res[i];
        }
        
        
    }
};