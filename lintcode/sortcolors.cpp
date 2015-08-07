class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */    
    void sortColors(vector<int> &nums) {
        // write your code here
        int current=0,head=0;
        int end=nums.size()-1;
        
        while(current<=end){
            if(nums[current]==0){
                swap(nums[current],nums[head]);
                head++;
                current++;
            }else if(nums[current]==1){
                current++;
            }else{
                swap(nums[end],nums[current]);
                end--;
            }
        }
    }
};
