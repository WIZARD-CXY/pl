class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> vis;
        while(n!=1){
            int next=helper(n);
            if(vis.find(next)==vis.end()){
                vis.insert(next);
            }else{
                return false;
            }
            
            n=next;
        }
        
        return true;
    }
    
    int helper(int n){
        int res=0;
        
        while(n){
            res+=(n%10)*(n%10);
            n/=10;
        }
        
        return res;
    }
};