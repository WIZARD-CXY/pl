class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        string num;
        vector<string> res;
        unordered_map<char,char> mm;
        
        mm['0']='0';
        mm['1']='1';
        mm['6']='9';
        mm['8']='8';
        mm['9']='6';
        
        if(n&1){
            //n is odd, set the central element
            num='1';helper(res,num,n-1,mm);
            num='0';helper(res,num,n-1,mm);
            num='8';helper(res,num,n-1,mm);
        }else{
            helper(res,num,n,mm);
        }
    
        return res;
    }
    
    void helper(vector<string> &res, string num, int n, unordered_map<char,char> &mm){
        if(n==0){
            if(num.size()>1 && num[0]=='0'){
                return;
            }
            res.push_back(num);
            return;
        }
        
        for(auto kv : mm){
            helper(res,kv.first+num+kv.second,n-2,mm);
        }
    }
};