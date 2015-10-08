class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;
        if(numerator==0){
            return "0";
        }
        //if num and deno is not same sign
        
        if((numerator>>31)^(denominator>>31)){
            res+='-';
        }
        
        // promot to long long in case INT_MIN 
        long long n=labs(numerator);
        long long d=labs(denominator);
        
        res+=(to_string(n/d));
        
        if(n%d==0){
            return res;
        }else{
            //have fraction part
            res+='.';
        }
        
        // store r as long long incase d is very large like -1 / INT_MIN 
        long long r=n%d;
        unordered_map<int,int> mm; //record remainer's first occur pos key is remainer, and value is pos in res
        
        while(r){
            if(mm.find(r)!=mm.end()){
                //the same r recur
                res.insert(mm[r],1,'(');
                res+=')';
                return res;
            }else{
                mm[r]=res.size();
                r*=10;
                res+=to_string(r/d);
                r=r%d;
            }
        }
        
        return res;
    }
};