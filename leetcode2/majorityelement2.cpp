class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> res;
        
        if(n==0){
           return res; 
        }
        
        int can1=nums[0];
        int cnt1=1;
        int can2=0;
        int cnt2=0;
        
        if(n==1){
            return {can1};
        }
        
        for(int i=1; i<n; i++){
            if(nums[i]==can1){
                cnt1++;
            }else if(nums[i]==can2){
                cnt2++;
            }else{
                if(cnt1==0){
                    can1=nums[i];
                    cnt1=1;
                }else if(cnt2==0){
                    can2=nums[i];
                    cnt2=1;
                }else{
                    cnt1--;
                    cnt2--;
                }
            }
        }
        
        //validate 
        cnt1=0,cnt2=0;
        
        for(int i=0; i<n; i++){
            if(nums[i]==can1){
                cnt1++;
            }else if(nums[i]==can2){
                cnt2++;
            }
        }
        
        if(cnt1>n/3){
            res.push_back(can1);
        }
        if(cnt2>n/3){
            res.push_back(can2);
        }
        
        return res;
    }
};