class Solution {
public:
    int step[5000]={0};
    
    int climbStairs(int n) {
        
        if(n==0 || n==1){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(step[n]){
            return step[n];
        }
        else{
            return step[n]=(climbStairs(n-1)+climbStairs(n-2));
        }
        
    }
};