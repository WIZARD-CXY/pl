class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        
        unordered_map<char,int> cnt;
        
        for(auto &c :s){
            cnt[c]++;
        }
        int oddcnt=0;
        char mid;
        //half the string if odd don't have the mid char
        string half;
        
        for(auto &kv : cnt){
            if(kv.second & 1){
                //odd count
                oddcnt++;
                if(oddcnt>1){
                    // more than 1 odd cnt exist, not a valid palindrome 
                    return res;
                }
                mid=kv.first;
            }
            half+=string(kv.second/2,kv.first);
        }
       
        res=getPerm(half);
       
        for(auto &p : res){
            string tmp=p;
            reverse(tmp.begin(),tmp.end());
            
            if(oddcnt){
                p+=mid;
            }
            p+=tmp;
        }
        
        return res;
    }
    
    vector<string> getPerm(string &s){
        string t=s;
        vector<string> res;
        
        do{
            res.push_back(s);
            next_permutation(s.begin(),s.end());
        }while(s!=t);
        
        return res;
    }
};