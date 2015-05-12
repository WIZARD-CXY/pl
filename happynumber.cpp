class Solution {
public:
    bool isHappy(int n) {
        
        if(n==1){
            return true;
        }
        unordered_set<int> old;
        
        
        while(true){
            
            int sum=0;
            
            while(n){
                sum+=(n%10)*(n%10);
                n/=10;
            }
            
            if(sum==1){
                return true;
            }
            
            if(old.find(sum)!=old.end()){
                // will begin endless loop
                return false;
            }
            old.insert(sum);
            n=sum;
        }
    }
};