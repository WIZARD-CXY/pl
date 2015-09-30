class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        string path;
        helper(res,num,path,target,0,0);
        
        return res;
    }
    // curres and prenum maybe very large use long long to store
    void helper(vector<string> &res, string num, string path, int target, long long curres, long long prenum){
        if(curres==target && num.size()==0){
            //num is used and curres==target
            //reach a dest
            res.push_back(path);
            return;
        }
        
        for(int i=1; i<=num.size(); i++){
            string curnum=num.substr(0,i);
            string leftnum=num.substr(i);
            
            if(curnum.size()>1 && curnum[0]=='0'){
                return; //early return for 000 like
            }
            if(path.empty()){
                //first number do not add a operator
                helper(res,leftnum,curnum,target,stoll(curnum),stoll(curnum));
            }else{
                //+
                helper(res,leftnum,path+"+"+curnum,target,curres+stoll(curnum),stoll(curnum));
                //-
                helper(res,leftnum,path+"-"+curnum,target,curres-stoll(curnum),-stoll(curnum));
                
                // * is special treatment need to minus prenum and add prenum*
                helper(res,leftnum,path+"*"+curnum,target,curres-prenum+prenum*stoll(curnum),stoll(curnum)*prenum);
            }
            
        }
    }
};