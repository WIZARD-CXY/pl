class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(),1);
        
        //res[i] records the res[0]*res[1]*...*res[i-1];
        for(int i=1; i<nums.size(); i++){
            res[i]=res[i-1]*nums[i-1];
        }
        //revese product continue to product right side
        int right=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            res[i]*=right;
            right*=nums[i];
        }
        
        return res;
    }
};