class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
       vector<string> res;
       unordered_map<char,char> mm;
       
       mm['0']='0';
       mm['1']='1';
       mm['6']='9';
       mm['8']='8';
       mm['9']='6';
       
       string path;
       if(n&1){
           // n is odd
           path='0';helper(res,path,n-1,mm);
           path='1';helper(res,path,n-1,mm);
           path='8';helper(res,path,n-1,mm);
       }else{
           // n is even
           helper(res,path,n,mm);
       }
       
       return res;
    }
    
    void helper(vector<string> &res, string path,int n,unordered_map<char,char> &mm){
        if(n==0){
            //reach the end
            if(path.size()>1 && path[0]=='0'){
                return;
            }
            res.push_back(path);
            return;
        }
        
        for(auto kv : mm){
            helper(res,kv.first+path+kv.second,n-2,mm);
        }
    }
};