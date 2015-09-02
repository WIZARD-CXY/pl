class Solution {
public:
        bool isValid(string s){
            if(s.size()==1 && s>="0" && s<="9") return true;
            if(s.size()==2 && s>="10" && s<="99") return true;
            if(s.size()==3 && s>="100" && s<="255") return true;
              
            return false;
        }
        vector<string> res;

        vector<string> restoreIpAddresses(string s) {
            vector<string> ipSegs;
            
            dfs(s, ipSegs, 0);
            
            return res;
        }
        
        // search in step-th step with start index 'start'
        void dfs(string &s, vector<string> &ipSegs, int start){
            int step=ipSegs.size();
            
            if(start==s.size() && step ==4){
                string temp=ipSegs[0];
                
                for(int i=1; i<4; i++){
                    temp=temp+"."+ipSegs[i];
                }
                
                res.push_back(temp);
                return;
            }
            
            if(s.size()-start > (4-step)*3){
                return; //return early because there is too many extra bits
            }
            
            if(s.size()-start <(4-step)){
                return; //return early because there is not enough bits
            }
            
            for(int i=1; i<=3 && start+i-1<s.size(); i++){
                string temp=s.substr(start,i);
                if(isValid(temp)){
                    ipSegs.push_back(temp);
                    //search forward
                    dfs(s, ipSegs,start+i);
                    ipSegs.pop_back();
                }
            }
        }
};