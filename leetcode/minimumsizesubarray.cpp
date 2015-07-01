class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
       int n=nums.size();
       //slightly larger
       int res=n+1;
       
       int l=0,r=0;
       int sum=0;
       
       while(r<n){
           sum+=nums[r];
           
           while(l<n && sum >=s){
               int len=r-l+1;
               
               if(len<res){
                   res=len;
               }
               sum-=nums[l];
               l++;
           }
           r++;
       }
       
       if(res>n){
           return 0;
       }
       return res;
    }
};