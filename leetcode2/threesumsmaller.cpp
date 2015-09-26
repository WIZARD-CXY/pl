class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.size()<3){
            return 0;
        }
        
       sort(nums.begin(),nums.end());
       int res=0;
       
       for(int i=0; i<nums.size()-2; i++){
           int l=i+1;
           int r=nums.size()-1;
           
           while(l<r){
               int sum=nums[i]+nums[l]+nums[r];
               
               if(sum<target){
                   res+=(r-l);
                   //move l forward try to find more
                   l++;
               }else{
                   r--;
               }
           }
       }
       
       return res;
    }
};