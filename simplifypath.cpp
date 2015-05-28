class Solution {
public:
    string simplifyPath(string path) {
        stack<string> ss;
        
        for(int i=0; i<path.size();){
            while(i<path.size() && path[i]=='/'){
                i++;
            }
            
            // break from trailing '/'
            if(i==path.size()) break;
            
            string s=""; // record the content between two consecutive '/'
            
            while(i<path.size() && path[i]!='/'){
                s=s+path[i];
                i++;
            }
            
            if(s==".." && !ss.empty()){
                ss.pop();
            }else if ( s!="." && s !=".."){
                ss.push(s);
            }
        }
        
        //just root path
        if(ss.empty()){
            return "/";
        }
        
        string res;
        while(!ss.empty()){
            res="/"+ss.top()+res;
            ss.pop();
            
        }
        
        return res;
        
    }
};