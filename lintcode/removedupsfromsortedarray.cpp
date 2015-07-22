class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        int n=nums.size();
        
        if(n==0){
            return 0;
        }
        int count=1;
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i]!=nums[count-1]){
                nums[count++]=nums[i];
            }
        }
        
        return count;
    }
};
