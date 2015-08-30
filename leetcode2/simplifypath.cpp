class Solution {
public:
    string simplifyPath(string path) {
        stack<string> ss;
        
        for(int i=0; i<path.size(); i++){
            if(path[i]=='/'){
                continue;
            }
            
            string tmp;
            while(i<path.size() && path[i]!='/'){
                tmp+=path[i++];
            }
            
            // push the dir name into stack
            if(tmp==".." && !ss.empty()){
                ss.pop();
            }else if(tmp!="." && tmp!=".."){
                ss.push(tmp);
            }
            
        }
        
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