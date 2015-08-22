class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        
        string path="";
        gen(res,path,n,n);
        
        return res;
    }
    // lremain means the number of (parenthesis, rremain means the number of )
    void gen(vector<string> &res, string path,int lremain, int rremain){
        if(lremain==0 && rremain==0){
            res.push_back(path);
            return;
        }
        
        if(lremain>0){
            gen(res,path+'(',lremain-1,rremain);
        }
        
        if(rremain>0 && lremain < rremain){
            gen(res,path+')',lremain,rremain-1);
        }
    }
};