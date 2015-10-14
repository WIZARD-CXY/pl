class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char,string> m1;
        unordered_map<string,char> m2;
        
        return helper(pattern,0,str,0,m1,m2);
    }
    
    bool helper(string &pat, int i, string &str, int j, unordered_map<char,string> &m1, unordered_map<string,char> &m2){
        if(i==pat.size() && j==str.size()){
            return true;
        }
        
        if(i==pat.size() || j==str.size()){
            return false;
        }
        
        
        char c = pat[i];
        
        if(m1.find(c)!=m1.end()){
            //pattern c is already exist
            string s=m1[c];
            
            if(s!=str.substr(j,s.size())){
                return false;
            }
            
            // match c, yeah , go forward
            return helper(pat,i+1,str,j+s.size(),m1,m2);
            
        }else{
            // pattern c is not exist
            // try to match it with str[i...end] use backtracking
            for(int k=j; k<str.size(); k++){
                string s = str.substr(j,k-j+1);
                
                if(m2.find(s)!=m2.end()){
                    if(m2[s]!=c){
                        continue;
                    }
                }
                
                //use it as a match 
                m1[c]=s;
                m2[s]=c;
                if(helper(pat,i+1,str,k+1,m1,m2)){
                    return true;
                }
                
                //backtracking
                m1.erase(c);
                m2.erase(s);
            }
        }
       
        return false;
    }
};