class Solution {
public:
    /**
     * @param path the original path
     * @return the simplified path
     */
    string simplifyPath(string& path) {
        // Write your code here
        //stack ss only store name 
        stack<string> ss;
        
        for(int i=0; i<path.size(); i++){
            // skip "/"
            while(i<path.size() && path[i]=='/'){
                i++;
                continue;
            }
            
            if(i==path.size()){
                break;
            }
            
            string tmp="";
            
            while(i<path.size() && path[i]!='/'){
                tmp+=path[i++];
            }
            
            if(tmp==".." && !ss.empty()){
                ss.pop();// move upper directory pop the latest pushin
            }else if (tmp!="." && tmp!=".."){
                ss.push(tmp);
            }
        }
        
        if(ss.empty()){
            return "/";
        }
        
        string res="";
        while(!ss.empty()){
            res="/"+ss.top()+res;
            ss.pop();
        }
        
        return res;
    }
};
