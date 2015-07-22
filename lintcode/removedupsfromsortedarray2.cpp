class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        int n=nums.size();
        
        if(n<2){
            return n;
        }
        int count=2;
        for(int i=2; i<nums.size(); i++){
            if(nums[i]!=nums[count-2]){
                nums[count++]=nums[i];
            }
        }
        return count;
    }
};
