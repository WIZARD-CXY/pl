class Solution {
public:
    /**
     * @param nums a list of integer
     * @return void
     */  
     
    //ref http://www.cnblogs.com/grandyang/p/5177285.html
    void wiggleSort(vector<int>& nums) {
        // Write your code here
        // O(n) solution
        
        // 
        for(int i=1; i<nums.size(); i+=1){
            if(((i&1)==1 && nums[i]<nums[i-1]) || ((i&1)==0 && nums[i]>nums[i-1])){
                swap(nums[i-1],nums[i]);
            }
        }
    }
};