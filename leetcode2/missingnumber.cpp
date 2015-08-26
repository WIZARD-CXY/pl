class Solution {
public:
    int missingNumber(vector<int>& nums) {
       long long sum=0;
       long long n=nums.size();
       
       for(auto n :nums){
           sum+=n;
       }
       
       return n*(n+1)/2-sum;
        
    }
};