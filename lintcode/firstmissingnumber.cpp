class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        
        // insert a dummy element
        nums.push_back(-1);
        int n=nums.size();
        
        for(int i=0; i<n; i++){
            while(nums[i]!=i){
                //swap the element
                if(nums[i]<0){
                    break;
                }
                swap(nums[i],nums[nums[i]]);
                
            }
        }
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=i){
                return i;
            }
        }
    }
};
