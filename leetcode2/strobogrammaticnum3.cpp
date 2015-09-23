class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int count=0;
        string num;
        unordered_map<char,char> mm;
        
        mm['0']='0';
        mm['1']='1';
        mm['6']='9';
        mm['8']='8';
        mm['9']='6';
        
        num="";helper(count,num,low,high,mm);
        num="0";helper(count,num,low,high,mm);
        num="1";helper(count,num,low,high,mm);
        num="8";helper(count,num,low,high,mm);
        
        return count;
    }
    
    void helper(int &count, string num,string &low, string &high, unordered_map<char,char> &mm){
        if(cmp(num,low)){
            if(cmp(high,num)){
                //if num is one digit number or many digit but first digit is not '0'
                if(num.size()>1 && num[0]!='0' || num.size()==1){
                   count++;
                }
            }else{
                // num is > high return
                return;
            }
        }
        
        for(auto kv : mm){
            helper(count,kv.first+num+kv.second,low,high,mm);
        }
        
    }
    // if s1 represented number >= s2 then return true
    // else return false
    bool cmp(string &s1, string &s2){
        if(s1.size()>s2.size()){
            return true;
        }else if(s1.size()==s2.size()){
            return s1>=s2;
        }else{
            return false;
        }
    }
};