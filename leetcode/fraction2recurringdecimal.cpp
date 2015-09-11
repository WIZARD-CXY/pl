class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0){
            return "0";
        }
        
        long long n=numerator,d=denominator;
        
        string res;
        if(n <0 ^ d <0) res+='-';
        
        n=abs(n);
        d=abs(d);
        
        res+=to_string(n/d);
        
        long long r = n%d; 
        
        if(r==0){
            return res;
        }else{
            res+='.';//has fraction part
        }
        unordered_map<int,int> mm;
        
        while(r){
            if(mm.find(r)!=mm.end()){
                //r has been stored in the map
                // will start recuring
                res.insert(mm[r],1,'(');
                res+=')';
                break;
            }
            
            mm[r]=res.size();
            r=r*10;
            res+=to_string(r/d);
            r=r%d;   
        }
        
        return res;
        
    }
};